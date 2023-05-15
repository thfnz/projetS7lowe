#ifndef _LOIS_PHY_H
#define _LOIS_PHY_H

#include "csv.h"

void loiNewton(float Tenv, float* T, float h, int t_max, float pas);
float* loiFourier(int NT, float DT, int NX, float DX, float lambda, float rhocp, float* T_air_metal, float* Tn);

#endif