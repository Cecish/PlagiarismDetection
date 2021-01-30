#ifndef __TYPES_H___
	#define __TYPES_H___

/*!
\file types.h
\version 1.0
\date 11-06-14
\brief Contient les prototypes des types structurés utilés dans le projet
\remarks Aucune
*/

/*Librairies de base*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include <string.h>

/*!
\struct structAbscisseOrdonneeTriplet
\brief Un triplet contenant abcisse et ordonnée d'un nombre nb0
*/
struct structAbscisseOrdonneeTriplet {
	int int_nb0; /**< le nombre dont on veut les coordonnées */
	int int_abscisse; /**< l'abcisse de nb0  */
	int int_ordonnee; /**< l'ordonnée de nb0 */
};

typedef struct structAbscisseOrdonneeTriplet sTripletCoordonne;
/**< Alias : structAbscisseOrdonneeTriplet est désigné par sTripletCoordonne */


/*!
\struct structCouple
\brief Un couple avec valeur et indice
*/
struct structCouple {
	/*@{*/
	int val; /**< la valeur */
	int indice; /**< l'indice de la valeur */
	/*@}*/
};

typedef struct structCouple sCouple;
/**< Alias :  structCouple désignée par sCouple */


/*!
\typedef Noeud
\brief Un liste chainée doublement
*/
typedef struct Noeud{
	/*@{*/
	void* valeur; /**< la valeur contenue dans le noeud */
	struct Noeud* suivant; /**< le noeud suivant */
	struct Noeud* precedent; /**< le noeud précédent */
	/*@}*/
} Noeud;

/*!
\struct Noeud 
\brief liste doublement chainée avec valeur de type quelconque
*/

/*!
\fn creerNoeud(void* n,Noeud* suivant, Noeud* prec)
\version 1.0
\date 18/03/11
\brief S'occupe de la création du noeud avec vérification du malloc
\param n valeur que doit prendre le noeud
\param suivant Pointeur sur le noeud suivant
\param prec Pointeur sur le noeud precedent
\return Le pointeur vers le noeud cree
*/
Noeud* creerNoeud(void* n,Noeud* suivant, Noeud* prec);

/*!
\fn libererNoeud(Noeud* noeud)
\version 1
\date 2012-12-20
\brief Permet de libere la memoire a la suppression d'un noeud (free de la valeur aussi) 
\param noeud Le noeud a supprimer
*/
void libererNoeud(Noeud* noeud);

/*!
\fn ajoutTete(Noeud* teteListe,void* n)
\version 1.0
\date 18/03/11
\brief Ajoute un noeud en tete de liste
\param teteListe Pointeur vers la tete de la liste
\param n valeur de noeud a ajouter
\return La tete de la liste(pointeur)
*/
Noeud* ajoutTete(Noeud* teteListe,void* n);

/*!
\fn ajoutFin(Noeud* teteListe,void* n)
\version 1.0
\date 18/03/11
\brief Ajoute un noeud en fin de liste
\param teteListe Pointeur vers la tete de la liste
\param n Valeur du noeud a ajouter
\return La nouvelle tete de liste
*/
Noeud* ajoutFin(Noeud* teteListe,void* n);

/*!
\fn ajoutKieme(Noeud* teteListe,int k,void* n)
\version 1.0
\date 18/03/11
\brief Ajoute un noeud a la Kieme position
\param teteListe Pointeur vers la tete de la liste
\param k Le rang ou ajouter un noeud
\param n la valeur du noeud a ajouter
\return La nouvelle tete de liste
*/
Noeud* ajoutKieme(Noeud* teteListe,int k,void* n);

/*!
\fn supprTete(Noeud* teteListe)
\version 1.0
\date 18/03/11
\brief Supprime la tete de liste
\param teteListe Pointeur vers la tete de la liste
\return La nouvelle tete de la liste(pointeur)
*/
Noeud* supprTete(Noeud* teteListe);

/*!
\fn supprFin(Noeud* teteListe)
\version 1.0
\date 18/03/11
\brief Supprime le noeud de fin de la liste
\param teteListe Pointeur vers la tete de la liste
\return La nouvelle tete de liste
*/
Noeud* supprFin(Noeud* teteListe);

/*!
\fn supprKieme(Noeud* teteListe,int k)
\version 1.0
\date 18/03/11
\brief Supprime le noeud de la Kieme position
\param teteListe Pointeur vers la tete de la liste
\param k Le rang du noeud a supprimer
\return La nouvelle tete de liste
*/
Noeud* supprKieme(Noeud* teteListe,int k);

/*!
\fn afficheListe(Noeud* teteListe)
\version 1.0
\date 18/03/11
\brief Affiche une liste sur la sortie standard
\param teteListe Pointeur vers la tete de la liste
*/
void afficheListe(Noeud* teteListe);

/*!
\fn recupKieme(Noeud* teteListe,int k)
\version 1
\date 2012-11-17
\brief Permet de recuperer l'element numero k dans la liste
\param teteListe La tete de liste
\param k La position de l'element a recuperer
\return NULL en cas de depassement de liste, pointeur sur l'element sinon
**/
void* recupKieme(Noeud* teteListe,int k);

/*!
\fn recupFin(Noeud* teteListe)
\version 1
\date 2013-01-09
\brief Permet de recuperer le dernier element d'une liste
\param teteListe La tete de liste
\return NULL en cas de liste NULL, pointeur sur l'element sinon
*/
void* recupFin(Noeud* teteListe);

/*!
\fn taille (Noeud* teteListe)
\version 1
\date 12/05/2014
\brief Permet de récupérer la taille de la liste
\param teteListe La tete de liste
\return int : le nombre d'éléments de la liste
*/
int taille (Noeud* teteListe);

/*!
\fn chercheNoeud(Noeud* teteListe, void* val)
\version 1
\date 2012-12-20
\brief Permet de rechercher un noeud à partir de sa valeur 
\param teteListe La tete de la liste
\param val La valeur du noeud (pointeur)
\return Le noeud de valeur val
**/
Noeud* chercheNoeud(Noeud* teteListe, void* val);

/*!
\fn supprNoeud(Noeud* teteListe, void* val)
\version 1
\date 2012-12-20
\brief Permet de supprimer un noeud a partir de sa valeur 
\param teteListe La tete de la liste
\param val La valeur du noeud (pointeur)
\return La tete de la nouvelle liste
**/
Noeud* supprNoeud(Noeud* teteListe, void* val);

/*!
\fn enleveNoeud(Noeud* teteListe, void* val)
\version 1
\date 2013-01-04
\brief Permet de supprimer un noeud a partir de sa valeur, 
sans le desallouer
\param teteListe La tete de la liste
\param val La valeur du noeud (pointeur)
\return La tete de la nouvelle liste
*/
Noeud* enleveNoeud(Noeud* teteListe, void* val);

/*!
\fn supprListe(Noeud* teteListe)
\version 1
\date 2012-12-20
\brief Permet de supprimer une liste entiere 
\param teteListe La tete de liste
\return NULL (pour utiliser la fonction sur le principe liste=supprListe(liste))
*/
Noeud* supprListe(Noeud* teteListe);


#endif