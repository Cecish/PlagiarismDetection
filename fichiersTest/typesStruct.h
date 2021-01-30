#ifndef __TYPESTRUCT_H___
	#define __TYPESTRUCT_H___
/*!
\file typesStruct.h
\version 1.0
\date 10-10-2013
\brief Contient les prototypes des types structurés utilés dans le projet
\remarks Aucune
*/

/*!
\struct Info
\version 1.0
\brief Permets de définir la structure Info ainsi que ses composantes 
\date 05-10-2013
\remarks Aucune
*/
#ifndef _INFO
typedef struct {
	char* magicnumber;
	int colonne;
	int ligne;
	int maxi;
	int** image;
}Info;
#define _INFO
#endif

/*!
\struct Doublet
\version 1.0
\brief Permets de définir la structure Doublet et ses composantes
\date 05-10-2013
\remarks Aucune
*/
#ifndef _DOUBLET
typedef struct {
	int ligne;
	int colonne;
}Doublet;
#define _DOUBLET
#endif

/*!
\struct NoeudDoublet
\version 1.0
\brief Permets de définir la structure NoeudDoublet et ses composantes, pour créer des listes chainees de doublets
\date 05-10-2013
\remarks Aucune
*/
#ifndef _NOEUDDOUBLET
typedef struct NoeudDoublet{
	Doublet valeur;
	struct NoeudDoublet* suivant;
	struct NoeudDoublet* precedent;
} NoeudDoublet;
#define _NOEUDDOUBLET
#endif

/*!
\struct NoeudInt 
\version 1.0
\brief Permets de définir la structure NoeudInt et ses composantes, pour créer des listes chainees d'entiers
\date 05-10-2013
\remarks Aucune
*/
#ifndef _NOEUDINT
typedef struct NoeudInt{
	int valeur;
	struct NoeudInt* suivant;
	struct NoeudInt* precedent;
} NoeudInt;
#define _NOEUDINT
#endif

/*!
\struct PtsClesCommuns
\version 1.0
\brief Permets de définir la structure PtsClesCommuns et ses composantes, pour renvoyer la liste de points clés communs, le nombre de correspondances ...
\date 05-10-2013
\remarks Aucune
*/
#ifndef _PTSCLESCOMMUNS
typedef struct {
	NoeudDoublet* listPts1; /* Liste des points clés de l'image 1 */
	NoeudDoublet* listPts2; /* Pts clés en correspondance avec chaque point image 2*/
	NoeudInt* listNbPtsCommuns; /* Nombre de correspondances pour chaque point clé */
}PtsClesCommuns;
#define _PTSCLESCOMMUNS
#endif



/**********************************************************************************/

/*!
\fn nouvelInfo (char* magicnumber, int colonne, int ligne, int maxi, unsigned int** image)
\version 1.0
\brief Permets de créer les composantes de l'image que l'on va mettre en mémoire
\param magicnumber Nombre magic qui correspond à un type d'image différent
\param colonne Nombre de colonne cad la largeur de l'image
\param ligne Nombre de ligne cad la hauteur de l'image
\param image Tableau d'entier qui correspond à l'image en ascii
\date 05-10-2013
\return a structure de type info qui contient toutes les informations pour mettre en mémoire l'image
\remarks Aucune
*/
Info nouvelInfo (char* magicnumber, int colonne, int ligne, int maxi, int** image);

/*!
\fn nouveau (int ligne, int colonne)
\version 1.0
\brief Permets de créer les composantes de coordonnées
\param ligne Numéro de la ligne du point
\param colonne Numéro de la colonne du point
\date 13-12-2013
\return a structure de type doublet qui contient les coordonnées d'un point
\remarks Aucune
*/
Doublet nouveauDoublet (int ligne ,int colonne);



