// Pour l'instant toute la paroi est une vitre de T homogène = Tréel au centre.
// Métal = thermostat ?

#include "../include/commun.h"
#include "../include/csv.h"
#include "../include/lois_phy.h"

#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{	
	//
	float LONGUEUR = 2.5; // Projection vecteur métal fenêtre sur le sol.
	float HAUTEUR = 2.5; // Projetction vecteur métal fenêtre sur le mur.
	float distanceMetalVitre = pow(pow(LONGUEUR, 2) + pow(HAUTEUR, 2), 0.5);
	float DX = 0.1;
	int NX = distanceMetalVitre / DX;
	float x[NX]; // Grille spatiale
	for(int i = 0; i < NX; i++){
		x[i] = i * NX;
	}

	int T_MAX = 10800; // Durée de l'expérience.
	float DT = 1;
	int NT = T_MAX / DT + 1;

	float LAMBDA_AIR = 0.026; // Fourier
	float RHO_CP_AIR = 1.1 * 1005;
	float H_AIR = 10; // Newton

	float T_METAL_ZERO = 273.15 + 60; // T initiale du métal
	float T_AIR_ZERO = 231.15 + 15; // T initiale de l'air


	//
	float T_air_metal[NT];
	T_air_metal[0] = T_AIR_ZERO;
	loiNewton(T_METAL_ZERO, T_air_metal, H_AIR, T_MAX, DT);

	printcsv(T_air_metal, "./resultats/T_air_metal.csv", T_MAX, DT);
	
	//
	float T_air[NX];
	for(int i = 0; i < NX; i++){
		T_air[i] = T_AIR_ZERO;
	}
	loiFourier(NT, DT, NX, DX, LAMBDA_AIR, RHO_CP_AIR, T_air_metal, T_air);

	return 0;
}