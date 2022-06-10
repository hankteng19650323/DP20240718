#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_113600903361663266);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4678168258284122623);
void car_H_mod_fun(double *state, double *out_2456387104957076988);
void car_f_fun(double *state, double dt, double *out_8116608585821850611);
void car_F_fun(double *state, double dt, double *out_505390882539216423);
void car_h_25(double *state, double *unused, double *out_7249789621637654674);
void car_H_25(double *state, double *unused, double *out_4667221578230230682);
void car_h_24(double *state, double *unused, double *out_1413574261057562674);
void car_H_24(double *state, double *unused, double *out_8910707630451614082);
void car_h_30(double *state, double *unused, double *out_7524983683922160563);
void car_H_30(double *state, double *unused, double *out_9194917908357838880);
void car_h_26(double *state, double *unused, double *out_6921667799245683046);
void car_H_26(double *state, double *unused, double *out_8408724897104286906);
void car_h_27(double *state, double *unused, double *out_5094435016338702552);
void car_H_27(double *state, double *unused, double *out_7077062853551287825);
void car_h_29(double *state, double *unused, double *out_5920087122126545408);
void car_H_29(double *state, double *unused, double *out_8684686564043446696);
void car_h_28(double *state, double *unused, double *out_3701874447927294588);
void car_H_28(double *state, double *unused, double *out_4679658492596574346);
void car_h_31(double *state, double *unused, double *out_3993738495085910972);
void car_H_31(double *state, double *unused, double *out_9034932999337638382);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}