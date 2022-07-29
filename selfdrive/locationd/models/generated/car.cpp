#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.10.1                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_1846714792948325524) {
   out_1846714792948325524[0] = delta_x[0] + nom_x[0];
   out_1846714792948325524[1] = delta_x[1] + nom_x[1];
   out_1846714792948325524[2] = delta_x[2] + nom_x[2];
   out_1846714792948325524[3] = delta_x[3] + nom_x[3];
   out_1846714792948325524[4] = delta_x[4] + nom_x[4];
   out_1846714792948325524[5] = delta_x[5] + nom_x[5];
   out_1846714792948325524[6] = delta_x[6] + nom_x[6];
   out_1846714792948325524[7] = delta_x[7] + nom_x[7];
   out_1846714792948325524[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_8663691803207781378) {
   out_8663691803207781378[0] = -nom_x[0] + true_x[0];
   out_8663691803207781378[1] = -nom_x[1] + true_x[1];
   out_8663691803207781378[2] = -nom_x[2] + true_x[2];
   out_8663691803207781378[3] = -nom_x[3] + true_x[3];
   out_8663691803207781378[4] = -nom_x[4] + true_x[4];
   out_8663691803207781378[5] = -nom_x[5] + true_x[5];
   out_8663691803207781378[6] = -nom_x[6] + true_x[6];
   out_8663691803207781378[7] = -nom_x[7] + true_x[7];
   out_8663691803207781378[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_5975961191185579824) {
   out_5975961191185579824[0] = 1.0;
   out_5975961191185579824[1] = 0;
   out_5975961191185579824[2] = 0;
   out_5975961191185579824[3] = 0;
   out_5975961191185579824[4] = 0;
   out_5975961191185579824[5] = 0;
   out_5975961191185579824[6] = 0;
   out_5975961191185579824[7] = 0;
   out_5975961191185579824[8] = 0;
   out_5975961191185579824[9] = 0;
   out_5975961191185579824[10] = 1.0;
   out_5975961191185579824[11] = 0;
   out_5975961191185579824[12] = 0;
   out_5975961191185579824[13] = 0;
   out_5975961191185579824[14] = 0;
   out_5975961191185579824[15] = 0;
   out_5975961191185579824[16] = 0;
   out_5975961191185579824[17] = 0;
   out_5975961191185579824[18] = 0;
   out_5975961191185579824[19] = 0;
   out_5975961191185579824[20] = 1.0;
   out_5975961191185579824[21] = 0;
   out_5975961191185579824[22] = 0;
   out_5975961191185579824[23] = 0;
   out_5975961191185579824[24] = 0;
   out_5975961191185579824[25] = 0;
   out_5975961191185579824[26] = 0;
   out_5975961191185579824[27] = 0;
   out_5975961191185579824[28] = 0;
   out_5975961191185579824[29] = 0;
   out_5975961191185579824[30] = 1.0;
   out_5975961191185579824[31] = 0;
   out_5975961191185579824[32] = 0;
   out_5975961191185579824[33] = 0;
   out_5975961191185579824[34] = 0;
   out_5975961191185579824[35] = 0;
   out_5975961191185579824[36] = 0;
   out_5975961191185579824[37] = 0;
   out_5975961191185579824[38] = 0;
   out_5975961191185579824[39] = 0;
   out_5975961191185579824[40] = 1.0;
   out_5975961191185579824[41] = 0;
   out_5975961191185579824[42] = 0;
   out_5975961191185579824[43] = 0;
   out_5975961191185579824[44] = 0;
   out_5975961191185579824[45] = 0;
   out_5975961191185579824[46] = 0;
   out_5975961191185579824[47] = 0;
   out_5975961191185579824[48] = 0;
   out_5975961191185579824[49] = 0;
   out_5975961191185579824[50] = 1.0;
   out_5975961191185579824[51] = 0;
   out_5975961191185579824[52] = 0;
   out_5975961191185579824[53] = 0;
   out_5975961191185579824[54] = 0;
   out_5975961191185579824[55] = 0;
   out_5975961191185579824[56] = 0;
   out_5975961191185579824[57] = 0;
   out_5975961191185579824[58] = 0;
   out_5975961191185579824[59] = 0;
   out_5975961191185579824[60] = 1.0;
   out_5975961191185579824[61] = 0;
   out_5975961191185579824[62] = 0;
   out_5975961191185579824[63] = 0;
   out_5975961191185579824[64] = 0;
   out_5975961191185579824[65] = 0;
   out_5975961191185579824[66] = 0;
   out_5975961191185579824[67] = 0;
   out_5975961191185579824[68] = 0;
   out_5975961191185579824[69] = 0;
   out_5975961191185579824[70] = 1.0;
   out_5975961191185579824[71] = 0;
   out_5975961191185579824[72] = 0;
   out_5975961191185579824[73] = 0;
   out_5975961191185579824[74] = 0;
   out_5975961191185579824[75] = 0;
   out_5975961191185579824[76] = 0;
   out_5975961191185579824[77] = 0;
   out_5975961191185579824[78] = 0;
   out_5975961191185579824[79] = 0;
   out_5975961191185579824[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_4476017350751467473) {
   out_4476017350751467473[0] = state[0];
   out_4476017350751467473[1] = state[1];
   out_4476017350751467473[2] = state[2];
   out_4476017350751467473[3] = state[3];
   out_4476017350751467473[4] = state[4];
   out_4476017350751467473[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_4476017350751467473[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_4476017350751467473[7] = state[7];
   out_4476017350751467473[8] = state[8];
}
void F_fun(double *state, double dt, double *out_1629429763049756951) {
   out_1629429763049756951[0] = 1;
   out_1629429763049756951[1] = 0;
   out_1629429763049756951[2] = 0;
   out_1629429763049756951[3] = 0;
   out_1629429763049756951[4] = 0;
   out_1629429763049756951[5] = 0;
   out_1629429763049756951[6] = 0;
   out_1629429763049756951[7] = 0;
   out_1629429763049756951[8] = 0;
   out_1629429763049756951[9] = 0;
   out_1629429763049756951[10] = 1;
   out_1629429763049756951[11] = 0;
   out_1629429763049756951[12] = 0;
   out_1629429763049756951[13] = 0;
   out_1629429763049756951[14] = 0;
   out_1629429763049756951[15] = 0;
   out_1629429763049756951[16] = 0;
   out_1629429763049756951[17] = 0;
   out_1629429763049756951[18] = 0;
   out_1629429763049756951[19] = 0;
   out_1629429763049756951[20] = 1;
   out_1629429763049756951[21] = 0;
   out_1629429763049756951[22] = 0;
   out_1629429763049756951[23] = 0;
   out_1629429763049756951[24] = 0;
   out_1629429763049756951[25] = 0;
   out_1629429763049756951[26] = 0;
   out_1629429763049756951[27] = 0;
   out_1629429763049756951[28] = 0;
   out_1629429763049756951[29] = 0;
   out_1629429763049756951[30] = 1;
   out_1629429763049756951[31] = 0;
   out_1629429763049756951[32] = 0;
   out_1629429763049756951[33] = 0;
   out_1629429763049756951[34] = 0;
   out_1629429763049756951[35] = 0;
   out_1629429763049756951[36] = 0;
   out_1629429763049756951[37] = 0;
   out_1629429763049756951[38] = 0;
   out_1629429763049756951[39] = 0;
   out_1629429763049756951[40] = 1;
   out_1629429763049756951[41] = 0;
   out_1629429763049756951[42] = 0;
   out_1629429763049756951[43] = 0;
   out_1629429763049756951[44] = 0;
   out_1629429763049756951[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_1629429763049756951[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_1629429763049756951[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_1629429763049756951[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_1629429763049756951[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_1629429763049756951[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_1629429763049756951[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_1629429763049756951[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_1629429763049756951[53] = -9.8000000000000007*dt;
   out_1629429763049756951[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_1629429763049756951[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_1629429763049756951[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_1629429763049756951[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_1629429763049756951[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_1629429763049756951[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_1629429763049756951[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_1629429763049756951[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_1629429763049756951[62] = 0;
   out_1629429763049756951[63] = 0;
   out_1629429763049756951[64] = 0;
   out_1629429763049756951[65] = 0;
   out_1629429763049756951[66] = 0;
   out_1629429763049756951[67] = 0;
   out_1629429763049756951[68] = 0;
   out_1629429763049756951[69] = 0;
   out_1629429763049756951[70] = 1;
   out_1629429763049756951[71] = 0;
   out_1629429763049756951[72] = 0;
   out_1629429763049756951[73] = 0;
   out_1629429763049756951[74] = 0;
   out_1629429763049756951[75] = 0;
   out_1629429763049756951[76] = 0;
   out_1629429763049756951[77] = 0;
   out_1629429763049756951[78] = 0;
   out_1629429763049756951[79] = 0;
   out_1629429763049756951[80] = 1;
}
void h_25(double *state, double *unused, double *out_7659068027560600567) {
   out_7659068027560600567[0] = state[6];
}
void H_25(double *state, double *unused, double *out_5775380342488646060) {
   out_5775380342488646060[0] = 0;
   out_5775380342488646060[1] = 0;
   out_5775380342488646060[2] = 0;
   out_5775380342488646060[3] = 0;
   out_5775380342488646060[4] = 0;
   out_5775380342488646060[5] = 0;
   out_5775380342488646060[6] = 1;
   out_5775380342488646060[7] = 0;
   out_5775380342488646060[8] = 0;
}
void h_24(double *state, double *unused, double *out_6245453102149723176) {
   out_6245453102149723176[0] = state[4];
   out_6245453102149723176[1] = state[5];
}
void H_24(double *state, double *unused, double *out_7924854404254396522) {
   out_7924854404254396522[0] = 0;
   out_7924854404254396522[1] = 0;
   out_7924854404254396522[2] = 0;
   out_7924854404254396522[3] = 0;
   out_7924854404254396522[4] = 1;
   out_7924854404254396522[5] = 0;
   out_7924854404254396522[6] = 0;
   out_7924854404254396522[7] = 0;
   out_7924854404254396522[8] = 0;
   out_7924854404254396522[9] = 0;
   out_7924854404254396522[10] = 0;
   out_7924854404254396522[11] = 0;
   out_7924854404254396522[12] = 0;
   out_7924854404254396522[13] = 0;
   out_7924854404254396522[14] = 1;
   out_7924854404254396522[15] = 0;
   out_7924854404254396522[16] = 0;
   out_7924854404254396522[17] = 0;
}
void h_30(double *state, double *unused, double *out_7383873965276094678) {
   out_7383873965276094678[0] = state[4];
}
void H_30(double *state, double *unused, double *out_3257047383981397433) {
   out_3257047383981397433[0] = 0;
   out_3257047383981397433[1] = 0;
   out_3257047383981397433[2] = 0;
   out_3257047383981397433[3] = 0;
   out_3257047383981397433[4] = 1;
   out_3257047383981397433[5] = 0;
   out_3257047383981397433[6] = 0;
   out_3257047383981397433[7] = 0;
   out_3257047383981397433[8] = 0;
}
void h_26(double *state, double *unused, double *out_3413524935122122596) {
   out_3413524935122122596[0] = state[7];
}
void H_26(double *state, double *unused, double *out_8929860412346849332) {
   out_8929860412346849332[0] = 0;
   out_8929860412346849332[1] = 0;
   out_8929860412346849332[2] = 0;
   out_8929860412346849332[3] = 0;
   out_8929860412346849332[4] = 0;
   out_8929860412346849332[5] = 0;
   out_8929860412346849332[6] = 0;
   out_8929860412346849332[7] = 1;
   out_8929860412346849332[8] = 0;
}
void h_27(double *state, double *unused, double *out_4951158479311913399) {
   out_4951158479311913399[0] = state[3];
}
void H_27(double *state, double *unused, double *out_1033453312797454216) {
   out_1033453312797454216[0] = 0;
   out_1033453312797454216[1] = 0;
   out_1033453312797454216[2] = 0;
   out_1033453312797454216[3] = 1;
   out_1033453312797454216[4] = 0;
   out_1033453312797454216[5] = 0;
   out_1033453312797454216[6] = 0;
   out_1033453312797454216[7] = 0;
   out_1033453312797454216[8] = 0;
}
void h_29(double *state, double *unused, double *out_1204288716528746730) {
   out_1204288716528746730[0] = state[1];
}
void H_29(double *state, double *unused, double *out_2746816039667005249) {
   out_2746816039667005249[0] = 0;
   out_2746816039667005249[1] = 1;
   out_2746816039667005249[2] = 0;
   out_2746816039667005249[3] = 0;
   out_2746816039667005249[4] = 0;
   out_2746816039667005249[5] = 0;
   out_2746816039667005249[6] = 0;
   out_2746816039667005249[7] = 0;
   out_2746816039667005249[8] = 0;
}
void h_28(double *state, double *unused, double *out_4347842594635435882) {
   out_4347842594635435882[0] = state[0];
}
void H_28(double *state, double *unused, double *out_7829215056736535823) {
   out_7829215056736535823[0] = 1;
   out_7829215056736535823[1] = 0;
   out_7829215056736535823[2] = 0;
   out_7829215056736535823[3] = 0;
   out_7829215056736535823[4] = 0;
   out_7829215056736535823[5] = 0;
   out_7829215056736535823[6] = 0;
   out_7829215056736535823[7] = 0;
   out_7829215056736535823[8] = 0;
}
void h_31(double *state, double *unused, double *out_4632228850308290920) {
   out_4632228850308290920[0] = state[8];
}
void H_31(double *state, double *unused, double *out_5744734380611685632) {
   out_5744734380611685632[0] = 0;
   out_5744734380611685632[1] = 0;
   out_5744734380611685632[2] = 0;
   out_5744734380611685632[3] = 0;
   out_5744734380611685632[4] = 0;
   out_5744734380611685632[5] = 0;
   out_5744734380611685632[6] = 0;
   out_5744734380611685632[7] = 0;
   out_5744734380611685632[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_1846714792948325524) {
  err_fun(nom_x, delta_x, out_1846714792948325524);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_8663691803207781378) {
  inv_err_fun(nom_x, true_x, out_8663691803207781378);
}
void car_H_mod_fun(double *state, double *out_5975961191185579824) {
  H_mod_fun(state, out_5975961191185579824);
}
void car_f_fun(double *state, double dt, double *out_4476017350751467473) {
  f_fun(state,  dt, out_4476017350751467473);
}
void car_F_fun(double *state, double dt, double *out_1629429763049756951) {
  F_fun(state,  dt, out_1629429763049756951);
}
void car_h_25(double *state, double *unused, double *out_7659068027560600567) {
  h_25(state, unused, out_7659068027560600567);
}
void car_H_25(double *state, double *unused, double *out_5775380342488646060) {
  H_25(state, unused, out_5775380342488646060);
}
void car_h_24(double *state, double *unused, double *out_6245453102149723176) {
  h_24(state, unused, out_6245453102149723176);
}
void car_H_24(double *state, double *unused, double *out_7924854404254396522) {
  H_24(state, unused, out_7924854404254396522);
}
void car_h_30(double *state, double *unused, double *out_7383873965276094678) {
  h_30(state, unused, out_7383873965276094678);
}
void car_H_30(double *state, double *unused, double *out_3257047383981397433) {
  H_30(state, unused, out_3257047383981397433);
}
void car_h_26(double *state, double *unused, double *out_3413524935122122596) {
  h_26(state, unused, out_3413524935122122596);
}
void car_H_26(double *state, double *unused, double *out_8929860412346849332) {
  H_26(state, unused, out_8929860412346849332);
}
void car_h_27(double *state, double *unused, double *out_4951158479311913399) {
  h_27(state, unused, out_4951158479311913399);
}
void car_H_27(double *state, double *unused, double *out_1033453312797454216) {
  H_27(state, unused, out_1033453312797454216);
}
void car_h_29(double *state, double *unused, double *out_1204288716528746730) {
  h_29(state, unused, out_1204288716528746730);
}
void car_H_29(double *state, double *unused, double *out_2746816039667005249) {
  H_29(state, unused, out_2746816039667005249);
}
void car_h_28(double *state, double *unused, double *out_4347842594635435882) {
  h_28(state, unused, out_4347842594635435882);
}
void car_H_28(double *state, double *unused, double *out_7829215056736535823) {
  H_28(state, unused, out_7829215056736535823);
}
void car_h_31(double *state, double *unused, double *out_4632228850308290920) {
  h_31(state, unused, out_4632228850308290920);
}
void car_H_31(double *state, double *unused, double *out_5744734380611685632) {
  H_31(state, unused, out_5744734380611685632);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_init(car);
