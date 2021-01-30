#include <stdio.h>
#include <stdlib.h>

/*Headers*/

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

//Coucou test
int
main (int argc, char **argv)
{

  int test=1;

  verifArguments(argc - 1, argv);

  if (test == 1) {
      printf ("Coucou ça marche");
    }
  else
    printf ("Coucou");

  return (0);
}
