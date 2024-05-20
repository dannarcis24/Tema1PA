#include "libs.h"

// TIPURILE DE STRUCT
//        (stiva, coada, arbore binar)
typedef struct c{
    TeamList *echipa;
    struct c *next;
} Node;

typedef struct d{
    Node *first, *last;
} Queue;

typedef struct e{
    int height;
    void *val;
    struct e *left, *right;
} Tree;

// APELURI PENTRU FUNCTII DE GESTIONARE A UNEI STIVE
//        (creare, adaugare, extragere, stergere)
Node* createNode();
void push(Node**, TeamList*); // se adauga element la inceput
TeamList* pop(Node**); // se extrage element de la inceput
void delStack(Node**);

// APELURI PENTRU FUNCTII DE GESTIONARE A UNEI COZI
//        (creare, adaugare, extragere, stergere)
Queue* createQueue();
void enQueue(Queue*, TeamList*); // se adauga element la final
TeamList* deQueue(Queue*); // se extrage element de la inceput
void delQueue(Queue**);

// APELURI PENTRU FUNCTII DE GESTIONARE A UNUI ARBORE BINAR
//        (creare, verificare, calcularea inaltimii, scriere, stergere)
Tree* createTree();
int verifOrd(Team*, Team*); // se aplica pentru BST/AVL
int height(Tree*);
void calcHeight(Tree*);
void writeTree(Tree*, FILE*); // parcurgerea in inordine de la dreapta (dreapta - radacina - stanga)
void writeLevel2(Tree*, int, FILE*);
void delTree(Tree**);
// APELURI PENTRU FUNCTII DE GESTIONARE BST
//        (creare, adaugare)
Tree* createBST(TeamList*);
void addInBST(Tree*, TeamList*);
// APELURI PENTRU FUNCTII DE GESTIONARE AVL
//        (creare, adaugare, rotatii)
void createAVL(Tree**, Tree*);
Tree* addInAVL(Tree*, Tree*);
Tree* leftRotation(Tree*);
Tree* rightRotation(Tree*);

// APELURI PENTRU FUNCTII DE GESTIONARE A CONCURSULUI
TeamList* whoWins(TeamList*, TeamList*);
void addPoints(Team*);
void match(Queue**, Node**, Node**);
void writeRound(Queue*, int, char*);
void writeWinners(Node*, int, char*);
TeamList* top8(TeamList*, int, char*[]);
