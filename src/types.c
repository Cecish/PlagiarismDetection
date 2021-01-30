/*!
\file types.c
\version 1.0
\date 10-11-2013
\brief Code source pour l'implentation des fonctions sur les structures
\remarks Aucune
*/

#include "types.h"


Noeud* creerNoeud(void* n,Noeud* suivant, Noeud* prec)
{
	Noeud* retour;
	retour=malloc(sizeof(Noeud)); 
	if(retour==NULL){
		exit(405);
	}
	retour->valeur=n;
	retour->suivant=suivant;
	retour->precedent=prec;
	return retour;
}

void libererNoeud(Noeud* noeud){
	if(noeud!=NULL){
		if (noeud->valeur!=NULL){
			free(noeud->valeur);
		}
		free(noeud);
	}
}

Noeud* ajoutTete(Noeud* teteListe,void* n)
{
	Noeud* retour;
	retour = creerNoeud(n,teteListe,NULL);
	if (retour->suivant!=NULL){
		retour->suivant->precedent=retour;
	}
	return retour;
}


Noeud* ajoutFin(Noeud* teteListe,void* n)
{
	Noeud* tmp;
	tmp=teteListe;
	if(tmp!=NULL){
		while(tmp->suivant!=NULL){
			tmp=tmp->suivant;
		}
		tmp->suivant=creerNoeud(n,NULL,tmp);
	}else{
		teteListe = creerNoeud(n,NULL,NULL);
	}
	return teteListe;
}


Noeud* ajoutKieme(Noeud* teteListe,int k,void* n)
{
	Noeud* tmp;
	tmp=teteListe;
	if(k==1 || tmp==NULL){
		teteListe=ajoutTete(teteListe,n);
	}
	else if(k>1){
		while(k!=2 && tmp!=NULL){
			tmp=tmp->suivant;
			k--;
		}
		if(tmp!=NULL){
			tmp->suivant=creerNoeud(n,tmp->suivant,tmp);
			tmp->suivant->suivant->precedent=tmp->suivant;
		}
	}
	return teteListe;
}


Noeud* supprTete(Noeud* teteListe)
{
	Noeud* retour;
	if(teteListe!=NULL){
		retour=teteListe->suivant;
		if (retour!=NULL){
			retour->precedent=NULL;	
		}
		libererNoeud(teteListe);
	}else{
		retour = NULL;
	}
	return retour;
}


Noeud* supprFin(Noeud* teteListe)
{
	Noeud* tmp;
	if (teteListe!=NULL){
		if(teteListe->suivant == NULL){
			libererNoeud(teteListe);
			teteListe=NULL;
		}
		else{
			tmp=teteListe;
			while((tmp->suivant)->suivant!=NULL){
				tmp=tmp->suivant;
			}
			libererNoeud(tmp->suivant);
			tmp->suivant=NULL;
		}
	}
	return teteListe;
}


Noeud* supprKieme(Noeud* teteListe,int k)
{
	Noeud* tmp;
	tmp=teteListe;
	if(k==1 && tmp!=NULL){
		teteListe = supprTete(teteListe);
	}else if(k>1){
		while(k!=1 && tmp!=NULL){
			tmp=tmp->suivant;
			k--;
		}
		if(tmp!=NULL){
			if (tmp->suivant!=NULL){
				tmp->suivant->precedent = tmp->precedent;
			}
			tmp->precedent->suivant=tmp->suivant;
			libererNoeud(tmp);
		}
	}
	return teteListe;
}


void afficheListe(Noeud* teteListe)
{
	Noeud* tmp;
	tmp=teteListe;
	while(tmp !=NULL){
		printf("--------------------------\n");
/*		printf("precedent : %p\n",(void*)tmp->precedent);*/
/*		printf("\t\tadresse : %p\n",(void*)tmp);*/
/*		printf("\t\tadresse valeur : %p\n",(void*)tmp->valeur);*/
/*		printf("\t\tvaleur : ");*/
		printf("%s ", (char*)tmp->valeur);
/*		printf("\nsuivant : %p\n",(void*)tmp->suivant);*/
		printf("\n");
		tmp=tmp->suivant;
	}
	printf("---------------------\n");
	printf("NULL\n");
}

void* recupKieme(Noeud* teteListe,int k){
	Noeud* tmp;
	tmp=teteListe;
	k--;
	if (tmp!=NULL){
		while (tmp->suivant!=NULL && k>0){
			tmp=tmp->suivant;
			k--;
		}
	}
	return((teteListe!=NULL && k==0)?tmp->valeur:NULL);
}

void* recupFin(Noeud* teteListe){
    Noeud* tmp;
    tmp=teteListe;
    if(tmp != NULL){
        while(tmp->suivant!=NULL){
            tmp=tmp->suivant;
        }
    }
return(tmp->valeur);
}

int taille (Noeud* teteListe) {
	int t;
	Noeud* tmp;
	
	t = 0;
	tmp=teteListe;
	if(tmp != NULL){
		while(tmp->suivant!=NULL){
 			tmp=tmp->suivant;
 			t++;
		}
	}
	return t;
}

Noeud* chercheNoeud(Noeud* teteListe, void* val){
	Noeud* tmp;
	int verif;
	tmp=teteListe;
	verif=1;
	while(tmp!=NULL && verif){
		if (tmp->valeur==val){
			verif=0;
		}else{
			tmp=tmp->suivant;
		}
	}
	return tmp;
}

Noeud* supprNoeud(Noeud* teteListe, void* val){
	Noeud* tmp;
	tmp=chercheNoeud(teteListe,val);
	if (tmp!=NULL){
		if (tmp->suivant!=NULL){
			tmp->suivant->precedent=tmp->precedent;
		}
		if (tmp->precedent!=NULL){
			tmp->precedent->suivant=tmp->suivant;
		}else{
			teteListe=tmp->suivant;
		}
		libererNoeud(tmp);
	}
	return teteListe;
}

Noeud* enleveNoeud(Noeud* teteListe, void* val){
	Noeud* tmp;
	tmp=chercheNoeud(teteListe,val);
	if (tmp!=NULL){
		if (tmp->suivant!=NULL){
			tmp->suivant->precedent=tmp->precedent;
		}
		if (tmp->precedent!=NULL){
			tmp->precedent->suivant=tmp->suivant;
		}else{
			teteListe=tmp->suivant;
		}
	}
	return teteListe;
}

Noeud* supprListe(Noeud* teteListe){
	while (teteListe!=NULL){
		teteListe=supprTete(teteListe);
	}
	return NULL;
}