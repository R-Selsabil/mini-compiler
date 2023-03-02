//structure of a quadruplet
#define P_MAX 255

typedef struct quadrupletNode
{
    char operator[20];
    char operand1[255];
    char operand2[255];
    char result[255];

    int address;
    struct quadrupletNode *next;
} QUADRUPLETNODE;

typedef struct quadTable
{
    struct quadrupletNode *head;
    int size;
} QUADTABLE;


typedef struct quadPile //this stack is used to keep quads so we can modify them
{
    int top;
    QUADRUPLETNODE* items[P_MAX];
} QUADPILE;


QUADTABLE* initialiserTQ();
void afficherTQ(QUADTABLE *TQ);
void supprimer_TQ(QUADTABLE *TQ);
void inserer_TQ(QUADTABLE *TQ, QUADRUPLETNODE *Q);
QUADRUPLETNODE* rechercherTQ(QUADTABLE *TQ,  int address);


QUADRUPLETNODE* creer_Q(char operator[], char* operand1, char* operand2, char* result, int address);
void afficherQ(QUADRUPLETNODE* Q);



//stack functions 
QUADPILE* initialiserP();
void afficherP(QUADPILE* P);
int Pempty(QUADPILE *P);
int Pfull(QUADPILE *P);
void push(QUADPILE *P, QUADRUPLETNODE *Q);
QUADRUPLETNODE* pop(QUADPILE *P);
