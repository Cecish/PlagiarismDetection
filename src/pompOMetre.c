/*!
\file pompOMetre.c
\version 1.0
\date 14-06-2014
\brief Contient les fontions et fait les appels pour la méthode du pomp-o-metre
\remarks Aucune
*/

/* Header */
#include "pompOMetre.h"

/*Teste si espace, retour chariot ou tabulation */
int isCaracWhiteSpace(char carac) {
	return ((carac == 32) || (carac==8) || (carac==9));
}

/*Teste si virgule, point virgule, accolade ... et autre caracteres que l'on doit garer tels quels (Voir table ascii) */
int aRecopier (char carac) {
	return (isCaracWhiteSpace(carac) || (carac==59)|| (carac==60) || (carac==61) || (carac==62) || (carac==43) || (carac==45) || (carac==47) || (carac==58) || (carac==123)|| (carac==125) || (carac==124) || (carac==38) || (carac==91) || (carac==93) || (carac==13) || (carac==10) || (carac==40) || (carac==41) || (carac==44));
} 

/* Teste si chiffre, lettre ... et autres caractères que l'on doit remplacer par une seule lettre*/
int aRemplacer(char carac) {
	return (((carac >= 48) && (carac <=57)) || ((carac >= 65) && (carac <=90)) || ((carac >= 97) && (carac <=122)) || (carac==95) || (carac==42) || (carac==34) || (carac==39));
}

/* Remplace tous les mots pas des lettres */
char* remplaceMots(char* str_file) {
	char* str_res;
	char carac;
	int int_taille, dejaDansUnMot;
	int i,j;
	int_taille = strlen(str_file);
	str_res = malloc((int_taille+1)*sizeof(char));
	j = 0;
	dejaDansUnMot = 0;
	for (i = 0 ; i < int_taille ; i++) {
		carac = str_file[i];
		if (aRecopier(carac)) {
			str_res[j] = carac;
			j++;
			dejaDansUnMot = 0;
		} else if (aRemplacer(carac) && !dejaDansUnMot) {
			str_res[j] = 'A';
			j++;
			dejaDansUnMot = 1;
		}		
	}
	str_res = realloc(str_res,sizeof(char)*(j+1));
	str_res[j] = '\0'; /*Terminaison de la chaîne*/ 
	return str_res;
}

/*Détermination de la longueur du bloc  */
int tailleBloc (char* str_fModif, int int_debutBloc, int int_tailleTotale) {
	int int_cptAcco;
	char carac;
	int int_tailleRes;
	int i;

	int_cptAcco = 1;
	int_tailleRes = 0;
	i = int_debutBloc;

	while ((int_cptAcco > 0) && (i < int_tailleTotale)) {
		carac = str_fModif[i];
		int_tailleRes++;

		if (carac == 123) { /* Accolade ouvrante */
			int_cptAcco++;
		} else if (carac == 125) { /* Accolade fermante */
			int_cptAcco--;
		}
			i++;
	}
	return int_tailleRes-1; /* Pour ne pas compter la dernière accolade */
}

/*Création du bloc entre deux points du fichier */
Noeud* creerBloc(Noeud* noeudPtr_blocs, char* str_fModif, int int_debut, int int_taille) {
	int i,j;
	char carac;
	char* str_bloc;

	str_bloc = malloc((abs(int_taille+int_debut) + 1)*sizeof(char));
	j = 0;
	for (i = int_debut ; i < int_taille+int_debut ; i++ ) {
		carac = str_fModif[i];
		str_bloc[j] = carac;
		j++;
	}
	str_bloc[j] = '\0';

	if (noeudPtr_blocs == NULL) {
		noeudPtr_blocs = creerNoeud(str_bloc,NULL,NULL);
	} else {
		noeudPtr_blocs = ajoutTete(noeudPtr_blocs,str_bloc);
	}
	return noeudPtr_blocs;
}

/* Extraction de tous les blocs entre accolades */
Noeud* extraireBlocs(Noeud* noeudPtr_blocs, char* str_fModif) {
	int int_taille;
	int int_tailleBloc;
	int i;
	char carac;

	int_taille = strlen(str_fModif);
	for (i = 0 ; i < int_taille ; i++) {
		carac = str_fModif[i];

		if (carac == 123) { /* Accolade ouvrante */
			int_tailleBloc = tailleBloc(str_fModif,i+1,int_taille);
			noeudPtr_blocs = creerBloc(noeudPtr_blocs,str_fModif,i+1,int_tailleBloc);
		} 
	}
	return noeudPtr_blocs;
} 


/* Appel des opérations pour le pompOMetre */
void mainPompOMetre (char* str_f1, char* str_f2) {
	char* str_f1Modif = NULL;
	char* str_f2Modif = NULL;
	Noeud* noeudPtr_blocs1 = NULL;
	Noeud* noeudPtr_blocs2 = NULL;

	printf("Replacing relevant words with the same letter :");
	str_f1Modif = remplaceMots(str_f1);
	str_f2Modif = remplaceMots(str_f2);

	printf(" words replaced successfully\nExtracting blocks : ");
	noeudPtr_blocs1 = extraireBlocs(noeudPtr_blocs1,str_f1Modif);
	noeudPtr_blocs2 = extraireBlocs(noeudPtr_blocs2,str_f2Modif);
	printf("blocks extracted successfully\n");

	mainTraitementHungarian (noeudPtr_blocs1, noeudPtr_blocs2);


	free(str_f1Modif);
	free(str_f2Modif);
	libererNoeud(noeudPtr_blocs1);
	libererNoeud(noeudPtr_blocs2);
}