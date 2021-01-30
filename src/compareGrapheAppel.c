/*!
\file gestionArg.c
\version 1.0
\date 10-06-2014
\brief Code compare deux matrices
\remarks Aucune
*/

#include "compareGrapheAppel.h"

int valeurAbsolue(int int_nombre){
	int int_abs;
	if(int_nombre < 0){
		int_abs = -(int_nombre);
	}
	if(int_nombre >= 0){
		int_abs = int_nombre;
	}
	return int_abs;
}

int superieur(int int_nombre1 , int int_nombre2){
	int int_res;
	if(int_nombre1 >= int_nombre2){
		int_res = int_nombre1;
	}
	if(int_nombre1 < int_nombre2){
		int_res = int_nombre2;
	}
	return int_res;
}

 int maximum (int* intTab_tableau , int int_taille){
	 int int_i = 1;
	 int int_max = intTab_tableau[0];
	 while (int_i < int_taille){
	 	if (intTab_tableau[int_i] >= int_max)
	 	int_max = intTab_tableau[int_i] ;
	 	int_i++;
		}
	 return int_max;
}

int** extendMatrice(int** intTab_mat, int int_taille1, int int_taille2) {
	int int_i;
	int int_j;
	int** intTab_res;
	intTab_res = malloc(superieur(int_taille1,int_taille2) * sizeof(int*));
	for(int_i = 0 ; int_i < superieur(int_taille1,int_taille2) ; int_i++){
		intTab_res[int_i] = malloc(superieur(int_taille1,int_taille2) * sizeof(int));
	}

	for(int_i = 0 ; int_i < int_taille1 ; int_i++) {
		for(int_j = 0 ; int_j < int_taille1 ; int_j++){
			intTab_res[int_i][int_j]= intTab_mat[int_i][int_j] ;
	 	}
	}

	for(int_i = int_taille1 ; int_i < superieur(int_taille1,int_taille2) ; int_i++){
		for(int_j = int_taille1 ; int_j < superieur(int_taille1,int_taille2) ; int_j++){
			intTab_res[int_i][int_j] = 0 ;
 		}
	}
		
	return intTab_res;
}

void verifierTaille(int** intTab_A , int** intTab_B , int int_tailleA , int int_tailleB , int*** intTab_res ){
	int int_j, int_i;
	
	if(int_tailleA > int_tailleB){
		*intTab_res = extendMatrice(intTab_B,int_tailleB,int_tailleA);
	} else if(int_tailleA < int_tailleB){
		*intTab_res = extendMatrice(intTab_A,int_tailleA,int_tailleB);
	} else if(int_tailleA == int_tailleB){
		for(int_i = 0 ; int_i < superieur(int_tailleA,int_tailleB) ; int_i++){
			for(int_j = 0 ; int_j < superieur(int_tailleA,int_tailleB) ; int_j++){
				*intTab_res[int_i][int_j] = 0;
			}
		}
	}
	int_tailleA = int_tailleB; 
}

int** doCalcMatrice(int** intTab_A , int** intTab_B , int int_tailleA, int int_tailleB, int int_taille, int*** intTab_res) {
	int int_i, int_j;
	if(int_tailleA == int_tailleB){
		for(int_i = 0 ; int_i < int_taille ; int_i++){
			for(int_j = 0 ; int_j < int_taille ; int_j++){
				(*intTab_res)[int_i][int_j] = intTab_A[int_i][int_j] - intTab_B[int_i][int_j];
			} 
		}
	} else if(int_tailleA > int_tailleB){
		verifierTaille(intTab_A , intTab_B , int_tailleA , int_tailleB , intTab_res );
		for(int_i = 0 ; int_i < int_taille ; int_i++){
			for(int_j = 0 ; int_j < int_taille ; int_j++){
				(*intTab_res)[int_i][int_j] = (*intTab_res)[int_i][int_j] - intTab_A[int_i][int_j];
			}
		}
	} else if(int_tailleA < int_tailleB){
		verifierTaille(intTab_A , intTab_B , int_tailleA , int_tailleB , intTab_res);	
		for(int_i = 0 ; int_i < int_taille ; int_i++){
			for(int_j = 0 ; int_j < int_taille ; int_j++){
				(*intTab_res)[int_i][int_j] = (*intTab_res)[int_i][int_j] - intTab_B[int_i][int_j];
			}
		}
	}
	return *intTab_res;
}


void differenceMatrice(int** intTab_A , int** intTab_B , int int_tailleA , int int_tailleB , int*** intTab_res) {
	int int_taille;
	int int_i;
	int_taille = superieur(int_tailleA,int_tailleB);
	
	*intTab_res = malloc(int_taille * sizeof(int*));
	for(int_i = 0 ; int_i < int_taille ; int_i++){
		(*intTab_res)[int_i] = malloc(int_taille * sizeof(int));
	}

	*intTab_res = doCalcMatrice( intTab_A ,intTab_B , int_tailleA , int_tailleB, int_taille, intTab_res);
}



int normeMatricielle(int** intTab_M , int int_taille ){
	int int_i;
	int int_j;
	int* intTab_ligne;
	intTab_ligne = calloc(int_taille , sizeof(int));
	int_i = 0;
	int_j = 0;
	for(int_i = 0 ; int_i < int_taille ; int_i++){
		for(int_j = 0 ; int_j < int_taille ; int_j++){
			intTab_ligne[int_i] = valeurAbsolue(intTab_M[int_i][int_j]) + intTab_ligne[int_i];
		}
	}
	return (maximum(intTab_ligne , int_taille));
} 

void compareGrapheAppel(int** intTab_A , int** intTab_B , int int_tailleA , int int_tailleB , int int_distanceMax){		
	int int_norme;
	int int_i;
	int int_taille;
	float double_taux;
	int** intTab_res;

	int_taille = superieur(int_tailleA,int_tailleB);
	intTab_res = malloc(int_taille * sizeof(int*));
	for(int_i = 0 ; int_i < int_taille ; int_i++){
		intTab_res[int_i] = malloc(int_taille * sizeof(int)); 
	}
	differenceMatrice(intTab_A , intTab_B , int_tailleA , int_tailleB , &intTab_res);
	int_norme = normeMatricielle(intTab_res , int_taille);


	double_taux = (1.0 - ((1.0 * int_norme)/(1.0 * int_distanceMax))) * 100.0 ;	
	for(int_i = 0 ; int_i < int_taille ; int_i++){
			free(intTab_res[int_i]);
	}
	free(intTab_res);
	printf("\nCalculating similarity rate with function calls graph method : \n");
	printf("Similarity rate result is %f %%\t (norm = %d)\n", double_taux,int_norme);
}














