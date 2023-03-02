#define STR 0
#define BOOL 1
#define INT 2
#define REAL 3
#define NUM 4 //includes real and int and only used to evaluate arithmetic expressions

#define CONST 0
#define VAR 1
#define FUN 2
#define ARRAY 3

typedef struct arrayContent{
    char* elements[255]; //pointer to a table of values
    int size;
} ARRAYCONTENT;


typedef struct NodeInfo
{
    char Token[255];
    int Type;
    char Value[255];
    int TokenType;
    ARRAYCONTENT *arraycontent;
} NODEINFO;


//Structure d'une entrée 
typedef struct NodeSymTable
{
    struct NodeInfo info;
    struct NodeSymTable *next;
} NODESYMTABLE;


//Structure d'une table des Symboles 
typedef struct SymTable
{
    struct NodeSymTable *head;
    int size;
} SYMTABLE;


NODESYMTABLE *rechercher(SYMTABLE *TS, char nom[]);

ARRAYCONTENT *accessArray(SYMTABLE *TS, char nomArray[]);

void addElementToArray(SYMTABLE *TS, char nomArray[], char element[]);

void setValue(SYMTABLE *TS, char name[], char value[]);

//void setType(NODESYMTABLE **TOKEN, int type);

void setType(SYMTABLE *TS, char name[], int type);

int supprimer(SYMTABLE *TS, char nom[]);

SYMTABLE *initialiserTS();

NODESYMTABLE *inserer(SYMTABLE *TS, char nom[]);

int supprimerTS(SYMTABLE *TS);

void afficherSymbole(NODESYMTABLE* S);

void afficherTS(SYMTABLE *TS);

void setTokenType(SYMTABLE *TS, char name[], int TokenType);
