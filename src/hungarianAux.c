/*!
\file hungarianAux.c
\version 1.0
\date 13-06-2014
\brief Code source pour les méthodes auxiliaires appelées au sein de la méthode hongroise
\remarks Aucune
*/

/*Headers */
#include "hungarianAux.h"

/**@def MIN3
	\brief POur le distance de levenshtein
*/
#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))
 
int levenshtein(char *s1, char *s2) {
	unsigned int x, y, s1len, s2len,i;
	unsigned int** matrix;
	s1len = strlen(s1);
	s2len = strlen(s2);

	matrix = malloc((s2len+1)*sizeof(unsigned int*));
	for (i = 0 ; i < s2len+1 ; i++) {
		matrix[i] = malloc((s1len+1)*sizeof(unsigned int));
	}
	matrix[0][0] = 0;
	for (x = 1; x <= s2len; x++) {
		matrix[x][0] = matrix[x-1][0] + 1;
	}
	for (y = 1; y <= s1len; y++) {
		matrix[0][y] = matrix[0][y-1] + 1;
	}
	
	for (x = 1; x <= s2len; x++) {
		for (y = 1; y <= s1len; y++) {
			matrix[x][y] = MIN3(matrix[x-1][y] + 1, matrix[x][y-1] + 1, matrix[x-1][y-1] + (s1[y-1] == s2[x-1] ? 0 : 1));
		}
	}
	return(matrix[s2len][s1len]);
}

/* FreeMat */
void freeMat(int** ppint_mat , int int_ligne , int int_colonne) {
	int int_j;
	
	for (int_j = 0; int_j < int_ligne ; int_j++) {
		free(ppint_mat[int_j]);
	}
	
	free(ppint_mat);
}

/* Copy of a square matrix */
void copyMatrix(int** ppint_matMesure, int** ppint_matMesure2, int int_colonne) {
	int int_i;
	int int_j;
	
	for (int_i = 0;int_i< int_colonne ; int_i++) {
	 	for (int_j = 0;int_j< int_colonne ; int_j++) {
	 		ppint_matMesure2[int_i][int_j] = ppint_matMesure[int_i][int_j];
 		}
	 }
}

/* Transforme un matrice rectangulaire où la dimension des lignes est la plus grande en une matrice carrée */
void to_squareLigne(int** ppint_matMesure2, int** ppint_matMesure, int int_ligne, int int_colonne) {
	int int_i;
	int int_j;
	
	for (int_i = 0;int_i< int_ligne ; int_i++) {
	 	for (int_j = 0;int_j< int_ligne ; int_j++) {
	 		if (int_j < int_colonne) {
	 			ppint_matMesure2[int_i][int_j] = ppint_matMesure[int_i][int_j];
	 		} else {
				ppint_matMesure2[int_i][int_j] = INT_MAX;
 			}
	 	}
	 }
}

/* Transforme un matrice rectangulaire où la dimension des colonnes est la plus grande en une matrice carrée */
void to_squareColonne(int** ppint_matMesure2, int** ppint_matMesure,  int int_ligne, int int_colonne) {
	int int_i;
	int int_j;
	
	for (int_i = 0;int_i< int_colonne ; int_i++) {
	 	for (int_j = 0;int_j< int_colonne ; int_j++) {
	 		if (int_i<int_ligne) {
	 			ppint_matMesure2[int_i][int_j] = ppint_matMesure[int_i][int_j];
	 		} else {
				ppint_matMesure2[int_i][int_j] = INT_MAX;
 			}
	 	}
	 }
}


/* Transforme un matrice rectangulaire en une matrice carrée */
void to_square(int** ppint_matMesure2, int** ppint_matMesure, int int_ligne, int int_colonne , int int_posLigneOuColonne) {

	switch (int_posLigneOuColonne) {
	
	/* int_ligne > int_colonne */
	case 1 :
	 	to_squareLigne(ppint_matMesure2, ppint_matMesure, int_ligne, int_colonne);
	break;
	
	/* int_colonne > int_ligne */
	case 2 :
		to_squareColonne(ppint_matMesure2, ppint_matMesure, int_ligne, int_colonne);
	break;
	
	default : 
	/* Nothing to do */
	break;
	}
}

/* Renvoie le minimum d'un tableau d'entier */	
int chercheMin(int* pint_tab, int int_dim) {
	int int_res = pint_tab[0];
	int int_i;
	
	for (int_i = 1; int_i < int_dim ; int_i++) {
		if (int_res > pint_tab[int_i]) {
			int_res = pint_tab[int_i];
		}
	}
	
	return int_res;
}

/* Renvoie le maximum (et sa position) d'un tableau d'entier */
sCouple chercheMax(int* pint_tab, int int_dim) {
	sCouple sPaire;
	int int_i;
	sPaire.val = pint_tab[0];
	sPaire.indice = 0;

	for (int_i = 1; int_i < int_dim ; int_i++) {
		if (sPaire.val < pint_tab[int_i]) {
			sPaire.val = pint_tab[int_i];
			sPaire.indice = int_i;
		}
	}
	return sPaire;
}

