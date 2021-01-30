/*!
\file main.c
\version 1.0
\date 10-06-2014
\brief Fichier principal du projet 
\remarks Aucun
*/

/*Libriaies de bases*/
#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

/*Headers*/
#include "gestionArg.h"

/*!
\fn main (int argc, char** argv)
\version 1.0
\brief Fonction principale	
\date 10-06-2014
\param argc nombre d'arguments
\param argv tableau de chaine des arguments
\return un entier
\remarks Aucune
*/
int main (int argc, char** argv) {
	verifArguments(argc-1,argv);
	return(0);
}