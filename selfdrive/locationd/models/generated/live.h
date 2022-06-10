#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_35(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_33(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_2822599319381688270);
void live_err_fun(double *nom_x, double *delta_x, double *out_7961072857689096202);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_4526548343824011490);
void live_H_mod_fun(double *state, double *out_8044105840918455214);
void live_f_fun(double *state, double dt, double *out_7878857156988566531);
void live_F_fun(double *state, double dt, double *out_7860804367873125575);
void live_h_4(double *state, double *unused, double *out_8110659987197455788);
void live_H_4(double *state, double *unused, double *out_3962229937409009016);
void live_h_9(double *state, double *unused, double *out_6611330330362697541);
void live_H_9(double *state, double *unused, double *out_7197295201036095130);
void live_h_10(double *state, double *unused, double *out_3405989874012051555);
void live_H_10(double *state, double *unused, double *out_5691276471454773343);
void live_h_12(double *state, double *unused, double *out_1745573603744563952);
void live_H_12(double *state, double *unused, double *out_2419028439633723980);
void live_h_35(double *state, double *unused, double *out_2242375180930933540);
void live_H_35(double *state, double *unused, double *out_4071822790293078399);
void live_h_32(double *state, double *unused, double *out_6989707278751510539);
void live_H_32(double *state, double *unused, double *out_5684052485070716790);
void live_h_13(double *state, double *unused, double *out_9008445801239303650);
void live_H_13(double *state, double *unused, double *out_4693524989663708846);
void live_h_14(double *state, double *unused, double *out_6611330330362697541);
void live_H_14(double *state, double *unused, double *out_7197295201036095130);
void live_h_33(double *state, double *unused, double *out_168842592932288984);
void live_H_33(double *state, double *unused, double *out_921265785654220795);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}