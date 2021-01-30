#ifndef __HONGROISEMETHOD_H___
	#define __HONGROISEMETHOD_H___
/*!
\file hongroiseMethod.h
\version 1.0
\date 13-06-2014
\brief Contient les prototypes de toutes les méthodes appelées au sein de la méthode hongroise
\remarks Aucune
*/

/*Librairies de base*/
#include <stdio.h>
#include <stdlib.h>
/*#include <math.h>*/

#include "hungarianAux.h"
#include "types.h"
#include "convolution.h"


/*!
\fn step1HungarianMethod(int** ppint_matMesure, int int_ligne, int int_colonne, int** ppint_matMesure2)
\version 1.0
\brief crée une matrice des distances carrées
\date 15-06-2014
\param ppint_matMesure la matrice des distances
\param int_ligne nombre de lignes
\param int_colonne nombre de colonnes
\param ppint_matMesure2 la matrice d'entiers sur laquelle on travaille
\return une matrice des distances avec l'infini sur les cases ajoutées 
\remarks Aucune
*/
void step1HungarianMethod(int** ppint_matMesure, int int_ligne, int int_colonne, int** ppint_matMesure2);

/*!
\fn step2HungarianMethod(int** ppint_matMesure2, int int_dim)
\version 1.0
\brief Soustrait le minimum de chaque ligne à chaque ligne respectivement
\date 15-06-2014
\param ppint_matMesure2 
\param int_dim la dimension de la matrice
\return une matrice d'entiers modifiée correctement
\remarks Aucune
*/	
void step2HungarianMethod(int** ppint_matMesure2, int int_dim);

/*!
\fn step3HungarianMethod(int** ppint_matMesure2, int int_dim)
\version 1.0
\brief Soustrait le minimum de chaque colonne à chaque colonne respectivement
\date 15-06-2014
\param ppint_matMesure2 
\param int_dim la dimension de la matrice
\return une matrice d'entiers modifiée correctement
\remarks Aucune
*/
void step3HungarianMethod(int** ppint_matMesure2, int int_dim);

/*!
\fn removeLigne0(int** ppint_copy , int indice, int int_dim)
\version 1.0
\brief Enlève tous les 0 d'une ligne
\date 15-06-2014
\param ppint_copy la matrice sur laquelle on agit
\param indice l'indice la ligne à modifier
\param int_dim la dimension de la matrice
\return une matrice sans 0 sur le connée donnée
\remarks Aucune
*/	
int** removeLigne0(int** ppint_copy , int indice, int int_dim);

/*!
\fn removeColonne0(int** ppint_copy , int indice, int int_dim)
\version 1.0
\brief Enlève tous les 0 d'une colonne
\date 15-06-2014
\param ppint_copy la matrice sur laquelle on agit
\param indice l'indice la colonne à modifier
\param int_dim la dimension de la matrice
\return une matrice sans 0 sur la colonne donnée
\remarks Aucune
*/	
int** removeColonne0(int** ppint_copy , int indice , int int_dim);

/*!
\fn sousProcessusMarquage00(int** ppint_copy , int int_dim , int* pint_tabLignes , int* pint_tabColonnes)
\version 1.0
\brief effectue le marquage de la matrice (1 à a place des 0)
\date 15-06-2014	
\param ppint_copy la matrice sur laquelle on agit
\param int_dim la dimension de la matrice
\param pint_tabLignes le tableau du nombre de 0 de chaque ligne
\param pint_tabColonnes le tableau du nombre de 0 de chaque colonne
\return une matrice correctement marquée
\remarks 
*/
int** sousProcessusMarquage00(int** ppint_copy , int int_dim , int* pint_tabLignes , int* pint_tabColonnes);

/*!
\fn sousProcessusMarquage0(int** ppint_copy , int int_dim)
\version 1.0
\brief effectue les opérations pré-requises pour le marquage
\date 15-06-2014
\param ppint_copy la matrice sur laquelle on agit
\param int_dim la dimension de la matrice
\return une matrice d'entiers marquée
\remarks Aucune
*/
int** sousProcessusMarquage0(int** ppint_copy , int int_dim);

