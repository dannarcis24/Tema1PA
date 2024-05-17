#include "libs.h"

// TIPURILE DE STRUCT
//        (stiva, coada)
typedef struct c{
    TeamList *echipa;
    struct c *next;
} Node;

typedef struct d{
    Node *first, *last;
} Queue;

typedef struct e{
    Node *val;
    struct e *left, *right;
} Tree;

// APELURI PENTRU FUNCTII DE GESTIONARE A UNEI STIVE
//        (creare, adaugare, extragere, stergere)
Node* createNode();
void push(Node**, TeamList*);
TeamList* pop(Node**);
void delStack(Node**);

// APELURI PENTRU FUNCTII DE GESTIONARE A UNEI COZI
//        (creare, adaugare, extragere, stergere)
Queue* createQueue();
void enQueue(Queue*, TeamList*);
TeamList* deQueue(Queue*);
void delQueue(Queue**);

//APELURI PENTRU FUNCTII DE GESTIONARE A UNUI ARBORE BINAR
//        (creare, creare BST, afisare, stergere)
Tree* createTree();
Tree* createBinarySearchTree(Node*);
void writeTree(Tree*); // parcurgerea in inordine
void delTree(Tree**);

// APELURI PENTRU FUNCTII DE GESTIONARE A CONCURSULUI
TeamList* whoWins(TeamList*, TeamList*);
void addPoints(Team*);
void match(Queue**, Node**, Node**);
void writeRound(Queue*, int, char*);
void writeWinners(Node*, int, char*);
Node* top8(TeamList*, int, char*[]);
