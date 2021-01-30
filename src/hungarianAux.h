#ifndef __HUNGARIANAUX_H___
	#define __HUNGARIANAUX_H___
/*!
\file hungarianAux.h
\version 1.0
\date 13-06-2014
\brief Contient les prototypes de toutes les méthodes appelées au sein de la méthode hongroise
\remarks Aucune
*/

/*Librairies de base*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "types.h"

/*Librairies pour l'infini */
#include <limits.h>

/*!
\fn levenshtein(char *s1, char *s2)
\version 1.0
\brief Calcul de la distance de levenshtein entre deux chaines
\date 15-06-2014
\param s1 la première chaine
\param s2 la deuxième chaine
\return un entier correspondant à la distance de levenshtein
\remarks Aucune
*/
int levenshtein(char *s1, char *s2);

/*!
\fn freeMat(int** ppint_mat , int int_ligne , int int_colonne)
\version 1.0
\brief libération mémoire d'une matrice d'entiers
\date 15-06-2014
\param ppint_mat la matrice à libérer
\param int_ligne le nombre de lignes
\param int_colonne le nombre de colonnes
\remarks Aucune
*/
void freeMat(int** ppint_mat , int int_ligne , int int_colonne);


/*!
\fn copyMatrix(int** ppint_matMesure, int** ppint_matMesure2, int int_colonne)
\version 1.0
\brief Copie une matrice carrée
\date 13-06-2014
\param ppint_matMesure matrice carrée à copier
\param ppint_matMesure2 matrice carrée copie
\param int_colonne dimension des matrices carrées
\remarks Aucune
*/
void copyMatrix(int** ppint_matMesure, int** ppint_matMesure2, int int_colonne);

/*!
\fn to_squareLigne(int** ppint_matMesure2, int** ppint_matMesure, int int_ligne, int int_colonne)
\version 1.0
\brief Copie une matrice non carrée (dim ligne > dim colonne) dans une matrice carrée d'ordre dim ligne
\date 13-06-2014
\param ppint_matMesure matrice non carrée à copier
\param ppint_matMesure2 matrice carrée copie
\param int_ligne nombre de ligne (matrice)
\param int_colonne nombre de colonne (matrice)
\remarks Aucune
*/
void to_squareLigne(int** ppint_matMesure2, int** ppint_matMesure, int int_ligne, int int_colonne);

/*!
\fn to_squareColonne(int** ppint_matMesure2, int** ppint_matMesure,  int int_ligne, int int_colonne)
\version 1.0
\brief Copie une matrice non carrée (dim colonne > dim ligne) dans une matrice carrée d'ordre dim colonne
\date 13-06-2014
\param ppint_matMesure matrice non carrée à copier
\param ppint_matMesure2 matrice carrée copie
\param int_ligne nombre de ligne (matrice)
\param int_colonne nombre de colonne (matrice)
\remarks Aucune
*/
void to_squareColonne(int** ppint_matMesure2, int** ppint_matMesure,  int int_ligne, int int_colonne);

/*!
\fn to_square(int** ppint_matMesure2, int** ppint_matMesure, int int_ligne, int int_colonne , int int_posLigneOuColonne)
\version 1.0
\brief Copie une matrice non carrée dans une matrice carrée (carrée au supérieur)
\date 13-06-2014
\param ppint_matMesure2 matrice carrée copie
\param ppint_matMesure matrice non carrée à copier
\param int_ligne nombre de ligne (matrice)
\param int_colonne nombre de colonne (matrice)
\param int_posLigneOuColonne : indicateur de la plus grande dimension (celle des lignes ou des colonnes) de la matrice à copier
\remarks Aucune
*/
void to_square(int** ppint_matMesure2, int** ppint_matMesure, int int_ligne, int int_colonne , int int_posLigneOuColonne);


/*!
\fn chercheMin(int* pint_tab, int int_dim)
\version 1.0
\brief cherche le minimum dans un tableau d'entiers
\date 15-06-2014
\param pint_tab le tableau dans lequel on cherche
\param int_dim la longueur du tableau 
\return le minimum d'un tableau d'entiers
\remarks Aucune
*/
int chercheMin(int* pint_tab, int int_dim);

/*!
\fn chercheMax(int* pint_tab, int int_dim)
\version 1.0
\brief recherche du max dans un tableau 
\date 15-06-2014
\param pint_tab le tableau dans lequel on cherche
\param int_dim la dimension du tableau
\return un couple avec le max et l'indice du max en question
\remarks Aucune
*/
sCouple chercheMax(int* pint_tab, int int_dim);

