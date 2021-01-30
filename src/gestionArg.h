#ifndef __GESTIONARG_H___
	#define __GESTIONARG_H___
/*!
\file gestionArg.h
\version 1.0
\date 10-06-2014
\brief Contient les prototypes de toutes les fonctions ayant attrait à la gestion de la ligne de commande
\remarks Aucune
*/

/*Librairies de base*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Librairies pour les chaines */
#include <string.h>
#include <wchar.h>

/*Librairies pour les tests sur les dossiers*/
#include <sys/types.h>
#include <dirent.h>

/*Headers*/
#include "preTraitement.h"

/*!
\fn affHelp(void)
\version 1.0
\brief Affiche l'aide
\date 10-06-2014
\remarks Aucune
*/
void affHelp(void);

/*!
\fn dirExists (char* str_dirName)
\version 1.0
\brief Teste si un dossier existe
\date 10-06-2014
\param str_dirName le nom du dossier à tester
\return 0 si faux, 1 si vrai
\remarks Aucune
*/
int dirExists (char* str_dirName);

/*!
\fn fileExists (char* str_fileName)
\version 1.0
\brief vérifie qu'un fichier existe
\date 10-06-2014
\param str_fileName chaine : nom du fichier à tester
\return 0 si faux, 1 si vrai
\remarks Aucune
*/
int fileExists (char* str_fileName);

/*!
\fn verifFiles(char** strTab_argv)
\version 1.0
\brief Vérification de l'intégrité des fichiers donnés
\date 10-06-2014
\param strTab_argv tableau de chaines des arguments
\remarks Aucune
*/
void verifFiles(char** strTab_argv);

/*!
\fn verifArguments(int int_argc, char** strTab_argv)
\version 1.0
\brief Vérifie l'intégrité des arguments pour l'appel du reste des fonctions
\date 10-06-2014
\param int_argc le nombre d'arguments (-1 pour éviter de compter le ./detectSim)
\param strTab_argv tableau de chaines des arguments
\remarks Aucune
*/
void verifArguments(int int_argc, char** strTab_argv); 

#endif