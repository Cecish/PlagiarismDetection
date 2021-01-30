/*!
\file hongroiseMethod.c
\version 1.0
\date 13-06-2014
\brief Code source pour la méthode hongroise
\remarks Aucune
*/

/*Headers */
#include "hongroiseMethod.h"
#include "gestionOperation.h"



/* Step 1 */
/* add of a dummy row(column) if the cost matrix isn't a square matrix */
void step1HungarianMethod(int** ppint_matMesure, int int_ligne, int int_colonne, int** ppint_matMesure2) {
	if (int_ligne > int_colonne) {
		
		to_square(ppint_matMesure2, ppint_matMesure, int_ligne, int_colonne , 1);
	
	} else {
		if (int_ligne < int_colonne) {
			to_square(ppint_matMesure2, ppint_matMesure ,int_ligne, int_colonne, 2);
		} else {
			copyMatrix(ppint_matMesure,ppint_matMesure2, int_colonne);
		}
	}
}

/* Step 2 */
/* Remove min from each rows */
void step2HungarianMethod(int** ppint_matMesure2, int int_dim) {
	int int_i;
	int int_j;
	int int_min;
	int* pint_tabMin;

	for (int_i=0 ; int_i<int_dim ; int_i++) {
     		pint_tabMin = malloc((int_dim)*sizeof(int));
     
    		if (pint_tabMin == NULL) {
          		fprintf(stderr,"Impossible allocation");
         		exit(EXIT_FAILURE);
     		}
	}
	for (int_i = 0; int_i< int_dim ; int_i++) {
		int_min = chercheMin(ppint_matMesure2[int_i], int_dim);
		pint_tabMin[int_i] = int_min;
	} 
	for (int_i = 0 ; int_i < int_dim ; int_i++) {
		for (int_j = 0 ; int_j < int_dim ; int_j++) {
			ppint_matMesure2[int_i][int_j] -= pint_tabMin[int_i];
		}
	}
	free(pint_tabMin);
}

/* Step 3 */
/* Remove min from each columns */
void step3HungarianMethod(int** ppint_matMesure2, int int_dim) {
	int int_j;
	int int_min;
	int int_ligne;
	int* pint_tab;
	
	for (int_j=0 ; int_j<int_dim ; int_j++) {
     		pint_tab = malloc((int_dim)*sizeof(int));
     
    		 if (pint_tab == NULL) {
          		fprintf(stderr,"Impossible allocation");
         		exit(EXIT_FAILURE);
     		}
	}
	
	for (int_j = 0; int_j < int_dim ; int_j++) {
		int_ligne = 0;
		while (int_ligne<int_dim) {
			pint_tab[int_ligne] = ppint_matMesure2[int_ligne][int_j];
			int_min = chercheMin(pint_tab,int_dim);
			int_ligne++;
		}
		soustractionColonne(ppint_matMesure2, int_min, int_j, int_dim);	
	}
}

/* Step 4 */
int** removeLigne0(int** ppint_copy , int indice, int int_dim) {
	int int_i;
	
	for(int_i = 0;int_i < int_dim;int_i++){
		if (ppint_copy[indice][int_i] == 0) {
			ppint_copy[indice][int_i] = -1;
		}
	
	}
	return ppint_copy;
}

int** removeColonne0(int** ppint_copy , int indice , int int_dim) {
	int int_i;
	
	for(int_i = 0;int_i < int_dim;int_i++){
		if (ppint_copy[int_i][indice] == 0) {
				ppint_copy[int_i][indice] = 1;
		}
	}
	return ppint_copy;
}



int** sousProcessusMarquage00(int** ppint_copy , int int_dim , int* pint_tabLignes , int* pint_tabColonnes) {
	sCouple sPairLignes;
	sCouple sPairColonnes;
	
	sPairLignes = chercheMax(pint_tabLignes, int_dim);
	sPairColonnes = chercheMax(pint_tabColonnes, int_dim);
	
	if (sPairLignes.val < sPairColonnes.val) {
		ppint_copy = removeColonne0(ppint_copy , sPairColonnes.indice , int_dim);
	} else {
		ppint_copy = removeLigne0(ppint_copy , sPairLignes.indice , int_dim);
	}
	
	return ppint_copy;
}

int** sousProcessusMarquage0(int** ppint_copy , int int_dim) {
	int* pint_tabLignes;
	int* pint_tabColonnes;
	int int_i;	
	for (int_i=0 ; int_i<int_dim ; int_i++) {
     		pint_tabLignes = malloc((int_dim)*sizeof(int));
    		if (pint_tabLignes == NULL) {
          		fprintf(stderr,"Impossible allocation");
         		exit(EXIT_FAILURE);
     		}
	}
	for (int_i=0 ; int_i<int_dim ; int_i++) {
     		pint_tabColonnes = malloc((int_dim)*sizeof(int));
    		if (pint_tabColonnes == NULL) {
          		fprintf(stderr,"Impossible allocation");
         		exit(EXIT_FAILURE);
     		}
	}
	pint_tabLignes = nb0Lignes(ppint_copy , int_dim , pint_tabLignes );
	pint_tabColonnes = nb0Colonnes(ppint_copy , int_dim , pint_tabColonnes);
	ppint_copy = sousProcessusMarquage00(ppint_copy , int_dim , pint_tabLignes , pint_tabColonnes);
	free(pint_tabColonnes); 
	free(pint_tabLignes);
	return ppint_copy;
}

