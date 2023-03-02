#include <stdlib.h>
#include "quadruplet.h"
#include <stdio.h>
#include <string.h>


QUADTABLE* initialiserTQ(){
    QUADTABLE *quadTable = malloc(sizeof(QUADTABLE));
    quadTable->head = NULL;
    quadTable->size = 0;
    printf("initialisaiton done\n");
    return quadTable;
}

QUADRUPLETNODE* creer_Q(char operator[], char* operand1, char* operand2, char* result, int address){
    QUADRUPLETNODE *quadruplet = malloc(sizeof(QUADRUPLETNODE));
    quadruplet->address = address;
    strcpy(quadruplet->operator, operator);
    strcpy(quadruplet->operand1, operand1);
    strcpy(quadruplet->operand2, operand2);
    strcpy(quadruplet->result, result);
    
    return quadruplet;
}

void afficherQ(QUADRUPLETNODE* Q){
    printf("%d : (%s, %s, %s, %s)\n", Q->address, Q->operator, Q->operand1, Q->operand2, Q->result);
    return;
}

void inserer_TQ(QUADTABLE *TQ, QUADRUPLETNODE *Q){
    if(TQ->head == NULL){
        TQ->head = Q;
        return;
    }
    QUADRUPLETNODE *n = TQ->head, *tmp;
    while(n != NULL) {
        tmp = n;
        n = n->next;
    }
    tmp->next = Q;
    Q->next = NULL;
    return;
}

void afficherTQ(QUADTABLE *TQ){
    printf("Table Quadruplets : \n");
    QUADRUPLETNODE *quad = TQ->head;
    while(quad != NULL){
        afficherQ(quad);
        quad = quad->next;
    }
    return;
}

QUADRUPLETNODE* rechercherTQ(QUADTABLE *TQ,  int address){
    QUADRUPLETNODE *quad = TQ->head;
    while(quad != NULL){
        if (quad->address == address){
            return quad;
        } else {
            quad = quad->next;
        }
    }
    return NULL;
}

void updateEtiq(QUADRUPLETNODE *Q, int newAdr){
    char op[20];
    itoa(newAdr, op, 10);
    strcpy(Q->operand1, op);
    return;
}

//stack functions 
QUADPILE* initialiserP() {
    QUADPILE *pile = malloc(sizeof(QUADPILE));
    pile->top = -1;
    printf("initialisaiton done\n");
    return pile;
}
int Pempty(QUADPILE *P){
    if(P->top == -1){
        return 1; //it is empty
    } 
    return 0;
}

int Pfull(QUADPILE *P){
    if(P->top == P_MAX - 1){
        return 1;
    }
    return 0;
}

void push(QUADPILE *P, QUADRUPLETNODE *Q){
    //add to stack 
    if(!Pfull(P)){
        //if stack isnt full
        P->top++;
        P->items[P->top] = Q;
        //printf("Q is inserted no worries <3 \n \n ");
    } 
    else {
        printf("cant pop, is full \n");
    }
}

QUADRUPLETNODE* pop(QUADPILE *P){
        //add to stack 
    if(!Pempty(P)){
        QUADRUPLETNODE *Q = P->items[P->top];
        //printf("POPED");
        P->top--;
        return Q;
    }
    printf("cant pop, is empty \n");
    return NULL;
}

void afficherP(QUADPILE* P){
    printf("QUADRUPLET STACK : \n");
    if(!Pempty(P)){
        for(int i = 0; i <= P->top; i++){
            afficherQ(P->items[i]);
        }
    } else {
        printf("STACK EMPTY \n");
    }

}