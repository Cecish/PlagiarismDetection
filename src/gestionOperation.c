/*!
\file gestionOperation.c
\version 1.0
\date 11-06-2014
\brief Code source pour les opérations
\remarks Aucune
*/

/*Headers */
#include "gestionOperation.h"
#include "grammaire.h"


/* Fonction d'affichage pour le debug */
void afficherMatriceIntCarree(int** matrice, int taille) {
    int i;
    int j;

    printf("Matrice %dx%d\n", taille,taille);
    for (i = 0 ; i < taille ; i++) {
        for (j = 0 ; j < taille ; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/* Fonction pour afficher les clés de la HashMap avec leur indice */
void afficherHashTable(GHashTable* hashTable) {
    gpointer gptr_key = NULL;
    gpointer gptr_index = NULL;
    char* str_key;
    int* int_value;
    GHashTableIter iter;

    g_hash_table_iter_init (&iter,hashTable); 
    while (g_hash_table_iter_next(&iter,&gptr_key,&gptr_index)) {
        str_key = gptr_key;
        int_value = gptr_index; 

        printf("%d -> %s\n", *int_value,str_key);
    }
}

/*Compte le nombre de fonction pour pouvoir alloc le vecteur correctement */
GHashTable* compteNombreFonctions(char* f, GHashTable* hashTable, int* int_nbFonctions) {
    GScanner* gscanner;
    int int_cptAcco;
    int int_cptParen; 
    int* int_v;

    int_cptAcco = 0;
    int_cptParen = 0;

    hashTable = g_hash_table_new(g_int_hash, g_int_equal);
    gscanner = g_scanner_new(NULL);
    g_scanner_input_text(gscanner,f,strlen(f));

    while(g_scanner_get_next_token (gscanner) != G_TOKEN_EOF) {
        g_scanner_peek_next_token(gscanner);
        switch(gscanner->token) {
            case G_TOKEN_LEFT_CURLY :
                int_cptAcco++;
                break;
            case G_TOKEN_RIGHT_CURLY :
                int_cptAcco--;
                break;
            case G_TOKEN_LEFT_PAREN :
                int_cptParen++;
                break;
            case G_TOKEN_RIGHT_PAREN :
                int_cptParen--;
                break;
            case G_TOKEN_IDENTIFIER:
                if (int_cptAcco == 0) {/* Si on se trouve au niveau 0 */
                    if (strcmp(gscanner->value.v_identifier,STRUCT) && strcmp(gscanner->value.v_identifier,TYPEDEF)) {
                        if(int_cptParen == 0) {/*Si Declaration de fonction */
                            if (gscanner->next_token == G_TOKEN_LEFT_PAREN) {
                                if (!g_hash_table_contains(hashTable,gscanner->value.v_identifier)) {
                                    int_v = (int*) int_nbFonctions;
                                    int_v = (int*) malloc(sizeof(int));
                                    *int_v = *int_nbFonctions;
                                    g_hash_table_insert(hashTable,g_strdup(gscanner->value.v_identifier),int_v);

                                    /*printf("%s\n",gscanner->value.v_identifier); */    
                                    (*int_nbFonctions)++;  
                                }
                            }
                        }
                    }
                } else {/*Si on est dans des accolades (Dans une fonction) */
                    if (gscanner->next_token == G_TOKEN_LEFT_PAREN) { /* Appel du type : appelFonction(..)*/
                        if (gscanner->token == G_TOKEN_IDENTIFIER && (strcmp((gscanner->value.v_identifier),IF)) && (strcmp((gscanner->value.v_identifier),FOR)) && (strcmp((gscanner->value.v_identifier),DO)) && (strcmp((gscanner->value.v_identifier),WHILE)) &&(strcmp((gscanner->value.v_identifier),SWITCH))) {
                            if (!g_hash_table_contains(hashTable,g_strdup(gscanner->value.v_identifier))) {
                                    int_v = (int*) int_nbFonctions;
                                    int_v = (int*) malloc(sizeof(int));
                                    *int_v = *int_nbFonctions;
                                    g_hash_table_insert(hashTable,g_strdup(gscanner->value.v_identifier),int_v);
                                    /*printf("%s\n",gscanner->value.v_identifier);  */
                                    (*int_nbFonctions)++;     
                            }      
                        }
                    } else if (gscanner->next_token == G_TOKEN_EQUAL_SIGN) { /* Appel du type : variable = appelFonction(..)*/
                        if(g_scanner_get_next_token(gscanner) != G_TOKEN_EOF) {
                            g_scanner_peek_next_token(gscanner);
                            if(gscanner->next_token == G_TOKEN_IDENTIFIER) {
                                int_v = (int*) int_nbFonctions;
                                int_v = (int*) malloc(sizeof(int));
                                *int_v = *int_nbFonctions;
                                if (!g_hash_table_contains(hashTable,g_strdup(gscanner->next_value.v_identifier))) {
                                    g_hash_table_insert(hashTable,g_strdup(gscanner->next_value.v_identifier),int_v);
                                    /*printf("%s\n",gscanner->next_value.v_identifier);*/
                                    (*int_nbFonctions)++;     
                                }         
                            }        
                        }           
                    }
                }
                break;
            default : break;
        }
    }

    g_scanner_destroy(gscanner);
    return hashTable;
}

/* Création du graphe d'appel des fonctions */
int** creerGrapheAppel(char* f, int int_nbFonctions, GHashTable* hashTable, int** grapheAppel) {
    GScanner* gscanner;
    int int_cptAcco;
    int int_cptParen; 
    gpointer gptr_indiceFuncMere;
    gpointer gptr_indiceFuncFille; 
    int* int_indiceFuncMere;
    int* int_indiceFuncFille;

    int_cptAcco = 0;
    int_cptParen = 0;

    gscanner = g_scanner_new(NULL);
    g_scanner_input_text(gscanner,f,strlen(f));

    while(g_scanner_get_next_token (gscanner) != G_TOKEN_EOF) {
        g_scanner_peek_next_token(gscanner);
        switch(gscanner->token) {
            case G_TOKEN_LEFT_CURLY :
                int_cptAcco++; /*printf("Accolade ouvrante\n");*/
                break;
            case G_TOKEN_RIGHT_CURLY :
                int_cptAcco--; /*printf("Accolade fermante\n");*/
                break;
            case G_TOKEN_LEFT_PAREN :
                int_cptParen++;
                break;
            case G_TOKEN_RIGHT_PAREN :
                int_cptParen--;
                break;
            case G_TOKEN_IDENTIFIER:
                if (int_cptAcco == 0) {/* Si on se trouve au niveau 0 */
                    if (strcmp(gscanner->value.v_identifier,STRUCT) && strcmp(gscanner->value.v_identifier,TYPEDEF)) {
                        if(int_cptParen == 0) {/*Si Declaration de fonction -> on prend l'indice de la fonction mère en parametre */
                            if (gscanner->next_token == G_TOKEN_LEFT_PAREN) {
                                gptr_indiceFuncMere = g_hash_table_lookup(hashTable,g_strdup(gscanner->value.v_identifier));
                                int_indiceFuncMere = gptr_indiceFuncMere;                
                            }   
                        }
                    }                    
                } else {/*Si on est dans des accolades (Dans une fonction) */
                    if (gscanner->next_token == G_TOKEN_LEFT_PAREN) { /* Appel du type : appelFonction(..)*/
                        if (gscanner->token == G_TOKEN_IDENTIFIER && (strcmp((gscanner->value.v_identifier),IF)) && (strcmp((gscanner->value.v_identifier),FOR)) && (strcmp((gscanner->value.v_identifier),DO)) && (strcmp((gscanner->value.v_identifier),WHILE)) &&(strcmp((gscanner->value.v_identifier),SWITCH))) {
                                 gptr_indiceFuncFille = g_hash_table_lookup(hashTable,g_strdup(gscanner->value.v_identifier));
                                 int_indiceFuncFille = gptr_indiceFuncFille;
                                grapheAppel[*int_indiceFuncFille][*int_indiceFuncMere]++;
                        }
                    } else if (gscanner->next_token == G_TOKEN_EQUAL_SIGN) { /* Appel du type : variable = appelFonction(..)*/
                        if(g_scanner_get_next_token(gscanner) != G_TOKEN_EOF) {
                            g_scanner_peek_next_token(gscanner);
                            if(gscanner->next_token == G_TOKEN_IDENTIFIER) {
                                gptr_indiceFuncFille = g_hash_table_lookup(hashTable,g_strdup(gscanner->next_value.v_identifier));
                                 int_indiceFuncFille = gptr_indiceFuncFille;
                                grapheAppel[*int_indiceFuncFille][*int_indiceFuncMere]++;
                                    /*printf("%s\n",gscanner->next_value.v_identifier);*/    
                            }        
                        }           
                    } else { /*TODO Ajouter les derniers types d'appels (Voir notes) */
                        /*printf("Coucou\n");*/
                    }
                } 
                break;
            default : break;
        }
    }
    g_scanner_destroy(gscanner);

    return grapheAppel;
}

/* Appelle les opérations pour la création du graphe*/
int** creationGrapheFonction(char* f, int* int_nbFonctions, int** grapheAppel) {
    GHashTable* hashTable = NULL;
    int i;

    *int_nbFonctions = 0;
	hashTable = compteNombreFonctions(f, hashTable, int_nbFonctions);
    grapheAppel = calloc(*int_nbFonctions,sizeof(int*));
    for (i = 0 ; i < *int_nbFonctions ; i++) {
        grapheAppel[i] = calloc(*int_nbFonctions,sizeof(int));
    }

    grapheAppel = creerGrapheAppel(f,*int_nbFonctions,hashTable,grapheAppel);
    /*afficherMatriceIntCarree(grapheAppel,*int_nbFonctions);*/

    g_hash_table_destroy(hashTable);

    return grapheAppel;
}

/*Gestion du traitement du graphe de fonctions */
void gestionGraphesFonctions (char* str_f1, char* str_f2) {
    int** grapheAppel1 = NULL;
    int** grapheAppel2 = NULL;
    int int_nbFonctions1;
    int int_nbFonctions2;
    int i;

    grapheAppel1 = creationGrapheFonction(str_f1,&int_nbFonctions1,grapheAppel1);
    grapheAppel2 = creationGrapheFonction(str_f2,&int_nbFonctions2,grapheAppel2);
    if ((grapheAppel1 != NULL) && (grapheAppel2 != NULL)) {
        printf("Function calls graphs succesfully created for both files\n");
        compareGrapheAppel(grapheAppel1, grapheAppel2 , int_nbFonctions1 ,int_nbFonctions2 , 100);
        for (i = 0 ; i < int_nbFonctions1 ; i++) {
            free(grapheAppel1[i]);
        }
        for (i = 0 ; i < int_nbFonctions2 ; i++) {
            free(grapheAppel2[i]);
        }
        free(grapheAppel1);
        free(grapheAppel2);
    } else {
        fprintf(stderr,"Problem building function call graphs\n");
    }
}


/* Traitement des fichiers mis en mémoire*/ 
void mainTraitementFichiersMem(char* str_f1, char* str_f2) {
    printf("\nInitializing function calls graphs method :\n");
    gestionGraphesFonctions(str_f1,str_f2);
    printf("\nInitializing ""pump-o-meter"" method :\n");
    mainPompOMetre(str_f1,str_f2);
}