int step4HungarianMethod(int** ppint_matMesure2, int int_dim, int** ppint_matCopy) {
	int int_cpt = 0;
	
	/* Allocation of the returned cost matrix */	
	copyMatrix(ppint_matMesure2 , ppint_matCopy , int_dim);
	
	while (existeO(ppint_matCopy , int_dim)) {
		int_cpt++;
		ppint_matCopy = sousProcessusMarquage0(ppint_matCopy , int_dim);
	}
	return (int_cpt);	
}

/* Step 5 */
void step5HungarianMethod(int** ppint_matMesure2, int int_dim , int int_compteur, int** ppint_matCopy) {
	int int_smallestElt;
	
	if (int_compteur == int_dim) {
		printf("Terminé\n");
	} else {
		int_smallestElt = smallestEltMatrix(ppint_matMesure2 , int_dim, ppint_matCopy);
		ppint_matMesure2 = substract(int_smallestElt, ppint_matMesure2, ppint_matCopy , int_dim, int_smallestElt);
		ppint_matMesure2 = add(ppint_matMesure2, ppint_matCopy, int_dim, int_smallestElt);
	}
} 

/* Création de la matrice des distances */
int** creationMatriceDistance(int** ppint_matDist, Noeud* noeudPtr_blocs1, Noeud* noeudPtr_blocs2, int int_taille1, int int_taille2) {
	int i,j;
	ppint_matDist = malloc(int_taille1*sizeof(int*));
	for (i = 0; i < int_taille1; i++) {
	 	ppint_matDist[i] = malloc(int_taille2*sizeof(int));
	} 
	i = 0;
	while (noeudPtr_blocs1 != NULL) {
		j = 0;
		while (noeudPtr_blocs2 -> suivant != NULL) {
			ppint_matDist[i][j] = levenshtein((char*) noeudPtr_blocs1->valeur, (char*) noeudPtr_blocs2->valeur);
			j++;
			noeudPtr_blocs2 = noeudPtr_blocs2->suivant;
			if (noeudPtr_blocs2 -> suivant == NULL) {
				ppint_matDist[i][j] = levenshtein((char*) noeudPtr_blocs1->valeur, (char*) noeudPtr_blocs2->valeur);
			}
		}
		while (noeudPtr_blocs2->precedent != NULL) {
			noeudPtr_blocs2 = noeudPtr_blocs2->precedent;
		}
		i++;
		noeudPtr_blocs1 = noeudPtr_blocs1->suivant;
	}
	return ppint_matDist;
}

int newDim(int int_tailleBloc1, int int_tailleBloc2) {
	int res;
	if (int_tailleBloc1 >= int_tailleBloc2) {
		res = int_tailleBloc1;
	} else {
		res = int_tailleBloc2;
	} 
	return res;
}

/* Appel étapes méthode hongroise*/
void appelStepHongroise (int int_newDim, int int_tailleBloc1, int int_tailleBloc2, int** ppint_matDist) {
	int i;
	int int_compteur;
	int** ppint_matCopy = NULL;
	int** ppint_matDist2 = NULL;
	int** ppint_matConvo = NULL;

	ppint_matDist2 = malloc(int_newDim*sizeof(int*));
	for (i = 0 ; i < int_newDim ; i++) {
		ppint_matDist2[i] = malloc(int_newDim*sizeof(int));
	}

	step1HungarianMethod(ppint_matDist, int_tailleBloc1, int_tailleBloc2, ppint_matDist2);
	step2HungarianMethod(ppint_matDist2, int_newDim);
	step3HungarianMethod(ppint_matDist2, int_newDim);
	ppint_matCopy = malloc((int_newDim)*sizeof(int*));
	for (i=0 ; i<int_newDim ; i++) {
     		ppint_matCopy[i] = malloc((int_newDim)*sizeof(int));
    }

	int_compteur = step4HungarianMethod(ppint_matDist2, int_newDim, ppint_matCopy);
	step5HungarianMethod(ppint_matDist2, int_newDim , int_compteur, ppint_matCopy);
	ppint_matConvo = convolution (ppint_matDist2,ppint_matConvo,int_newDim,int_newDim);
	printf("Similarity rate result  : %f %%\n",calculSimilitude(ppint_matConvo, int_newDim));
}

/* Main traitements méthode hongroise */
void mainTraitementHungarian (Noeud* noeudPtr_blocs1, Noeud* noeudPtr_blocs2) {
	int int_tailleBloc1;
	int int_tailleBloc2;
	int int_newDim;
	int** ppint_matDist = NULL;

	int_tailleBloc1 = taille(noeudPtr_blocs1)+1;
	int_tailleBloc2 = taille(noeudPtr_blocs2)+1;

	printf("Generating distances matrix with levenshtein distance\n");
	printf("\nCalulating similarity rate with hungarian method (Please wait)\n");
	ppint_matDist = creationMatriceDistance(ppint_matDist,noeudPtr_blocs1,noeudPtr_blocs2,int_tailleBloc1,int_tailleBloc2);

	int_newDim = newDim(int_tailleBloc1,int_tailleBloc2);
	
	appelStepHongroise(int_newDim,int_tailleBloc1,int_tailleBloc2,ppint_matDist);
	freeMat(ppint_matDist,int_tailleBloc1,int_tailleBloc2);
}

