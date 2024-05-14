#include "libs.h"

// TIPURILE DE STRUCT
//        (stiva, coada)
typedef struct c{
    TeamList *echipa;
    struct c *next;
} Stack;

typedef struct d{
    TeamList *first, *last;
} Queue;

// APELURI PENTRU FUNCTII DE GESTIONARE A UNEI STIVE
//        (creare, adaugare, extragere, stergere)
Stack* createStack();
void push(Stack**, TeamList*);
TeamList* pop(Stack**);
void delStack(Stack**);

// APELURI PENTRU FUNCTII DE GESTIONARE A UNEI COZI