/*!
\fn soustractionColonne(int** ppint_matMesure2, int int_min, int int_indiceColonne, int int_dim)
\version 1.0
\brief soustrait à la colonne son minimum 
\date 15-06-2014
\param ppint_matMesure2 la matrice sur laquelle on agit
\param int_min le minimum à soustraire
\param int_indiceColonne la colonne sur laquelle on travaille
\param  int_dim la dimension de la matrice
\remarks Aucune
*/
void soustractionColonne(int** ppint_matMesure2, int int_min, int int_indiceColonne, int int_dim);

/*!
\fn existeO(int** ppint_copy, int int_dim)
\version 1.0
\brief détermine s'il existe encore des 0 dans une matrice
\date 15-06-2014
\param ppint_copy la matrice sur laquelle on fait le test
\param int_dim la taille de la matrice
\return 0 si faux, 1 si vrai
\remarks Aucune
*/
int existeO(int** ppint_copy, int int_dim);

/*!
\fn nb0Lignes(int** ppint_matMesure2 , int int_dim , int* pint_tabResLignes)
\version 1.0
\brief compte le nombre de 0 de chaque ligne
\date 15-06-2014
\param ppint_matMesure2 la ligne sur laquelle on fait la recherche
\param int_dim la dimension de la matrice
\param pint_tabResLignes le tableau de lignes que l'on retourne
\return un tableau d'entiers contenant le nombre de 0 de chaque ligne
\remarks Aucune
*/
int* nb0Lignes(int** ppint_matMesure2 , int int_dim , int* pint_tabResLignes);

/*!
\fn nb0Colonnes(int** ppint_matMesure2 , int int_dim , int* pint_tabResColonnes)
\version 1.0
\brief compte le nombre de 0 dans chaque colonne d'une matrice
\date 15-06-2014
\param ppint_matMesure2 la matrice sur laquelle on compte
\param int_dim la dimension de la matrice
\param pint_tabResColonnes le tableau de colonnes que l'on retourne
\return un tableau d'entiers contenant le nombre de 0 de chaque colonne 
\remarks Aucune
*/
int* nb0Colonnes(int** ppint_matMesure2 , int int_dim , int* pint_tabResColonnes);

/*!
\fn compteur0(int* pint_tab , int int_dim)
\version 1.0
\brief Compte le nombre de 0 d'un tableau d'entiers
\date 15-06-2014
\param pint_tab le tableau dans lequel on compte
\param int_dim la taille du tableau
\return un entier correspondant nombre de 0 d'un tableau d'entiers
\remarks Aucune
*/
int compteur0(int* pint_tab , int int_dim);

/*!
\fn smallestEltMatrix(int** ppint_matMesure2 , int int_dim, int** ppint_matCopy)
\version 1.0
\brief trouve le plus petit élément non marqué d'une matrice
\date 15-06-2014
\param ppint_matMesure2 la matrice dans laquelle on cherche
\param int_dim les dimensions de la matrice
\param ppint_matCopy la matrice de marquage
\return le plus petit élément entier non marqué d'une matrice
\remarks Aucune
*/
int smallestEltMatrix(int** ppint_matMesure2 , int int_dim, int** ppint_matCopy);

/*!
\fn substract(int int_smallestElt, int** ppint_matMesure2, int** ppint_matCopy , int int_dim, int int_suppr)
\version 1.0
\brief soustraction de l'élément minimum non marqué à tous les éléments non marqués
\date 15-06-2014
\param int_smallestElt l'élement le plus petit
\param ppint_matMesure2 la matrice sur laquelle on agit
\param ppint_matCopy la matrice de marquage
\param int_dim la dimension de la matrice
\param int_suppr la valeur que l'on elève
\return une matrice d'entiers à laquelle on a soustrait ... (Voir brief)
\remarks Aucune
*/
int** substract(int int_smallestElt, int** ppint_matMesure2, int** ppint_matCopy , int int_dim, int int_suppr);

/*!
\fn add(int** ppint_matMesure2, int** ppint_matCopy, int int_dim, int int_ajout)
\version 1.0
\brief ajout de l'élément minimum non marqué à tous les éléments non marqués
\date 15-06-2014
\param ppint_matMesure2 la matrice sur laquelle on agit
\param ppint_matCopy la matrice de marquage
\param int_dim la dimension de la matrice
\param int_ajout la valeur que l'on ajoute
\return une matrice d'entiers à laquelle on a ajouté ... (Voir brief)
\return 
\remarks 
*/
int** add(int** ppint_matMesure2, int** ppint_matCopy, int int_dim, int int_ajout);

#endif
