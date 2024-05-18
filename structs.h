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
    int height;
    TeamList *val;
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
//        (creari nod/BST/AVL, verificari, calcularea inaltimii, adaugari, rotatii stanga/dreapta, afisari, stergere)
Tree* createTree();
Tree* createBinarySearchTree(TeamList*);
void createAVL(Tree**); 
void addInTree(Tree*, TeamList*);
int verifOrd(Team*, Team*);
Tree* searchFather(Tree*, Tree*);
Tree* isBalanced(Tree*);
int height(Tree*);
void calcHeight(Tree*);
Tree* leftRotation(Tree*);
Tree* rightRotation(Tree*);
void writeTree(Tree*, FILE*); // parcurgerea in inordine
void writeLevel2(Tree*, int, FILE*);
void delTree(Tree**);

// APELURI PENTRU FUNCTII DE GESTIONARE A CONCURSULUI
TeamList* whoWins(TeamList*, TeamList*);
void addPoints(Team*);
void match(Queue**, Node**, Node**);
void writeRound(Queue*, int, char*);
void writeWinners(Node*, int, char*);
TeamList* top8(TeamList*, int, char*[]);
