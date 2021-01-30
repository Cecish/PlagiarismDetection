#ifndef __COMPAREGRAPHEAPPEL_H___
	#define __COMPAREGRAPHEAPPEL_H___

/*!
\file compareGrapheAppel.h
\version 1.0
\date 10-06-2014
\brief Code compare deux matrices
\remarks Aucune
*/

/*Librairies de base*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "gestionOperation.h"

/*!
\fn superieur (int int_nombre1 , int int_nombre2)
\version 1.0
\brief retourne le plus grand des deux nombres passés en paramètre
\date 10-06-2014
\param int_nombre1 le premier nombre à tester
\param int_nombre2 le deuxième nombre à tester
\return le plus grand des deux
\remarks Aucune
*/
int superieur(int int_nombre1 , int int_nombre2);

/*!
\fn valeurAbsolue(int int_nombre)
\version 1.0
\brief retourne la valeur absolue du nombre passé en paramètre
\date 10-06-2014
\param int_nombre le nombre dont on veut la valeur absolue
\return la valeur absolue
\remarks Aucune
*/
int valeurAbsolue(int int_nombre);

/*!
\fn maximum (int* intTab_tableau , int int_taille)
\version 1.0
\brief retourne la valeur maximum contenue dans un tableau
\date 10-06-2014
\param intTab_tableau le tableau dans lequel on cherche
\param int_taille la taille du tableau
\return le maximium du tableau
\remarks Aucune
*/
int maximum (int* intTab_tableau , int int_taille);

/*!
\fn extendMatrice(int** intTab_mat, int int_taille1, int int_taille2)
\version 1.0
\brief agrandit la matrice la plus petit pour la soustraction	
\date 13-06-2014
\param intTab_mat la matrice à agrandir 
\param int_taille1 la taille de la première matrice
\param int_taille2 la taille de la deuxième matrice
\return la matrice agrandie
\remarks 
*/
int** extendMatrice(int** intTab_mat, int int_taille1, int int_taille2);

/*!
\fn verifierTaille(int** intTab_A , int** intTab_B , int int_tailleA , int int_tailleB , int*** intTab_res )
\version 1.0
\brief gère les comparaisons entre les tailles des fichiers
\date 10-06-2014
\param intTab_A la matrice du fichier 1
\param intTab_B la matrice du fichier 2
\param int_tailleA nombre fonctions du fichier1  
\param int_tailleB nombre fonctions du fichier1
\param intTab_res la matrice résultant des opérations
\remarks Aucune
*/
void verifierTaille(int** intTab_A , int** intTab_B , int int_tailleA , int int_tailleB , int*** intTab_res );


/*!
\fn doCalcMatrice(int** intTab_A , int** intTab_B , int int_tailleA, int int_tailleB, int int_taille, int*** intTab_res)
\version 1.0
\brief Effectue les calculs nécessaires sur la matrice
\date 13-06-2014
\param intTab_A la matrice du fichier 1
\param intTab_B la matrice du fichier 2
\param int_tailleA nombre fonctions du fichier1  
\param int_tailleB nombre fonctions du fichier1
\param int_taille la taille maximale
\param intTab_res la matrice résultant des opérations
\return la matrice après les calculs
\remarks Aucune
*/
int** doCalcMatrice(int** intTab_A , int** intTab_B , int int_tailleA, int int_tailleB, int int_taille, int*** intTab_res);


/*!
\fn differenceMatrice(int** intTab_A , int** intTab_B , int int_tailleA , int int_tailleB , int*** pointeurTab_res)
\version 1.0
\brief calcule la soustraction de deux matrices de même dimensions
\date 10-06-2014
\param intTab_A la matrice du fichier 1
\param intTab_B la matrice du fichier 2
\param int_tailleA nombre fonctions du fichier1  
\param int_tailleB nombre fonctions du fichier2
\param intTab_res le résultat de la différence
\remarks Aucune
*/
void differenceMatrice(int** intTab_A , int** intTab_B, int int_tailleA , int int_tailleB , int*** intTab_res); 

/*!
\fn normeMatricielle(int** intTab_M , int int_taille )
\version 1.0
\brief calcule la norme d'une matrice
\date 10-06-2014
\remarks Aucune
*/
int normeMatricielle(int** intTab_M , int int_taille );

/*!
\fn compareGrapheAppel(int** intTab_A , int** intTab_B , int int_tailleA , int int_tailleB , int int_distanceMax)
\version 1.0
\brief compare deux matrices
\date 10-06-2014
\param intTab_A la matrice du fichier 1
\param intTab_B la matrice du fichier 2
\param int_tailleA nombre fonctions du fichier1  
\param int_tailleB nombre fonctions du fichier2
\param int_distanceMax la distance maximale 
\remarks Aucune
*/
void compareGrapheAppel(int** intTab_A , int** intTab_B , int int_tailleA , int int_tailleB , int int_distanceMax);

#endif