/* Soustraction du minimum de chaque colonne pour chaque colonne */
void soustractionColonne(int** ppint_matMesure2, int int_min, int int_indiceColonne, int int_dim) {
	int int_i;
	int int_j;
	
	for (int_i = 0; int_i < int_dim ; int_i++) {
		for (int_j = 0; int_j < int_dim ; int_j++) {
			if (int_j == int_indiceColonne) {
				ppint_matMesure2[int_i][int_j] -= int_min;
			}
		}
	}
}

/* Déterminer si une matrice carrée contient des 0 */
int existeO(int** ppint_copy, int int_dim) {	
	int i;
	int j;
	int int_zeroExiste;

	int_zeroExiste = int_dim*int_dim;
	for(i=0;i<int_dim;i++){
		for(j=0;j<int_dim;j++){
			if(ppint_copy[i][j]!=0){
				int_zeroExiste--;
			}
		}
	}
	return int_zeroExiste;
}

/* Récupération nb de 0 sur les lignes */
int* nb0Lignes(int** ppint_matMesure2 , int int_dim , int* pint_tabResLignes ) {
	int int_i;
	int int_res0;
	
	for (int_i = 0 ; int_i < int_dim ; int_i++) {
		int_res0 = compteur0(ppint_matMesure2[int_i] , int_dim);
		pint_tabResLignes[int_i] = int_res0;
	}
	return pint_tabResLignes;
}


/* Récupération nb de 0 sur les colonnes */
int* nb0Colonnes(int** ppint_matMesure2 , int int_dim , int* pint_tabResColonnes) {
/*    int int_ligne;*/
    int int_j;
    int int_i;
    int int_res0;
    int* pint_tabTemp;
    
    for (int_i=0 ; int_i<int_dim ; int_i++) {
             pint_tabTemp = malloc((int_dim)*sizeof(int));
     
            if (pint_tabTemp == NULL) {
                  fprintf(stderr,"Impossible allocation");
                 exit(EXIT_FAILURE);
             }
    } /* end alloc */  
    for (int_j = 0 ; int_j < int_dim ; int_j++) {
        for (int_i = 0 ; int_i< int_dim ; int_i++) {
            pint_tabTemp[int_i] = ppint_matMesure2[int_i][int_j];
        }
        int_res0 = compteur0(pint_tabTemp , int_dim);
        pint_tabResColonnes[int_j] = int_res0;
    }
    free (pint_tabTemp);
    return pint_tabResColonnes;
}

/* Compte le nombre de 0 contenus dans un tableau */
int compteur0(int* pint_tab , int int_dim) {
	int int_i;
	int int_cpt = 0;
	
	for (int_i = 0 ; int_i < int_dim ; int_i++) {
		if (pint_tab[int_i] == 0) {
			int_cpt++;
		}
	}
	return int_cpt;
}

/* Détermine le plus petit élément de matMesure2 non marqué */
int smallestEltMatrix(int** ppint_matMesure2 , int int_dim, int** ppint_matCopy) {
	int int_i;
	int int_j;
	int int_min;
	int int_boucleBool;
	int_boucleBool = 1;

	for (int_i = 0 ; int_j < int_dim ; int_i++) {
		for (int_j = 0; int_j < int_dim ; int_j++) {
			if (!((ppint_matCopy[int_i][int_j] == 1)||(int_boucleBool == 0))) {
				int_min = ppint_matMesure2[int_i][int_j];
				int_boucleBool = 0;
			}
		}
	}

	for(int_i=0; int_i < int_dim ; int_i++) {
		for (int_j = 0; int_j < int_dim; int_j++){
			if (!((ppint_matMesure2[int_i][int_j] == -1)||(ppint_matMesure2[int_i][int_j] >= int_min))) {
				int_min = ppint_matMesure2[int_i][int_j];
			}	
		}
	}
	return int_min;
}

int** substract(int int_smallestElt, int** ppint_matMesure2, int** ppint_matCopy , int int_dim, int int_suppr) {
	int int_i;
	int int_j;
	
	for(int_i=0; int_i < int_dim ; int_i++) {
		for (int_j = 0; int_j < int_dim; int_j++) {
			if (ppint_matCopy[int_i][int_j] != -1) {
				ppint_matMesure2[int_i][int_j] -= int_suppr;
				ppint_matCopy[int_i][int_j] -= int_suppr; 
			}
		}
	}
	return ppint_matMesure2;
}

/* add the same elements at the intersection of horizontal and vertical lines */
int** add(int** ppint_matMesure2, int** ppint_matCopy, int int_dim, int int_ajout) {
	int int_i;
	int int_j;
	
	for(int_i=0; int_i < int_dim ; int_i++) {
		for (int_j = 0; int_j < int_dim; int_j++) {
			if (ppint_matCopy[int_i][int_j] == -1) {
				ppint_matMesure2 += int_ajout;
			}
		}
	}
	return ppint_matMesure2;	
}

