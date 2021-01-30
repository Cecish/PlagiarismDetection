/*!
\file main.c
\version 1.0
\date 10-10-2013
\brief Fichier principal du projet 
\remarks Sert juste à appeler la gestion de la ligne de commande
*/

/*Libriaies de bases*/
#include <stdio.h>
#include <stdlib.h>

/*Headers*/
#include "gestionArg.h"

int test() {
	return 4;
}

int main (int argc, char** argv) {
/*	int coucou;*/
/*	*/
/*	int* trou;*/
/*	coucou = test();*/
/*	*/
/*	*trou = 2+3;*/
	

/*	int coucou = test();*/
/*	printf("test");*/

	return (0);

	verifNbArgDeb (argv,argc);
	return(0);
}