/*!
\fn nouveauPtsClesCommuns (Noeud* listPts1, Noeud* listPts2, Noeud* listNbPtsCommuns)
\version 1.0
\brief Créer un nouveau PtsClesCommuns
\date 18-01-2014
\param listPts1 une liste de doublets
\param listPts2 idem
\param listNbPtsCommuns une liste d'entiers
\return une structure du type PtsClesCommuns
\remarks Aucune
*/
PtsClesCommuns nouveauPtsClesCommuns (NoeudDoublet* listPts1, NoeudDoublet* listPts2, NoeudInt* listNbPtsCommuns);


/*!
\fn creerNoeudDoublet(Doublet n, NoeudDoublet* suivant, NoeudDoublet* prec)
\version 1.0
\brief Créer un nouveau NoeudDoublet
\date 18-01-2014
\param  n, le premier doublet de la liste
\param suivant la case suivante de notre liste chainée (Souvent initialisée à NULL)
\param prececédent, idem case précédente
\return une structure du type NoeudDoublet*
\remarks Aucune
*/	
NoeudDoublet* creerNoeudDoublet(Doublet n, NoeudDoublet* suivant, NoeudDoublet* prec);

/*!
\fn libererNoeudDoublet(NoeudDoublet* noeud)
\version 1.0
\brief Libérer un NoeudDoublet
\date 18-01-2014
\param  noeud un NoeudDoublet* à libérer
\remarks Aucune
*/	
void libererNoeudDoublet(NoeudDoublet* noeud);

/*!
\fn ajoutFinDoublet(NoeudDoublet* teteListe, Doublet n)
\version 1.0
\brief Ajouter un NoeudDOublet à la fin d'une liste chainée de Doublets
\date 18-01-2014
\param  n, le doublet à ajouter
\param teteListe la liste à modifier
\return une structure du type NoeudDoublet*
\remarks Aucune
*/	
NoeudDoublet* ajoutFinDoublet(NoeudDoublet* teteListe, Doublet n);

/*!
\fn supprTeteDoublet(NoeudDoublet* teteListe)
\version 1.0
\brief Supprimer la tête d'un NoeudDoublet
\date 18-01-2014
\param teteListe la liste à modifier
\return une structure du type NoeudDoublet* avec sa tête supprimée
\remarks Aucune
*/	
NoeudDoublet* supprTeteDoublet(NoeudDoublet* teteListe);

/*!
\fn creerNoeudInt(int n, NoeudInt* suivant, NoeudInt* prec)
\version 1.0
\brief Créer un nouveau NoeudInt
\date 18-01-2014
\param  n, le premier entier de la liste
\param suivant la case suivante de notre liste chainée (Souvent initialisée à NULL)
\param prececédent, idem case précédente
\return une structure du type NoeudInt*
\remarks Aucune
*/	
NoeudInt* creerNoeudInt(int n, NoeudInt* suivant, NoeudInt* prec);

/*!
\fn libererNoeudInt(NoeudInt* noeud)
\version 1.0
\brief Libérer un NoeudInt
\date 18-01-2014
\param  noeud un NoeudInt* à libérer
\remarks Aucune
*/
void libererNoeudInt(NoeudInt* noeud);

/*!
\fn ajoutFinInt(NoeudInt* teteListe, int n)
\version 1.0
\brief Ajouter un NoeudInt à la fin d'une liste chainée de Doublets
\date 18-01-2014
\param  n, l'entier à ajouter
\param teteListe la liste à modifier
\return une structure du type NoeudInt*
\remarks Aucune
*/	
NoeudInt* ajoutFinInt(NoeudInt* teteListe, int n);

/*!
\fn supprTeteInt(NoeudDoublet* teteListe)
\version 1.0
\brief Supprimer la tête d'un NoeudInt
\date 18-01-2014
\param teteListe la liste à modifier
\return une structure du type NoeudInt* avec sa tête supprimée
\remarks Aucune
*/	
NoeudInt* supprTeteInt(NoeudInt* teteListe);






#endif
