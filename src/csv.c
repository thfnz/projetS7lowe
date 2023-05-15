#include "../include/csv.h"

#include <stdio.h>
#include <string.h>

void printcsv(float* T, char* nom, int t_max, float pas){
	// Création du fichier CSV.
	FILE* f = fopen(nom, "w+");
	
	for(int t = 0; t <= (int)(t_max / pas); t++){
		fprintf(f, "%d, %f\n", t, T[t]);
	}

	fclose(f);
}

void nomCsv(float* Tn, int i, int NX){
	// Nomme et lance la création des images individuelles composant les GIF.
	char filename[24] = "./resultats/Tn";
	char indice[6];
	sprintf(indice, "%d", i);
	
	char* csv = ".csv";
	strcat(filename, indice);
	strcat(filename, csv);
	printcsv(Tn, filename, NX - 1, 1);
}
