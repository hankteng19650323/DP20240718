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
void err_fun(double *nom_x, double *delta_x, double *out_6952590880159753802) {
   out_6952590880159753802[0] = delta_x[0] + nom_x[0];
   out_6952590880159753802[1] = delta_x[1] + nom_x[1];
   out_6952590880159753802[2] = delta_x[2] + nom_x[2];
   out_6952590880159753802[3] = delta_x[3] + nom_x[3];
   out_6952590880159753802[4] = delta_x[4] + nom_x[4];
   out_6952590880159753802[5] = delta_x[5] + nom_x[5];
   out_6952590880159753802[6] = delta_x[6] + nom_x[6];
   out_6952590880159753802[7] = delta_x[7] + nom_x[7];
   out_6952590880159753802[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2261899865498132123) {
   out_2261899865498132123[0] = -nom_x[0] + true_x[0];
   out_2261899865498132123[1] = -nom_x[1] + true_x[1];
   out_2261899865498132123[2] = -nom_x[2] + true_x[2];
   out_2261899865498132123[3] = -nom_x[3] + true_x[3];
   out_2261899865498132123[4] = -nom_x[4] + true_x[4];
   out_2261899865498132123[5] = -nom_x[5] + true_x[5];
   out_2261899865498132123[6] = -nom_x[6] + true_x[6];
   out_2261899865498132123[7] = -nom_x[7] + true_x[7];
   out_2261899865498132123[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_8676500456739819914) {
   out_8676500456739819914[0] = 1.0;
   out_8676500456739819914[1] = 0;
   out_8676500456739819914[2] = 0;
   out_8676500456739819914[3] = 0;
   out_8676500456739819914[4] = 0;
   out_8676500456739819914[5] = 0;
   out_8676500456739819914[6] = 0;
   out_8676500456739819914[7] = 0;
   out_8676500456739819914[8] = 0;
   out_8676500456739819914[9] = 0;
   out_8676500456739819914[10] = 1.0;
   out_8676500456739819914[11] = 0;
   out_8676500456739819914[12] = 0;
   out_8676500456739819914[13] = 0;
   out_8676500456739819914[14] = 0;
   out_8676500456739819914[15] = 0;
   out_8676500456739819914[16] = 0;
   out_8676500456739819914[17] = 0;
   out_8676500456739819914[18] = 0;
   out_8676500456739819914[19] = 0;
   out_8676500456739819914[20] = 1.0;
   out_8676500456739819914[21] = 0;
   out_8676500456739819914[22] = 0;
   out_8676500456739819914[23] = 0;
   out_8676500456739819914[24] = 0;
   out_8676500456739819914[25] = 0;
   out_8676500456739819914[26] = 0;
   out_8676500456739819914[27] = 0;
   out_8676500456739819914[28] = 0;
   out_8676500456739819914[29] = 0;
   out_8676500456739819914[30] = 1.0;
   out_8676500456739819914[31] = 0;
   out_8676500456739819914[32] = 0;
   out_8676500456739819914[33] = 0;
   out_8676500456739819914[34] = 0;
   out_8676500456739819914[35] = 0;
   out_8676500456739819914[36] = 0;
   out_8676500456739819914[37] = 0;
   out_8676500456739819914[38] = 0;
   out_8676500456739819914[39] = 0;
   out_8676500456739819914[40] = 1.0;
   out_8676500456739819914[41] = 0;
   out_8676500456739819914[42] = 0;
   out_8676500456739819914[43] = 0;
   out_8676500456739819914[44] = 0;
   out_8676500456739819914[45] = 0;
   out_8676500456739819914[46] = 0;
   out_8676500456739819914[47] = 0;
   out_8676500456739819914[48] = 0;
   out_8676500456739819914[49] = 0;
   out_8676500456739819914[50] = 1.0;
   out_8676500456739819914[51] = 0;
   out_8676500456739819914[52] = 0;
   out_8676500456739819914[53] = 0;
   out_8676500456739819914[54] = 0;
   out_8676500456739819914[55] = 0;
   out_8676500456739819914[56] = 0;
   out_8676500456739819914[57] = 0;
   out_8676500456739819914[58] = 0;
   out_8676500456739819914[59] = 0;
   out_8676500456739819914[60] = 1.0;
   out_8676500456739819914[61] = 0;
   out_8676500456739819914[62] = 0;
   out_8676500456739819914[63] = 0;
   out_8676500456739819914[64] = 0;
   out_8676500456739819914[65] = 0;
   out_8676500456739819914[66] = 0;
   out_8676500456739819914[67] = 0;
   out_8676500456739819914[68] = 0;
   out_8676500456739819914[69] = 0;
   out_8676500456739819914[70] = 1.0;
   out_8676500456739819914[71] = 0;
   out_8676500456739819914[72] = 0;
   out_8676500456739819914[73] = 0;
   out_8676500456739819914[74] = 0;
   out_8676500456739819914[75] = 0;
   out_8676500456739819914[76] = 0;
   out_8676500456739819914[77] = 0;
   out_8676500456739819914[78] = 0;
   out_8676500456739819914[79] = 0;
   out_8676500456739819914[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_4153484326751475120) {
   out_4153484326751475120[0] = state[0];
   out_4153484326751475120[1] = state[1];
   out_4153484326751475120[2] = state[2];
   out_4153484326751475120[3] = state[3];
   out_4153484326751475120[4] = state[4];
   out_4153484326751475120[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_4153484326751475120[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_4153484326751475120[7] = state[7];
   out_4153484326751475120[8] = state[8];
}
void F_fun(double *state, double dt, double *out_74190663820938698) {
   out_74190663820938698[0] = 1;
   out_74190663820938698[1] = 0;
   out_74190663820938698[2] = 0;
   out_74190663820938698[3] = 0;
   out_74190663820938698[4] = 0;
   out_74190663820938698[5] = 0;
   out_74190663820938698[6] = 0;
   out_74190663820938698[7] = 0;
   out_74190663820938698[8] = 0;
   out_74190663820938698[9] = 0;
   out_74190663820938698[10] = 1;
   out_74190663820938698[11] = 0;
   out_74190663820938698[12] = 0;
   out_74190663820938698[13] = 0;
   out_74190663820938698[14] = 0;
   out_74190663820938698[15] = 0;
   out_74190663820938698[16] = 0;
   out_74190663820938698[17] = 0;
   out_74190663820938698[18] = 0;
   out_74190663820938698[19] = 0;
   out_74190663820938698[20] = 1;
   out_74190663820938698[21] = 0;
   out_74190663820938698[22] = 0;
   out_74190663820938698[23] = 0;
   out_74190663820938698[24] = 0;
   out_74190663820938698[25] = 0;
   out_74190663820938698[26] = 0;
   out_74190663820938698[27] = 0;
   out_74190663820938698[28] = 0;
   out_74190663820938698[29] = 0;
   out_74190663820938698[30] = 1;
   out_74190663820938698[31] = 0;
   out_74190663820938698[32] = 0;
   out_74190663820938698[33] = 0;
   out_74190663820938698[34] = 0;
   out_74190663820938698[35] = 0;
   out_74190663820938698[36] = 0;
   out_74190663820938698[37] = 0;
   out_74190663820938698[38] = 0;
   out_74190663820938698[39] = 0;
   out_74190663820938698[40] = 1;
   out_74190663820938698[41] = 0;
   out_74190663820938698[42] = 0;
   out_74190663820938698[43] = 0;
   out_74190663820938698[44] = 0;
   out_74190663820938698[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_74190663820938698[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_74190663820938698[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_74190663820938698[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_74190663820938698[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_74190663820938698[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_74190663820938698[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_74190663820938698[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_74190663820938698[53] = -9.8000000000000007*dt;
   out_74190663820938698[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_74190663820938698[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_74190663820938698[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_74190663820938698[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_74190663820938698[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_74190663820938698[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_74190663820938698[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_74190663820938698[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_74190663820938698[62] = 0;
   out_74190663820938698[63] = 0;
   out_74190663820938698[64] = 0;
   out_74190663820938698[65] = 0;
   out_74190663820938698[66] = 0;
   out_74190663820938698[67] = 0;
   out_74190663820938698[68] = 0;
   out_74190663820938698[69] = 0;
   out_74190663820938698[70] = 1;
   out_74190663820938698[71] = 0;
   out_74190663820938698[72] = 0;
   out_74190663820938698[73] = 0;
   out_74190663820938698[74] = 0;
   out_74190663820938698[75] = 0;
   out_74190663820938698[76] = 0;
   out_74190663820938698[77] = 0;
   out_74190663820938698[78] = 0;
   out_74190663820938698[79] = 0;
   out_74190663820938698[80] = 1;
}
void h_25(double *state, double *unused, double *out_5053605820729364307) {
   out_5053605820729364307[0] = state[6];
}
void H_25(double *state, double *unused, double *out_1038074172362167343) {
   out_1038074172362167343[0] = 0;
   out_1038074172362167343[1] = 0;
   out_1038074172362167343[2] = 0;
   out_1038074172362167343[3] = 0;
   out_1038074172362167343[4] = 0;
   out_1038074172362167343[5] = 0;
   out_1038074172362167343[6] = 1;
   out_1038074172362167343[7] = 0;
   out_1038074172362167343[8] = 0;
}
void h_24(double *state, double *unused, double *out_323218756557611349) {
   out_323218756557611349[0] = state[4];
   out_323218756557611349[1] = state[5];
}
void H_24(double *state, double *unused, double *out_5162958507488994083) {
   out_5162958507488994083[0] = 0;
   out_5162958507488994083[1] = 0;
   out_5162958507488994083[2] = 0;
   out_5162958507488994083[3] = 0;
   out_5162958507488994083[4] = 1;
   out_5162958507488994083[5] = 0;
   out_5162958507488994083[6] = 0;
   out_5162958507488994083[7] = 0;
   out_5162958507488994083[8] = 0;
   out_5162958507488994083[9] = 0;
   out_5162958507488994083[10] = 0;
   out_5162958507488994083[11] = 0;
   out_5162958507488994083[12] = 0;
   out_5162958507488994083[13] = 0;
   out_5162958507488994083[14] = 1;
   out_5162958507488994083[15] = 0;
   out_5162958507488994083[16] = 0;
   out_5162958507488994083[17] = 0;
}
void h_30(double *state, double *unused, double *out_5629872996159514868) {
   out_5629872996159514868[0] = state[4];
}
void H_30(double *state, double *unused, double *out_908735225218927273) {
   out_908735225218927273[0] = 0;
   out_908735225218927273[1] = 0;
   out_908735225218927273[2] = 0;
   out_908735225218927273[3] = 0;
   out_908735225218927273[4] = 1;
   out_908735225218927273[5] = 0;
   out_908735225218927273[6] = 0;
   out_908735225218927273[7] = 0;
   out_908735225218927273[8] = 0;
}
void h_26(double *state, double *unused, double *out_3610667957368716681) {
   out_3610667957368716681[0] = state[7];
}
void H_26(double *state, double *unused, double *out_1694928236472479247) {
   out_1694928236472479247[0] = 0;
   out_1694928236472479247[1] = 0;
   out_1694928236472479247[2] = 0;
   out_1694928236472479247[3] = 0;
   out_1694928236472479247[4] = 0;
   out_1694928236472479247[5] = 0;
   out_1694928236472479247[6] = 0;
   out_1694928236472479247[7] = 1;
   out_1694928236472479247[8] = 0;
}
void h_27(double *state, double *unused, double *out_7908054221639354854) {
   out_7908054221639354854[0] = state[3];
}
void H_27(double *state, double *unused, double *out_1266028086581497638) {
   out_1266028086581497638[0] = 0;
   out_1266028086581497638[1] = 0;
   out_1266028086581497638[2] = 0;
   out_1266028086581497638[3] = 1;
   out_1266028086581497638[4] = 0;
   out_1266028086581497638[5] = 0;
   out_1266028086581497638[6] = 0;
   out_1266028086581497638[7] = 0;
   out_1266028086581497638[8] = 0;
}
void h_29(double *state, double *unused, double *out_7590963861714711801) {
   out_7590963861714711801[0] = state[1];
}
void H_29(double *state, double *unused, double *out_1418966569533319457) {
   out_1418966569533319457[0] = 0;
   out_1418966569533319457[1] = 1;
   out_1418966569533319457[2] = 0;
   out_1418966569533319457[3] = 0;
   out_1418966569533319457[4] = 0;
   out_1418966569533319457[5] = 0;
   out_1418966569533319457[6] = 0;
   out_1418966569533319457[7] = 0;
   out_1418966569533319457[8] = 0;
}
void h_28(double *state, double *unused, double *out_2864484656338372045) {
   out_2864484656338372045[0] = state[0];
}
void H_28(double *state, double *unused, double *out_3663432447536211117) {
   out_3663432447536211117[0] = 1;
   out_3663432447536211117[1] = 0;
   out_3663432447536211117[2] = 0;
   out_3663432447536211117[3] = 0;
   out_3663432447536211117[4] = 0;
   out_3663432447536211117[5] = 0;
   out_3663432447536211117[6] = 0;
   out_3663432447536211117[7] = 0;
   out_3663432447536211117[8] = 0;
}
void h_31(double *state, double *unused, double *out_2631186891694003320) {
   out_2631186891694003320[0] = state[8];
}
void H_31(double *state, double *unused, double *out_1068720134239127771) {
   out_1068720134239127771[0] = 0;
   out_1068720134239127771[1] = 0;
   out_1068720134239127771[2] = 0;
   out_1068720134239127771[3] = 0;
   out_1068720134239127771[4] = 0;
   out_1068720134239127771[5] = 0;
   out_1068720134239127771[6] = 0;
   out_1068720134239127771[7] = 0;
   out_1068720134239127771[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_6952590880159753802) {
  err_fun(nom_x, delta_x, out_6952590880159753802);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2261899865498132123) {
  inv_err_fun(nom_x, true_x, out_2261899865498132123);
}
void car_H_mod_fun(double *state, double *out_8676500456739819914) {
  H_mod_fun(state, out_8676500456739819914);
}
void car_f_fun(double *state, double dt, double *out_4153484326751475120) {
  f_fun(state,  dt, out_4153484326751475120);
}
void car_F_fun(double *state, double dt, double *out_74190663820938698) {
  F_fun(state,  dt, out_74190663820938698);
}
void car_h_25(double *state, double *unused, double *out_5053605820729364307) {
  h_25(state, unused, out_5053605820729364307);
}
void car_H_25(double *state, double *unused, double *out_1038074172362167343) {
  H_25(state, unused, out_1038074172362167343);
}
void car_h_24(double *state, double *unused, double *out_323218756557611349) {
  h_24(state, unused, out_323218756557611349);
}
void car_H_24(double *state, double *unused, double *out_5162958507488994083) {
  H_24(state, unused, out_5162958507488994083);
}
void car_h_30(double *state, double *unused, double *out_5629872996159514868) {
  h_30(state, unused, out_5629872996159514868);
}
void car_H_30(double *state, double *unused, double *out_908735225218927273) {
  H_30(state, unused, out_908735225218927273);
}
void car_h_26(double *state, double *unused, double *out_3610667957368716681) {
  h_26(state, unused, out_3610667957368716681);
}
void car_H_26(double *state, double *unused, double *out_1694928236472479247) {
  H_26(state, unused, out_1694928236472479247);
}
void car_h_27(double *state, double *unused, double *out_7908054221639354854) {
  h_27(state, unused, out_7908054221639354854);
}
void car_H_27(double *state, double *unused, double *out_1266028086581497638) {
  H_27(state, unused, out_1266028086581497638);
}
void car_h_29(double *state, double *unused, double *out_7590963861714711801) {
  h_29(state, unused, out_7590963861714711801);
}
void car_H_29(double *state, double *unused, double *out_1418966569533319457) {
  H_29(state, unused, out_1418966569533319457);
}
void car_h_28(double *state, double *unused, double *out_2864484656338372045) {
  h_28(state, unused, out_2864484656338372045);
}
void car_H_28(double *state, double *unused, double *out_3663432447536211117) {
  H_28(state, unused, out_3663432447536211117);
}
void car_h_31(double *state, double *unused, double *out_2631186891694003320) {
  h_31(state, unused, out_2631186891694003320);
}
void car_H_31(double *state, double *unused, double *out_1068720134239127771) {
  H_31(state, unused, out_1068720134239127771);
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
