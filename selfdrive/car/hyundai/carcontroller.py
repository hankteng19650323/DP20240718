from cereal import car
from common.realtime import DT_CTRL
from selfdrive.car import apply_std_steer_torque_limits
from selfdrive.car.hyundai.hyundaican import create_lkas11, create_clu11, create_lfa_mfa, create_mdps12
from selfdrive.car.hyundai.values import Buttons, SteerLimitParams, CAR, FEATURES
from selfdrive.config import Conversions as CV
from opendbc.can.packer import CANPacker
from common.dp_common import common_controller_ctrl
from common.numpy_fast import interp

VisualAlert = car.CarControl.HUDControl.VisualAlert

STEER_MAX_BP = [384, 307, 255]
V_EGO_BP = [0, 22, 28]

def process_hud_alert(enabled, fingerprint, visual_alert, left_lane,
                      right_lane, left_lane_depart, right_lane_depart):
  sys_warning = (visual_alert == VisualAlert.steerRequired)

  # initialize to no line visible
  sys_state = 1
  if left_lane and right_lane or sys_warning:  # HUD alert only display when LKAS status is active
    if enabled or sys_warning:
      sys_state = 3
    else:
      sys_state = 4
  elif left_lane:
    sys_state = 5
  elif right_lane:
    sys_state = 6

  # initialize to no warnings
  left_lane_warning = 0
  right_lane_warning = 0
  if left_lane_depart:
    left_lane_warning = 1 if fingerprint in [CAR.HYUNDAI_GENESIS, CAR.GENESIS_G90, CAR.GENESIS_G80] else 2
  if right_lane_depart:
    right_lane_warning = 1 if fingerprint in [CAR.HYUNDAI_GENESIS, CAR.GENESIS_G90, CAR.GENESIS_G80] else 2

  return sys_warning, sys_state, left_lane_warning, right_lane_warning


class CarController():
  def __init__(self, dbc_name, CP, VM):
    self.apply_steer_last = 0
    self.car_fingerprint = CP.carFingerprint
    self.packer = CANPacker(dbc_name)
    self.steer_rate_limited = False
    self.last_resume_frame = 0

    # dp
    self.last_blinker_on = False
    self.blinker_end_frame = 0.

  def update(self, enabled, CS, frame, actuators, pcm_cancel_cmd, visual_alert,
             left_lane, right_lane, left_lane_depart, right_lane_depart, dragonconf):

    # *** compute control surfaces ***

    # Steering Torque
    steer_max = interp(CS.out.vEgo, V_EGO_BP, STEER_MAX_BP)
    new_steer = actuators.steer * steer_max
    apply_steer = apply_std_steer_torque_limits(new_steer, self.apply_steer_last, CS.out.steeringTorque, SteerLimitParams, steer_max, True)
    self.steer_rate_limited = new_steer != apply_steer

    # disable if steer angle reach 90 deg, otherwise mdps fault in some models
    # temporarily disable steering when LKAS button off
    lkas_active = enabled and abs(CS.out.steeringAngle) < 90.

    # fix for Genesis hard fault at low speed
    if CS.out.vEgo < 16.7 and self.car_fingerprint == CAR.HYUNDAI_GENESIS and not CS.mdps_bus:
      lkas_active = False

    if not lkas_active:
      apply_steer = 0

    # dp
    blinker_on = CS.out.leftBlinker or CS.out.rightBlinker
    if not enabled:
      self.blinker_end_frame = 0
    if self.last_blinker_on and not blinker_on:
      self.blinker_end_frame = frame + dragonconf.dpSignalOffDelay
    apply_steer = common_controller_ctrl(lkas_active,
                                         dragonconf.dpLatCtrl,
                                         dragonconf.dpSteeringOnSignal,
                                         blinker_on or frame < self.blinker_end_frame,
                                         apply_steer)

    self.last_blinker_on = blinker_on
    self.apply_steer_last = apply_steer

    sys_warning, sys_state, left_lane_warning, right_lane_warning = \
      process_hud_alert(lkas_active, self.car_fingerprint, visual_alert, left_lane,
                        right_lane, left_lane_depart, right_lane_depart)

    clu11_speed = CS.clu11["CF_Clu_Vanz"]
    enabled_speed = 38 if CS.is_set_speed_in_mph  else 60
    if clu11_speed > enabled_speed or not lkas_active:
      enabled_speed = clu11_speed

    self.prev_scc_cnt = CS.scc11["AliveCounterACC"]

    can_sends = []
    can_sends.append(create_lkas11(self.packer, frame, self.car_fingerprint, apply_steer, lkas_active,
                                   CS.lkas11, sys_warning, sys_state, enabled, left_lane, right_lane,
                                   left_lane_warning, right_lane_warning, 0))

    if CS.mdps_bus or CS.scc_bus == 1: # send lkas11 bus 1 if mdps or scc is on bus 1
      can_sends.append(create_lkas11(self.packer, frame, self.car_fingerprint, apply_steer, lkas_active,
                                     CS.lkas11, sys_warning, sys_state, enabled, left_lane, right_lane,
                                     left_lane_warning, right_lane_warning, 1))
    if frame % 2 and CS.mdps_bus: # send clu11 to mdps if it is not on bus 0
      can_sends.append(create_clu11(self.packer, frame, CS.mdps_bus, CS.clu11, Buttons.NONE, enabled_speed))

    if pcm_cancel_cmd:
      can_sends.append(create_clu11(self.packer, frame, 0, CS.clu11, Buttons.CANCEL, clu11_speed))
    elif CS.out.cruiseState.standstill:
      # SCC won't resume anyway when the lead distace is less than 3.7m
      # send resume at a max freq of 5Hz
      if CS.lead_distance > 3.7 and (frame - self.last_resume_frame)*DT_CTRL > 0.2:
        can_sends.append(create_clu11(self.packer, frame, 0, CS.clu11, Buttons.RES_ACCEL, clu11_speed))
        self.last_resume_frame = frame

    if CS.mdps_bus: # send mdps12 to LKAS to prevent LKAS error
      can_sends.append(create_mdps12(self.packer, frame, CS.mdps12))

    # 20 Hz LFA MFA message
    if frame % 5 == 0 and self.car_fingerprint in FEATURES["send_lfa_mfa"]:
      can_sends.append(create_lfa_mfa(self.packer, frame, lkas_active))

    return can_sends
