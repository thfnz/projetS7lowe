#include "../include/lois_phy.h"

#include <math.h>
#include <stdio.h>

void loiNewton(float Tenv, float* T, float h, int t_max, float pas){
	for(int t = 1; t <= (int)(t_max / pas); t++){
		T[t] = Tenv + (T[0] - Tenv) * exp(-1 * h * t * pas);
	}
}

float* loiFourier(int NT, float DT, int NX, float DX, float lambda, float rhocp, float* T_air_metal, float* Tn){
	// Méthode des différences finies.
	float TnMoinsUn[NX];
	
	for(int t = 0; t < NT; t++){
		// Copie
		for(int i = 0; i < NX; i++){
			TnMoinsUn[i] = Tn[i];
		}

		// Calcul de dT/dt = (lambda / rho*Cp) * d2T/dx2.
		for(int i = 1; i < NX - 1; i++){ // ! Conditions initiales.
			Tn[i] = TnMoinsUn[i] + DT * (lambda / rhocp) * (Tn[i + 1] - 2 * Tn[i] + Tn[i - 1]) / (DX * DX);// Tn+1 = Tn + dt * (lambda / rho*Cp) * (Tn[i+1] - 2Tn[i] + Tn[i - 1]) / dx^2 (Taylor)
		}

		// Conditions limites. T_vitre ?
		Tn[0] = T_air_metal[t];
		nomCsv(Tn, t, NX);
	}

	for(int t = 0; t < NT; t++){
		
	}
	return Tn;
}