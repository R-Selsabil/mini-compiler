#include "TableSymboles.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//Fonction d'initialisation d'une TS
SYMTABLE *initialiserTS(){
    SYMTABLE *symboleTable = malloc(sizeof(SYMTABLE));
    symboleTable->head = NULL;
    symboleTable->size = 0;
    printf("initialisaiton done\n");
    return symboleTable;
}


//Fonction de recherche 
NODESYMTABLE *rechercher(SYMTABLE *TS, char nom[]){
    NODESYMTABLE *n = TS->head;
    while (n != NULL) {
        if(strcmp(n->info.Token, nom) == 0) {
            return n;
        } else {
            n = n->next;
        }
    }
    //printf("we didnt find it \n");
    return NULL;
}


//Fonction d'insertion
NODESYMTABLE *inserer(SYMTABLE *TS, char nom[]){
    NODESYMTABLE *node = malloc(sizeof(NODESYMTABLE));
    strcpy(node->info.Token, nom);
    node->info.Type = -1;
    node->info.TokenType = -1;
    node->next = TS->head;
    TS->head = node;
    TS->size++;
    return node;
}


//Fonction de suppression de la TS 
int supprimerTS(SYMTABLE *TS){
    NODESYMTABLE *node = TS->head, *tmp;
    while(node != NULL) {
        tmp = node;
        free(node);
        node = tmp->next;
    }
    free(TS);
}


//Affichage 
void afficherTS(SYMTABLE *TS) {
    printf("\n \nTable des symboles \n \n");
    NODESYMTABLE *n = TS->head;
    while(n != NULL) {
        afficherSymbole(n);
        n = n->next;
    }
    printf("\n\n");
}

void afficherSymbole(NODESYMTABLE* S){
    char type[20] = "", tokenType[20] = "";
    switch(S->info.Type){
        case  0 :
            strcpy(type, "str");
            break;
        case 1 : 
            strcpy(type, "bool");
            break;
        case 2 : 
            strcpy(type, "int");
            break;
        case 3 : 
            strcpy(type, "real");
            break;
    }

    switch(S->info.TokenType){
        case  0 :
            strcpy(tokenType, "const");
            break;
        case 1 : 
            
            strcpy(tokenType, "var");
            break;
        case 2 : 
            strcpy(tokenType, "fun");
            break;
        case 3 : 
            strcpy(tokenType, "array");
            break;
    }


    printf("%s : %s   -  %s  -  %s ", S->info.Token, type, tokenType, S->info.Value);
    printf("\n");
}
//get the array of values of an array
ARRAYCONTENT *accessArray(SYMTABLE *TS, char nomArray[]){
    NODESYMTABLE *node = rechercher(TS, nomArray);
    return node->info.arraycontent;
    
}

void setType(SYMTABLE *TS, char name[], int type){
    NODESYMTABLE *TOKEN = rechercher(TS, name);
    if(TOKEN != NULL){
        TOKEN->info.Type = type;
    }
    return;
}


/*void setType(NODESYMTABLE **TOKEN, int type){
    if(*TOKEN != NULL){
        (*TOKEN)->info.Type = type;
        printf("done here");
        
    }
    return;
}*/


void setTokenType(SYMTABLE *TS, char name[], int TokenType){
    NODESYMTABLE *TOKEN = rechercher(TS, name);
    if(TOKEN != NULL){
        TOKEN->info.TokenType = TokenType;
    }
    return;
}

void setValue(SYMTABLE *TS, char name[], char value[]){
    NODESYMTABLE *TOKEN = rechercher(TS, name);
    if(TOKEN != NULL){
        strcpy(TOKEN->info.Value, value);
        return;
    }
    return;
}

void addElementToArray(SYMTABLE *TS, char nomArray[], char element[]){
    NODESYMTABLE *TOKEN = rechercher(TS, nomArray);
    if(TOKEN != NULL){
        if(TOKEN->info.arraycontent == NULL){
            ARRAYCONTENT *node = malloc(sizeof(NODESYMTABLE));
            node->elements;
            TOKEN->info.arraycontent = node;
        }
    }
}


