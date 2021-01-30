#ifndef __GESTIONOPERATION_H___
	#define __GESTIONOPERATION_H___
/*!
\file gestionOperation.h
\version 1.0
\date 10-06-2014
\brief Header pour les opérations
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

/*Librairies pour les chaines */
#include <string.h>
#include <wchar.h>

/*Librairies pour les tests sur les dossiers*/
#include <sys/types.h>
#include <dirent.h>

/*Headers */
#include "compareGrapheAppel.h"
#include "pompOMetre.h"

/*!
\fn afficherMatriceIntCarree(int** matrice, int taille)
\version 1.0
\brief Affiche une matrice carrée
\date 13-06-2014
\param matrice la matrice à afficher
\param taille la taille de la matrice
\remarks Aucune 
*/
void afficherMatriceIntCarree(int** matrice, int taille);

/*!
\fn afficherHashTable(GHashTable* hashTable)
\version 1.0
\brief affichage des valeurs de la hashtable
\date 13-06-2014
\param hashTable la GHashTable à afficher
\remarks Aucune
*/
void afficherHashTable(GHashTable* hashTable);

/*!
\fn compteNombreFonctions(char* f, GHashTable* hashTable, int* int_nbFonctions)
\version 1.0
\brief compte le nombre de fonctions et les donne dans un char**
\date 12-06-2014
\param f la chaine du fichier
\param hashTable la hashTable à générer
\param int_nbFonctions le nombre de fonctions du fichier (Sans doublons, en sortie)
\return un tableau de chaines contenant toutes les fonctions (Pas de doublons, hashtable power)
\remarks Aucune
*/
GHashTable* compteNombreFonctions(char* f, GHashTable* hashTable, int* int_nbFonctions);

/*!
\fn creerGrapheAppel(char* f, int int_nbFonctions, GHashTable* hashTable, int** grapheAppel)
\version 1.0
\brief crée le graphe d'appel des fonctions
\date 13-06-2014
\param f le fichier qu'on teste
\param int_nbFonctions le nombre de fonctions sans doublons du fichier
\param hashTable la hashTable contenant les fonctions avec leur futur indice dans le graphe 
\param grapheAppel le graphe résultant en sortie
\return le graphe d'appel des fonctions sous forme de int**
\remarks Aucune
*/	
int** creerGrapheAppel(char* f, int int_nbFonctions, GHashTable* hashTable, int** grapheAppel);

/*!
\fn creationGrapheFonction(char* f, int* int_nbFonctions, int** grapheAppel)
\version 1.0
\brief créer le graphe d'appel des fonctions
\date 12-06-2014	
\param f la chaine du fichier
\param int_nbFonctions nombre de fonctions du fichier (Doublons non comptés)
\param grapheAppel le graphe d'appel des fonctions (en sortie)
\return le graphe d'appel des fonctions
\remarks Aucune
*/
int** creationGrapheFonction(char* f, int* int_nbFonctions, int** grapheAppel);

/*!
\fn gestionGraphesFonctions (char* str_f1, char* str_f2)
\version 1.0
\brief gère les appels pour la constructions des graphes d'appel de fonctions
\date 13-06-2014
\param str_f1 la chaine du premier fichier
\param str_f2 la chaine du deuxième fichier
\remarks Aucune
*/
void gestionGraphesFonctions (char* str_f1, char* str_f2);

/*!
\fn mainTraitementFichiersMem(char* str_f1, char* str_f2)
\version 1.0
\brief appelle des traitements
\date 11-06-14
\param str_f1 la première chaine contenant le fichier 1
\param str_f2  la deuxième chaine contenant le fichier 2
\remarks Aucune
*/
void mainTraitementFichiersMem(char* str_f1, char* str_f2);





#endif