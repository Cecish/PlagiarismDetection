#ifndef __POMPOMETRE_H___
	#define __POMPOMETRE_H___
/*!
\file gestionOperation.h
\version 1.0
\date 14-06-2014
\brief Header pour le pomp-o-metre
\remarks Aucune
*/

/*Librairies de base*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/io.h>
#include <sys/stat.h>
#include <glib.h>
#include <math.h>

/*Librairies pour les chaines */
#include <string.h>
#include <wchar.h>

/*Librairies pour les tests sur les dossiers*/
#include <sys/types.h>
#include <dirent.h>

/* Headers */
#include "types.h"
#include "hongroiseMethod.h"

/*!
\fn creerBloc(Noeud* noeudPtr_blocs, char* str_fModif, int int_debut, int int_fin)
\version 1.0
\brief Création d'un bloc et ajout bloc à bloc
\date  15-06-2014
\param noeudPtr_blocs la liste chainée à modifier
\param str_fModif la chaine à laquelle on doit retirer les blocs
\param int_debut le début du bloc dans la chaine donnée
\param int_fin la fin du bloc dans la chaine donnée
\return le bloc crée ou auquel on a ajouté le bloc souhaité
\remarks Aucune
*/		
Noeud* creerBloc(Noeud* noeudPtr_blocs, char* str_fModif, int int_debut, int int_fin);

/*!
\fn tailleBloc (char* str_fModif, int int_debutBloc, int int_tailleTotale)
\version 1.0
\brief calcule la taille du prochain bloc
\date 15-06-2014
\param str_fModif la chaine sur laquelle on travaille
\param int_debutBloc le début du bloc à considérer
\param int_tailleTotale la taille totale de la chaine pour ne pas dépasser si erreur quelconque
\return un entier qui correspond à la taille du prochain bloc
\remarks Aucune
*/
int tailleBloc (char* str_fModif, int int_debutBloc, int int_tailleTotale); 

/*!
\fn extraireBlocs(Noeud* noeudPtr_blocs, char* str_fModif)
\version 1.0
\brief Extraction de tous les blocs du fichier
\date 15-06-2014
\param noeudPtr_blocs la liste de noeud de char*
\param str_fModif la chaine représentant le fichier
\return un noeud contenant tous les blocs
\remarks Aucune
*/
Noeud* extraireBlocs(Noeud* noeudPtr_blocs, char* str_fModif);

/*!
\fn isCaracWhiteSpace(char carac)
\version 1.0
\brief teste si la caractère en paramètre est un whitespace quelconque (espace, tabulation, retour chariot ...)
\date 15-06-2014
\param carac le caractère à tester	 
\return 0 si faux, 1 si vrai
\remarks Aucune
*/
int isCaracWhiteSpace(char carac); 

/*!
\fn aRecopier (char carac)
\version 1.0
\brief teste si la caractère en paramètre est un caractère que l'on doit recopier tel quel (accolade, egal, parenthèse ...)
\date 15-06-2014
\param carac le caractère à tester	 
\return 0 si faux, 1 si vrai
\remarks Aucune
*/
int aRecopier (char carac);

/*!
\fn aRemplacer(char carac)
\version 1.0
\brief teste si la caractère en paramètre est un caractère à remplacer par un 'A' (appel fonction ...) 
\date 15-06-2014
\param carac le caractère à tester	 
\return 0 si faux, 1 si vrai
\remarks Aucune
*/
int aRemplacer(char carac);


/*!
\fn remplaceMots(char* str_file)
\version 1.0
\brief remplace les mots par des 'A' dans la chaine du fichier et laisse les caractères nécessaires 
\date 15-06-2014
\param str_file la chaine sur laquelle on effectue le remplacement	
\return une chaine sur laquelle on a effectué le remplacement 
\remarks Aucune
*/
char* remplaceMots(char* str_file);

/*!
\fn mainPompOMetre (char* f1, char* f2)
\version 1.0
\brief Fait les appels pour la méthode du pomp-o-metre	
\date 15-06-2014	
\param f1 le premier fichier
\param f2 le deuxième fichier
\remarks Aucune
*/
void mainPompOMetre (char* f1, char* f2);



#endif