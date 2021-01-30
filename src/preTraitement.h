#ifndef __PRETRAITEMENT_H___
	#define __PRETRAITEMENT_H___
/*!
\file preTraitement.h
\version 1.0
\date 10-06-2014
\brief Header pour les pré-traitements
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

/*Librairies pour les chaines */
#include <string.h>
#include <wchar.h>

/*Librairies pour les tests sur les dossiers*/
#include <sys/types.h>
#include <dirent.h>

/*Headers */
#include "gestionOperation.h"

/*!
\fn extractNomFichier(char* str_file, int int_nbFichier, char** strPtr_resBis)
\version 1.0
\brief Extrait le nom du fichier d'un chemin complet (/src/tmp/nomFichier.ext)
\date 10-06-2014
\param str_file le chemin complet du fichier
\param int_nbFichier le numéro à ajouter à la fin du fichier
\param strPtr_resBis le résultat (en sortie)
\remarks Aucune
*/
void extractNomFichier(char* str_file, int int_nbFichier, char** strPtr_resBis);

/*!
\fn construireCheminFichierTmp(char* str_fileName, char** strPtr_fileTmpPath)
\version 1.0
\brief construit le chemin jusqu'au fichier temporaire pour les traitements
\date 10-06-2014
\param str_fileName nom du fichier dont on veut le chemin vers tmp
\param strPtr_fileTmpPath le résultat (en sortie)
\remarks Aucune
*/
void construireCheminFichierTmp(char* str_fileName, char** strPtr_fileTmpPath);

/*!
\fn correctCompilation(char* str_file, char* str_fileName)
\version 1.0
\brief teste si la compilation se fait sans erreurs et envoie les résultats du gcc -E dans un fichier dans un dossier donné, avec uncrustify pour formater le fichier correctement
\date 10-06-2014
\param str_file le chemin complet du fichier
\param str_fileName le nom seul du fichier
\return 0 si faux, un nombre positif si vrai
\remarks Aucune
*/
int correctCompilation(char* str_file, char* str_fileName); 

/*!
\fn appliqueCorrect(char* str_file, char* str_fileName)
\version 1.0
\brief Application de uncrustify sur chaque fichier
\date 10-06-2014
\param str_file le chemin complet du fichier
\param str_fileName le nom seul du fichier
\remarks Écrit le résultat dans le même fichier que le source
*/
void appliqueCorrect(char* str_file, char* str_fileName);

/*!
\fn miseEnMemoireMmap(char* str_fileName, int* statusRes, int* sizeRes, char** f)
\version 1.0
\brief fait toutes les opérations pour la mise en mémoire (open, mmap, close ...)
\date 11-06-14
\param str_fileName le nom du fichier à traiter
\param statusRes le statut résultant de la mise en mémoire (0 si ok) en sortie
\param sizeRes la taille du char* résultant en sortie
\param f le résultat (En sortie)
\remarks Aucune
*/
void miseEnMemoireMmap(char* str_fileName, int* statusRes, int* sizeRes, char** f);

/*!
\fn miseEnMemoireFichiers(char* str_fileName1, char* str_fileName2)
\version 1.0
\brief fait les appels pour la mise en mémoire des fichiers et appelle les opérations suivantes
\date 11-06-14
\param str_fileName1 le chemin du premier fichier temporaire à traiter
\param str_fileName2 le chemin du deuxième fichier temporaire à traiter
\remarks Aucune
*/
void miseEnMemoireFichiers(char* str_fileName1, char* str_fileName2);

/*!
\fn appliqueIndentEtOpSuiv(char* str_fileName1, char* str_fileName2)
\version 1.0
\brief applique le nettoyage du code et appelle les actions suivantes
\date 10-06-2014
\param str_fileName1 le nom du premier fichier
\param str_fileName2 le nom du premier fichier
\remarks Aucune
*/
void appliqueIndentEtOpSuiv(char* str_fileName1, char* str_fileName2);

/*!
\fn mainPreTraitement(char* str_file1, char* str_file2)
\version 1.0
\brief fait les traitements nécessaires avant de commencer à tester les similarités (Nettoyage du code, test si compile ...)
\date 10-06-2014
\param str_file1 le chemin du premier fichier
\param str_file2 le chemin du deuxième fichier
\remarks 
*/
void mainPreTraitement(char* str_file1, char* str_file2);



#endif