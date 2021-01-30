/**
*\file convolution.h
*\version 1
*\date 2014-06-13
*\brief Contient les headers pour la convolution
*/

#ifndef CONVOLUTION_H
	#define	CONVOLUTION_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

#include "hongroiseMethod.h"
#include "gestionOperation.h"


/*!
\fn bordMatriceImage(int int_ligne,int int_colonne, int** ppint_mat2 , int** ppint_mat , int** ppint_noyau)
\version 1.0
\brief Applique la convolution sur une matrice donnée
\date 15-06-2014
\param ppint_noyau la matrice identité 3x3
\param ppint_mat la matrice sur laquelle on applique la convolution
\param ppint_mat2 la matrice résultat 
\param int_ligne le nombre de lignes
\param int_colonne le nombre de colonnes
\return une matrice convoluée
\remarks 
*/
void bordMatriceImage(int int_ligne,int int_colonne, int** ppint_mat2 , int** ppint_mat , int** ppint_noyau);


/*!
\fn produitConvolution(int** ppint_mat , int int_ligne , int int_colonne , int** ppint_noyau, int** ppint_mat2)
\version 1.0
\brief Applique la convolution sur une matrice donnée
\date 15-06-2014
\param ppint_noyau la matrice identité 3x3
\param ppint_mat la matrice sur laquelle on applique la convolution
\param ppint_mat2 la matrice résultat 
\param int_ligne le nombre de lignes
\param int_colonne le nombre de colonnes
\return une matrice convoluée
\remarks 
*/
int** produitConvolution(int** ppint_mat , int int_ligne , int int_colonne , int** ppint_noyau, int** ppint_mat2);

/*!
\fn convolution(int** ppint_mat, int** ppint_mat2 , int int_ligne, int int_colonne)
\version 1.0
\brief Applique la convolution sur une matrice donnée
\date 15-06-2014
\param ppint_mat la matrice sur laquelle on applique la convolution
\param ppint_mat2 la matrice résultat 
\param int_ligne le nombre de lignes
\param int_colonne le nombre de colonnes
\return une matrice convoluée
\remarks 
*/
int** convolution(int** ppint_mat, int** ppint_mat2 , int int_ligne, int int_colonne); 

/*!
\fn calculSimilitude(int** ppint_matConvo, int int_dim)
\version 1.0
\brief calcul du taux de similitude à partir de la matrice convoluée	
\date 15-06-2014
\param ppint_matConvo la matrice de convolution
\param int_dim la dimension de la matrice de convolution
\return le taux de similitude sous forme de float
\remarks Aucune
*/
float calculSimilitude(int** ppint_matConvo, int int_dim); 


#endif