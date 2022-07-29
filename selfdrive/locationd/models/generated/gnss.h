#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_5685586692381648546);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_961684295642468722);
void gnss_H_mod_fun(double *state, double *out_3447866398814421424);
void gnss_f_fun(double *state, double dt, double *out_1737638576013027315);
void gnss_F_fun(double *state, double dt, double *out_3900105210689889954);
void gnss_h_6(double *state, double *sat_pos, double *out_1821551638969343814);
void gnss_H_6(double *state, double *sat_pos, double *out_3240344798520983452);
void gnss_h_20(double *state, double *sat_pos, double *out_2555555902212981732);
void gnss_H_20(double *state, double *sat_pos, double *out_2076278837200806812);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_1218272769678248077);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_3936184874712729906);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_1218272769678248077);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_3936184874712729906);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}