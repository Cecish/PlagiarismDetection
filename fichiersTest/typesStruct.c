/*!
\file typesStruct.c
\version 1.0
\date 10-11-2013
\brief Code source pour l'implentation des fonctions sur les structures
\remarks Aucune
*/
#define _GNU_SOURCE 1

#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <string.h>

#include "typesStruct.h"  

/**********************************************************************************/

Info nouvelInfo (char* magicnumber, int colonne, int ligne, int maxi, int** image){
	Info a;
	a.magicnumber = strdup(magicnumber);
	a.colonne = colonne;
	a.ligne = ligne;
	a.image = image;
	a.maxi = maxi;
	return a;
}

Doublet nouveauDoublet (int ligne ,int colonne){
	Doublet a;
	a.colonne = colonne;
	a.ligne = ligne;
	return a;
}

PtsClesCommuns nouveauPtsClesCommuns (NoeudDoublet* listPts1, NoeudDoublet* listPts2, NoeudInt* listNbPtsCommuns) {
	PtsClesCommuns a;
	a.listPts1 = listPts1;
	a.listPts2 = listPts2;
	a.listNbPtsCommuns = listNbPtsCommuns;
	return a;
}

/*Fonctions pour les listes chainées Doublet*/

NoeudDoublet* creerNoeudDoublet(Doublet n, NoeudDoublet* suivant, NoeudDoublet* prec) {
	NoeudDoublet* retour;
	retour=malloc(sizeof(NoeudDoublet));
	if(retour==NULL){
		printf("Problème malloc");
	}
	retour->valeur= n;
	retour->suivant=suivant;
	retour->precedent=prec;
	return retour;
}

void libererNoeudDoublet(NoeudDoublet* noeud){
	if(noeud!=NULL){
		free(noeud);
	}
}


NoeudDoublet* ajoutFinDoublet(NoeudDoublet* teteListe, Doublet n) {
	NoeudDoublet* tmp;
	tmp=teteListe;
	if(tmp!=NULL){
		while(tmp->suivant!=NULL){
			tmp=tmp->suivant;
		}
		tmp->suivant=creerNoeudDoublet(n,NULL,tmp);
	}else{
		teteListe = creerNoeudDoublet(n,NULL,NULL);
	}
	return teteListe;
}

NoeudDoublet* supprTeteDoublet(NoeudDoublet* teteListe) {
	NoeudDoublet* retour;
	if(teteListe!=NULL){
		retour=teteListe->suivant;
		if (retour!=NULL){
			retour->precedent=NULL;	
		}
		libererNoeudDoublet(teteListe);
	}else{
		retour = NULL;
	}
	return retour;
}

/*Fonctions pour les listes chainées Entier*/
NoeudInt* creerNoeudInt(int n, NoeudInt* suivant, NoeudInt* prec) {
	NoeudInt* retour;
	retour=malloc(sizeof(NoeudInt));
	if(retour==NULL){
		printf("Problème malloc");
	}
	retour->valeur=n;
	retour->suivant=suivant;
	retour->precedent=prec;
	return retour;
}

void libererNoeudInt(NoeudInt* noeud){
	if(noeud!=NULL){
		free(noeud);
	}
}

NoeudInt* ajoutFinInt(NoeudInt* teteListe, int n) {
	NoeudInt* tmp;
	tmp=teteListe;
	if(tmp!=NULL){
		while(tmp->suivant!=NULL){
			tmp=tmp->suivant;
		}
		tmp->suivant=creerNoeudInt(n,NULL,tmp);
	}else{
		teteListe = creerNoeudInt(n,NULL,NULL);
	}
	return teteListe;
}

NoeudInt* supprTeteInt(NoeudInt* teteListe) {
	NoeudInt* retour;
	if(teteListe!=NULL){
		retour=teteListe->suivant;
		if (retour!=NULL){
			retour->precedent=NULL;	
		}
		libererNoeudInt(teteListe);
	}else{
		retour = NULL;
	}
	return retour;
}
