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