/*!
\fn step4HungarianMethod(int** ppint_matMesure2, int int_dim, int** ppint_matCopy)	
\version 1.0
\brief Calcule le nombre minimum de lignes et colonnes pour recouvrir les 0
\date 15-06-2014
\param ppint_matMesure2 la matrice pour laquelle on cherche
\param int_dim la dimension de la matrice 
\param ppint_matCopy la matrice copiée
\return la valeur min pour recouvrir de 0
\remarks Aucune
*/
int step4HungarianMethod(int** ppint_matMesure2, int int_dim, int** ppint_matCopy);

/*!
\fn step5HungarianMethod(int** ppint_matMesure2, int int_dim , int int_compteur, int** ppint_matCopy)	
\version 1.0
\brief Calcule le nombre minimum de lignes et colonnes pour recouvrir les 0
\date 15-06-2014
\param ppint_matMesure2 la matrice pour laquelle on cherche
\param int_dim la dimension de la matrice 
\param int_compteur 
\param ppint_matCopy la matrice copiée
\return la valeur min pour recouvrir de 0
\remarks Aucune
*/
void step5HungarianMethod(int** ppint_matMesure2, int int_dim , int int_compteur, int** ppint_matCopy);

/*!
\fn creationMatriceDistance(int** ppint_matDist, Noeud* noeudPtr_blocs1, Noeud* noeudPtr_blocs2, int int_taille1, int int_taille2)
\version 1.0
\brief Création de la matrice des distances avec la distance de levenshtein
\date 15-06-2014
\param ppint_matDist la matrice résultante
\param noeudPtr_blocs1 les blocs du premier fichier
\param noeudPtr_blocs2 les blocs du deuxième fichier
\param int_taille1 nombre de blocs fichier1
\param int_taille2 nombre de blocs fichier2
\return retourne une matrice d'entier contenant les distances entre chaque bloc
\remarks 
*/
int** creationMatriceDistance(int** ppint_matDist, Noeud* noeudPtr_blocs1, Noeud* noeudPtr_blocs2, int int_taille1, int int_taille2);

/*!
\fn newDim(int int_tailleBloc1, int int_tailleBloc2)
\version 1.0
\brief Retourne la dimension max qui sera la nouvelle dimension des matrices utilisées par la suite
\date 15-06-2014
\param int_tailleBloc1 la taille du bloc 1
\param int_tailleBloc2 la taille du bloc 2
\return un entier 
\remarks 
*/
int newDim(int int_tailleBloc1, int int_tailleBloc2);

/*!
\fn appelStepHongroise (int int_newDim, int int_tailleBloc1, int int_tailleBloc2, int** ppint_matDist)
\version 
\brief Appel de toutes les opérations pour la méthode hongroise et affichage du résultat
\date 15-06-2014
\param int_newDim la dimension des matrices carrées utilisées
\param int_tailleBloc1 la taille du bloc 1 pour la matrice des distances
\param int_tailleBloc2 la taille du bloc 2 pour la matrice des distances
\param ppint_matDist la matrice sur laquelle on agit
\return 
\remarks 
*/
void appelStepHongroise (int int_newDim, int int_tailleBloc1, int int_tailleBloc2, int** ppint_matDist);

/*!
\fn mainTraitementHungarian (Noeud* noeudPtr_blocs1, Noeud* noeudPtr_blocs2)
\version 1.0
\brief appel des diverses fonctions pour la méthode hongroise
\date 15-06-2014
\param noeudPtr_blocs1 la liste chainée des blocs du fichier 1
\param noeudPtr_blocs2 la liste chainée des blocs du fichier 2
\return 
\remarks 
*/
void mainTraitementHungarian (Noeud* noeudPtr_blocs1, Noeud* noeudPtr_blocs2);




#endif
