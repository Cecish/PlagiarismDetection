/**
*\file convolution.c
*\author Cécile Riquart
*\version 1
*\date 2014-06-13
*\brief Contient les fonctions pour la convolution
*/

#include "convolution.h"


float calculSimilitude(int** ppint_matConvo, int int_dim) {
	int int_i;
	int int_j;
	int int_temp;
	float res;

	int_temp = 0;
	for (int_i = 0 ; int_i<int_dim ; int_i++) {
  		for (int_j = 0 ; int_j < int_dim ; int_j++) {
  			if (int_i==int_j) {
  				if (ppint_matConvo[int_i][int_j] == 0) {
  					int_temp++;	
  				}	
  			}
  		}
  	}
  	res = ((float) int_temp) / ((float) int_dim);
  	return res*100.0;
}

/* Procédure pour les bords ......................................................................................................... */
void bordMatriceImage(int int_ligne,int int_colonne, int** ppint_mat2 , int** ppint_mat , int** ppint_noyau) {
	int int_i;
	int int_j;

	for (int_i = 0 ; int_i <= int_ligne -1 ; int_i++) {
		for (int_j = 0 ; int_j <= int_colonne - 1 ; int_j++) {
			if ((((int_i == 1)||(int_j == 1))||(int_i == int_ligne - 1))||(int_j == int_colonne - 1)) {
				/* Cas 1.1 : Pour la 1ere ligne */
				if (int_i == 1) {
					/* Le probleme de bordure est géré en assignant des 0 */
					for (int_j = 0 ; int_j <= int_colonne - 1 ; int_j++) {
						ppint_mat2[1][int_j] = 0;
					}
				}
				/* Cas 1.2 : Pour la 1ere colonne */
				if (int_j == 1) {
					/* Le probleme de bordure est géré en assignant des 0 */
					for (int_i = 0 ; int_i <= int_ligne - 1 ; int_i++) {
						ppint_mat2[int_i][1] = 0;
					}
				}
				/* Cas 1.3 : Pour la derniere ligne */
				if (int_i == int_ligne - 1) {
					/* Le probleme de bordure est géré en assignant des 0 */
					for (int_j = 0 ; int_j <= int_colonne - 1 ; int_j++) {
						ppint_mat2[int_ligne - 1][int_j] = 0;
					}
				}
				/* Cas 1.4 : Pour la derniere colonne */
				if (int_j == int_colonne-1) {
					/* Le probleme de bordure est géré en assignant des 0 */
					for (int_i = 0 ; int_i <= int_ligne - 1 ; int_i++) {
						ppint_mat2[int_i][int_colonne - 1] = 0;
					}
				}
			/* Cas 2 : Pour le reste de la matrice : */
			} else {
				for (int_i = 1 ; int_i <= int_ligne - 2 ; int_i++) {
					for (int_j = 1 ; int_j <= int_colonne - 2 ; int_j++) {
						/* On remplit ppint_mat2 avec le resultat du produit de convolution */
						ppint_mat2[int_i][int_j] = ppint_mat[int_i-1][int_j-1]*ppint_noyau[0][0] + ppint_mat[int_i-1][int_j]*ppint_noyau[0][1] + ppint_mat[int_i-1][int_j+1]*ppint_noyau[0][2] + ppint_mat[int_i][int_j-1]*ppint_noyau[1][0] + ppint_mat[int_i][int_j]*ppint_noyau[1][1] + ppint_mat[int_i][int_j+1]*ppint_noyau[1][2] + ppint_mat[int_i+1][int_j-1]*ppint_noyau[2][0] + ppint_mat[int_i+1][int_j]*ppint_noyau[2][1] + ppint_mat[int_i+1][int_j+1]*ppint_noyau[2][2];
					}
				}
			}
		}
	}
}


/* Procédure produit de convolution ................................................................................................. */
int** produitConvolution(int** ppint_mat , int int_ligne , int int_colonne , int** ppint_noyau, int** ppint_mat2) {
	int i;
	ppint_mat2 = malloc (int_ligne*sizeof(int*));
	for (i = 0 ; i < int_ligne ; i++) {
		ppint_mat2[i] = malloc(int_colonne*sizeof(int));
	}

	

	bordMatriceImage(int_ligne,int_colonne, ppint_mat2, ppint_mat , ppint_noyau);

	
	return ppint_mat2;
}




/* Procédure de convolution ......................................................................................................... */
int** convolution(int** ppint_mat, int** ppint_mat2 , int int_ligne, int int_colonne) {
	int i,j;
	int** ppint_noyau = NULL;

	ppint_noyau = malloc (3*sizeof(int*));
	for (i = 0 ; i < 3 ; i++) {
		ppint_noyau[i] = malloc(3*sizeof(int));
	}

	for (i = 0 ; i < 3 ; i++) {
		for (j = 0 ; j < 3 ; j++) {
			if (i==j) {
				ppint_noyau[i][j] = 1;
			} else {
				ppint_noyau[i][j] = 0;
			}
		}
	}

	/* Appel de la procedure produit de convolution */
	ppint_mat2 = produitConvolution(ppint_mat , int_ligne , int_colonne , ppint_noyau, ppint_mat2);
	freeMat(ppint_noyau,3,3);
	return ppint_mat2;
}
