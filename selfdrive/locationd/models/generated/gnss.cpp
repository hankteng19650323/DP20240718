#include "gnss.h"

namespace {
#define DIM 11
#define EDIM 11
#define MEDIM 11
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_6 = 3.8414588206941227;
const static double MAHA_THRESH_20 = 3.8414588206941227;
const static double MAHA_THRESH_7 = 3.8414588206941227;
const static double MAHA_THRESH_21 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.10.1                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_5685586692381648546) {
   out_5685586692381648546[0] = delta_x[0] + nom_x[0];
   out_5685586692381648546[1] = delta_x[1] + nom_x[1];
   out_5685586692381648546[2] = delta_x[2] + nom_x[2];
   out_5685586692381648546[3] = delta_x[3] + nom_x[3];
   out_5685586692381648546[4] = delta_x[4] + nom_x[4];
   out_5685586692381648546[5] = delta_x[5] + nom_x[5];
   out_5685586692381648546[6] = delta_x[6] + nom_x[6];
   out_5685586692381648546[7] = delta_x[7] + nom_x[7];
   out_5685586692381648546[8] = delta_x[8] + nom_x[8];
   out_5685586692381648546[9] = delta_x[9] + nom_x[9];
   out_5685586692381648546[10] = delta_x[10] + nom_x[10];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_961684295642468722) {
   out_961684295642468722[0] = -nom_x[0] + true_x[0];
   out_961684295642468722[1] = -nom_x[1] + true_x[1];
   out_961684295642468722[2] = -nom_x[2] + true_x[2];
   out_961684295642468722[3] = -nom_x[3] + true_x[3];
   out_961684295642468722[4] = -nom_x[4] + true_x[4];
   out_961684295642468722[5] = -nom_x[5] + true_x[5];
   out_961684295642468722[6] = -nom_x[6] + true_x[6];
   out_961684295642468722[7] = -nom_x[7] + true_x[7];
   out_961684295642468722[8] = -nom_x[8] + true_x[8];
   out_961684295642468722[9] = -nom_x[9] + true_x[9];
   out_961684295642468722[10] = -nom_x[10] + true_x[10];
}
void H_mod_fun(double *state, double *out_3447866398814421424) {
   out_3447866398814421424[0] = 1.0;
   out_3447866398814421424[1] = 0;
   out_3447866398814421424[2] = 0;
   out_3447866398814421424[3] = 0;
   out_3447866398814421424[4] = 0;
   out_3447866398814421424[5] = 0;
   out_3447866398814421424[6] = 0;
   out_3447866398814421424[7] = 0;
   out_3447866398814421424[8] = 0;
   out_3447866398814421424[9] = 0;
   out_3447866398814421424[10] = 0;
   out_3447866398814421424[11] = 0;
   out_3447866398814421424[12] = 1.0;
   out_3447866398814421424[13] = 0;
   out_3447866398814421424[14] = 0;
   out_3447866398814421424[15] = 0;
   out_3447866398814421424[16] = 0;
   out_3447866398814421424[17] = 0;
   out_3447866398814421424[18] = 0;
   out_3447866398814421424[19] = 0;
   out_3447866398814421424[20] = 0;
   out_3447866398814421424[21] = 0;
   out_3447866398814421424[22] = 0;
   out_3447866398814421424[23] = 0;
   out_3447866398814421424[24] = 1.0;
   out_3447866398814421424[25] = 0;
   out_3447866398814421424[26] = 0;
   out_3447866398814421424[27] = 0;
   out_3447866398814421424[28] = 0;
   out_3447866398814421424[29] = 0;
   out_3447866398814421424[30] = 0;
   out_3447866398814421424[31] = 0;
   out_3447866398814421424[32] = 0;
   out_3447866398814421424[33] = 0;
   out_3447866398814421424[34] = 0;
   out_3447866398814421424[35] = 0;
   out_3447866398814421424[36] = 1.0;
   out_3447866398814421424[37] = 0;
   out_3447866398814421424[38] = 0;
   out_3447866398814421424[39] = 0;
   out_3447866398814421424[40] = 0;
   out_3447866398814421424[41] = 0;
   out_3447866398814421424[42] = 0;
   out_3447866398814421424[43] = 0;
   out_3447866398814421424[44] = 0;
   out_3447866398814421424[45] = 0;
   out_3447866398814421424[46] = 0;
   out_3447866398814421424[47] = 0;
   out_3447866398814421424[48] = 1.0;
   out_3447866398814421424[49] = 0;
   out_3447866398814421424[50] = 0;
   out_3447866398814421424[51] = 0;
   out_3447866398814421424[52] = 0;
   out_3447866398814421424[53] = 0;
   out_3447866398814421424[54] = 0;
   out_3447866398814421424[55] = 0;
   out_3447866398814421424[56] = 0;
   out_3447866398814421424[57] = 0;
   out_3447866398814421424[58] = 0;
   out_3447866398814421424[59] = 0;
   out_3447866398814421424[60] = 1.0;
   out_3447866398814421424[61] = 0;
   out_3447866398814421424[62] = 0;
   out_3447866398814421424[63] = 0;
   out_3447866398814421424[64] = 0;
   out_3447866398814421424[65] = 0;
   out_3447866398814421424[66] = 0;
   out_3447866398814421424[67] = 0;
   out_3447866398814421424[68] = 0;
   out_3447866398814421424[69] = 0;
   out_3447866398814421424[70] = 0;
   out_3447866398814421424[71] = 0;
   out_3447866398814421424[72] = 1.0;
   out_3447866398814421424[73] = 0;
   out_3447866398814421424[74] = 0;
   out_3447866398814421424[75] = 0;
   out_3447866398814421424[76] = 0;
   out_3447866398814421424[77] = 0;
   out_3447866398814421424[78] = 0;
   out_3447866398814421424[79] = 0;
   out_3447866398814421424[80] = 0;
   out_3447866398814421424[81] = 0;
   out_3447866398814421424[82] = 0;
   out_3447866398814421424[83] = 0;
   out_3447866398814421424[84] = 1.0;
   out_3447866398814421424[85] = 0;
   out_3447866398814421424[86] = 0;
   out_3447866398814421424[87] = 0;
   out_3447866398814421424[88] = 0;
   out_3447866398814421424[89] = 0;
   out_3447866398814421424[90] = 0;
   out_3447866398814421424[91] = 0;
   out_3447866398814421424[92] = 0;
   out_3447866398814421424[93] = 0;
   out_3447866398814421424[94] = 0;
   out_3447866398814421424[95] = 0;
   out_3447866398814421424[96] = 1.0;
   out_3447866398814421424[97] = 0;
   out_3447866398814421424[98] = 0;
   out_3447866398814421424[99] = 0;
   out_3447866398814421424[100] = 0;
   out_3447866398814421424[101] = 0;
   out_3447866398814421424[102] = 0;
   out_3447866398814421424[103] = 0;
   out_3447866398814421424[104] = 0;
   out_3447866398814421424[105] = 0;
   out_3447866398814421424[106] = 0;
   out_3447866398814421424[107] = 0;
   out_3447866398814421424[108] = 1.0;
   out_3447866398814421424[109] = 0;
   out_3447866398814421424[110] = 0;
   out_3447866398814421424[111] = 0;
   out_3447866398814421424[112] = 0;
   out_3447866398814421424[113] = 0;
   out_3447866398814421424[114] = 0;
   out_3447866398814421424[115] = 0;
   out_3447866398814421424[116] = 0;
   out_3447866398814421424[117] = 0;
   out_3447866398814421424[118] = 0;
   out_3447866398814421424[119] = 0;
   out_3447866398814421424[120] = 1.0;
}
void f_fun(double *state, double dt, double *out_1737638576013027315) {
   out_1737638576013027315[0] = dt*state[3] + state[0];
   out_1737638576013027315[1] = dt*state[4] + state[1];
   out_1737638576013027315[2] = dt*state[5] + state[2];
   out_1737638576013027315[3] = state[3];
   out_1737638576013027315[4] = state[4];
   out_1737638576013027315[5] = state[5];
   out_1737638576013027315[6] = dt*state[7] + state[6];
   out_1737638576013027315[7] = dt*state[8] + state[7];
   out_1737638576013027315[8] = state[8];
   out_1737638576013027315[9] = state[9];
   out_1737638576013027315[10] = state[10];
}
void F_fun(double *state, double dt, double *out_3900105210689889954) {
   out_3900105210689889954[0] = 1;
   out_3900105210689889954[1] = 0;
   out_3900105210689889954[2] = 0;
   out_3900105210689889954[3] = dt;
   out_3900105210689889954[4] = 0;
   out_3900105210689889954[5] = 0;
   out_3900105210689889954[6] = 0;
   out_3900105210689889954[7] = 0;
   out_3900105210689889954[8] = 0;
   out_3900105210689889954[9] = 0;
   out_3900105210689889954[10] = 0;
   out_3900105210689889954[11] = 0;
   out_3900105210689889954[12] = 1;
   out_3900105210689889954[13] = 0;
   out_3900105210689889954[14] = 0;
   out_3900105210689889954[15] = dt;
   out_3900105210689889954[16] = 0;
   out_3900105210689889954[17] = 0;
   out_3900105210689889954[18] = 0;
   out_3900105210689889954[19] = 0;
   out_3900105210689889954[20] = 0;
   out_3900105210689889954[21] = 0;
   out_3900105210689889954[22] = 0;
   out_3900105210689889954[23] = 0;
   out_3900105210689889954[24] = 1;
   out_3900105210689889954[25] = 0;
   out_3900105210689889954[26] = 0;
   out_3900105210689889954[27] = dt;
   out_3900105210689889954[28] = 0;
   out_3900105210689889954[29] = 0;
   out_3900105210689889954[30] = 0;
   out_3900105210689889954[31] = 0;
   out_3900105210689889954[32] = 0;
   out_3900105210689889954[33] = 0;
   out_3900105210689889954[34] = 0;
   out_3900105210689889954[35] = 0;
   out_3900105210689889954[36] = 1;
   out_3900105210689889954[37] = 0;
   out_3900105210689889954[38] = 0;
   out_3900105210689889954[39] = 0;
   out_3900105210689889954[40] = 0;
   out_3900105210689889954[41] = 0;
   out_3900105210689889954[42] = 0;
   out_3900105210689889954[43] = 0;
   out_3900105210689889954[44] = 0;
   out_3900105210689889954[45] = 0;
   out_3900105210689889954[46] = 0;
   out_3900105210689889954[47] = 0;
   out_3900105210689889954[48] = 1;
   out_3900105210689889954[49] = 0;
   out_3900105210689889954[50] = 0;
   out_3900105210689889954[51] = 0;
   out_3900105210689889954[52] = 0;
   out_3900105210689889954[53] = 0;
   out_3900105210689889954[54] = 0;
   out_3900105210689889954[55] = 0;
   out_3900105210689889954[56] = 0;
   out_3900105210689889954[57] = 0;
   out_3900105210689889954[58] = 0;
   out_3900105210689889954[59] = 0;
   out_3900105210689889954[60] = 1;
   out_3900105210689889954[61] = 0;
   out_3900105210689889954[62] = 0;
   out_3900105210689889954[63] = 0;
   out_3900105210689889954[64] = 0;
   out_3900105210689889954[65] = 0;
   out_3900105210689889954[66] = 0;
   out_3900105210689889954[67] = 0;
   out_3900105210689889954[68] = 0;
   out_3900105210689889954[69] = 0;
   out_3900105210689889954[70] = 0;
   out_3900105210689889954[71] = 0;
   out_3900105210689889954[72] = 1;
   out_3900105210689889954[73] = dt;
   out_3900105210689889954[74] = 0;
   out_3900105210689889954[75] = 0;
   out_3900105210689889954[76] = 0;
   out_3900105210689889954[77] = 0;
   out_3900105210689889954[78] = 0;
   out_3900105210689889954[79] = 0;
   out_3900105210689889954[80] = 0;
   out_3900105210689889954[81] = 0;
   out_3900105210689889954[82] = 0;
   out_3900105210689889954[83] = 0;
   out_3900105210689889954[84] = 1;
   out_3900105210689889954[85] = dt;
   out_3900105210689889954[86] = 0;
   out_3900105210689889954[87] = 0;
   out_3900105210689889954[88] = 0;
   out_3900105210689889954[89] = 0;
   out_3900105210689889954[90] = 0;
   out_3900105210689889954[91] = 0;
   out_3900105210689889954[92] = 0;
   out_3900105210689889954[93] = 0;
   out_3900105210689889954[94] = 0;
   out_3900105210689889954[95] = 0;
   out_3900105210689889954[96] = 1;
   out_3900105210689889954[97] = 0;
   out_3900105210689889954[98] = 0;
   out_3900105210689889954[99] = 0;
   out_3900105210689889954[100] = 0;
   out_3900105210689889954[101] = 0;
   out_3900105210689889954[102] = 0;
   out_3900105210689889954[103] = 0;
   out_3900105210689889954[104] = 0;
   out_3900105210689889954[105] = 0;
   out_3900105210689889954[106] = 0;
   out_3900105210689889954[107] = 0;
   out_3900105210689889954[108] = 1;
   out_3900105210689889954[109] = 0;
   out_3900105210689889954[110] = 0;
   out_3900105210689889954[111] = 0;
   out_3900105210689889954[112] = 0;
   out_3900105210689889954[113] = 0;
   out_3900105210689889954[114] = 0;
   out_3900105210689889954[115] = 0;
   out_3900105210689889954[116] = 0;
   out_3900105210689889954[117] = 0;
   out_3900105210689889954[118] = 0;
   out_3900105210689889954[119] = 0;
   out_3900105210689889954[120] = 1;
}
void h_6(double *state, double *sat_pos, double *out_1821551638969343814) {
   out_1821551638969343814[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + state[6];
}
void H_6(double *state, double *sat_pos, double *out_3240344798520983452) {
   out_3240344798520983452[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_3240344798520983452[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_3240344798520983452[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_3240344798520983452[3] = 0;
   out_3240344798520983452[4] = 0;
   out_3240344798520983452[5] = 0;
   out_3240344798520983452[6] = 1;
   out_3240344798520983452[7] = 0;
   out_3240344798520983452[8] = 0;
   out_3240344798520983452[9] = 0;
   out_3240344798520983452[10] = 0;
}
void h_20(double *state, double *sat_pos, double *out_2555555902212981732) {
   out_2555555902212981732[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + sat_pos[3]*state[10] + state[6] + state[9];
}
void H_20(double *state, double *sat_pos, double *out_2076278837200806812) {
   out_2076278837200806812[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_2076278837200806812[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_2076278837200806812[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_2076278837200806812[3] = 0;
   out_2076278837200806812[4] = 0;
   out_2076278837200806812[5] = 0;
   out_2076278837200806812[6] = 1;
   out_2076278837200806812[7] = 0;
   out_2076278837200806812[8] = 0;
   out_2076278837200806812[9] = 1;
   out_2076278837200806812[10] = sat_pos[3];
}
void h_7(double *state, double *sat_pos_vel, double *out_1218272769678248077) {
   out_1218272769678248077[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_7(double *state, double *sat_pos_vel, double *out_3936184874712729906) {
   out_3936184874712729906[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_3936184874712729906[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_3936184874712729906[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_3936184874712729906[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_3936184874712729906[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_3936184874712729906[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_3936184874712729906[6] = 0;
   out_3936184874712729906[7] = 1;
   out_3936184874712729906[8] = 0;
   out_3936184874712729906[9] = 0;
   out_3936184874712729906[10] = 0;
}
void h_21(double *state, double *sat_pos_vel, double *out_1218272769678248077) {
   out_1218272769678248077[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_21(double *state, double *sat_pos_vel, double *out_3936184874712729906) {
   out_3936184874712729906[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_3936184874712729906[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_3936184874712729906[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_3936184874712729906[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_3936184874712729906[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_3936184874712729906[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_3936184874712729906[6] = 0;
   out_3936184874712729906[7] = 1;
   out_3936184874712729906[8] = 0;
   out_3936184874712729906[9] = 0;
   out_3936184874712729906[10] = 0;
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

void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_6, H_6, NULL, in_z, in_R, in_ea, MAHA_THRESH_6);
}
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_20, H_20, NULL, in_z, in_R, in_ea, MAHA_THRESH_20);
}
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_7, H_7, NULL, in_z, in_R, in_ea, MAHA_THRESH_7);
}
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_21, H_21, NULL, in_z, in_R, in_ea, MAHA_THRESH_21);
}
void gnss_err_fun(double *nom_x, double *delta_x, double *out_5685586692381648546) {
  err_fun(nom_x, delta_x, out_5685586692381648546);
}
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_961684295642468722) {
  inv_err_fun(nom_x, true_x, out_961684295642468722);
}
void gnss_H_mod_fun(double *state, double *out_3447866398814421424) {
  H_mod_fun(state, out_3447866398814421424);
}
void gnss_f_fun(double *state, double dt, double *out_1737638576013027315) {
  f_fun(state,  dt, out_1737638576013027315);
}
void gnss_F_fun(double *state, double dt, double *out_3900105210689889954) {
  F_fun(state,  dt, out_3900105210689889954);
}
void gnss_h_6(double *state, double *sat_pos, double *out_1821551638969343814) {
  h_6(state, sat_pos, out_1821551638969343814);
}
void gnss_H_6(double *state, double *sat_pos, double *out_3240344798520983452) {
  H_6(state, sat_pos, out_3240344798520983452);
}
void gnss_h_20(double *state, double *sat_pos, double *out_2555555902212981732) {
  h_20(state, sat_pos, out_2555555902212981732);
}
void gnss_H_20(double *state, double *sat_pos, double *out_2076278837200806812) {
  H_20(state, sat_pos, out_2076278837200806812);
}
void gnss_h_7(double *state, double *sat_pos_vel, double *out_1218272769678248077) {
  h_7(state, sat_pos_vel, out_1218272769678248077);
}
void gnss_H_7(double *state, double *sat_pos_vel, double *out_3936184874712729906) {
  H_7(state, sat_pos_vel, out_3936184874712729906);
}
void gnss_h_21(double *state, double *sat_pos_vel, double *out_1218272769678248077) {
  h_21(state, sat_pos_vel, out_1218272769678248077);
}
void gnss_H_21(double *state, double *sat_pos_vel, double *out_3936184874712729906) {
  H_21(state, sat_pos_vel, out_3936184874712729906);
}
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF gnss = {
  .name = "gnss",
  .kinds = { 6, 20, 7, 21 },
  .feature_kinds = {  },
  .f_fun = gnss_f_fun,
  .F_fun = gnss_F_fun,
  .err_fun = gnss_err_fun,
  .inv_err_fun = gnss_inv_err_fun,
  .H_mod_fun = gnss_H_mod_fun,
  .predict = gnss_predict,
  .hs = {
    { 6, gnss_h_6 },
    { 20, gnss_h_20 },
    { 7, gnss_h_7 },
    { 21, gnss_h_21 },
  },
  .Hs = {
    { 6, gnss_H_6 },
    { 20, gnss_H_20 },
    { 7, gnss_H_7 },
    { 21, gnss_H_21 },
  },
  .updates = {
    { 6, gnss_update_6 },
    { 20, gnss_update_20 },
    { 7, gnss_update_7 },
    { 21, gnss_update_21 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_init(gnss);
