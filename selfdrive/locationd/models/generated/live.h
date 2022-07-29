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
void live_H(double *in_vec, double *out_779002897874222835);
void live_err_fun(double *nom_x, double *delta_x, double *out_2575057030449799647);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_4939839170744340603);
void live_H_mod_fun(double *state, double *out_7182898073611301348);
void live_f_fun(double *state, double dt, double *out_4173568346217898788);
void live_F_fun(double *state, double dt, double *out_6296105127634558501);
void live_h_4(double *state, double *unused, double *out_5948577426230530012);
void live_H_4(double *state, double *unused, double *out_4770896317044356210);
void live_h_9(double *state, double *unused, double *out_265691507195281761);
void live_H_9(double *state, double *unused, double *out_6388628821400747936);
void live_h_10(double *state, double *unused, double *out_1564786531389201107);
void live_H_10(double *state, double *unused, double *out_3553953439702851604);
void live_h_12(double *state, double *unused, double *out_4265222670993935151);
void live_H_12(double *state, double *unused, double *out_1610362059998376786);
void live_h_35(double *state, double *unused, double *out_6965666151732865991);
void live_H_35(double *state, double *unused, double *out_1135200972326636923);
void live_h_32(double *state, double *unused, double *out_2730940807872760310);
void live_H_32(double *state, double *unused, double *out_6936505344534249481);
void live_h_13(double *state, double *unused, double *out_6721831887981491262);
void live_H_13(double *state, double *unused, double *out_3979044278064943195);
void live_h_14(double *state, double *unused, double *out_265691507195281761);
void live_H_14(double *state, double *unused, double *out_6388628821400747936);
void live_h_33(double *state, double *unused, double *out_7566033101307018314);
void live_H_33(double *state, double *unused, double *out_112599406018873601);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}