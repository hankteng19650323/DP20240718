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
void car_err_fun(double *nom_x, double *delta_x, double *out_1846714792948325524);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_8663691803207781378);
void car_H_mod_fun(double *state, double *out_5975961191185579824);
void car_f_fun(double *state, double dt, double *out_4476017350751467473);
void car_F_fun(double *state, double dt, double *out_1629429763049756951);
void car_h_25(double *state, double *unused, double *out_7659068027560600567);
void car_H_25(double *state, double *unused, double *out_5775380342488646060);
void car_h_24(double *state, double *unused, double *out_6245453102149723176);
void car_H_24(double *state, double *unused, double *out_7924854404254396522);
void car_h_30(double *state, double *unused, double *out_7383873965276094678);
void car_H_30(double *state, double *unused, double *out_3257047383981397433);
void car_h_26(double *state, double *unused, double *out_3413524935122122596);
void car_H_26(double *state, double *unused, double *out_8929860412346849332);
void car_h_27(double *state, double *unused, double *out_4951158479311913399);
void car_H_27(double *state, double *unused, double *out_1033453312797454216);
void car_h_29(double *state, double *unused, double *out_1204288716528746730);
void car_H_29(double *state, double *unused, double *out_2746816039667005249);
void car_h_28(double *state, double *unused, double *out_4347842594635435882);
void car_H_28(double *state, double *unused, double *out_7829215056736535823);
void car_h_31(double *state, double *unused, double *out_4632228850308290920);
void car_H_31(double *state, double *unused, double *out_5744734380611685632);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}