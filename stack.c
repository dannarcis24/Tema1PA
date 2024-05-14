#include "structs.h"
Stack* createStack()
{
    Stack *nod = (Stack*)malloc(sizeof(Stack));
    if(!nod)
    {
        printf("variabilei nod nu i s-a putut aloca memorie");
        exit(1);
    }

    nod->echipa = NULL;
    nod->next = NULL;

    return nod;
}

void push(Stack **stiva, TeamList *elem)
{
    Stack *nod = createStack();
    nod->echipa = elem;
    nod->next = *stiva;
    *stiva = nod;
}

TeamList* pop(Stack **stiva)
{
    if(!(*stiva))
        return NULL;

    TeamList *nod = (*stiva)->echipa;

    Stack* p = *stiva;
    *stiva = (*stiva)->next;
    p->next = NULL;
    free(p);

    return nod;
}

void delStack(Stack **stiva)
{
    if(!(*stiva))
        return;

    TeamList *p;
    while((*stiva))
        p = pop(stiva); 

    free(*stiva);
    *stiva = NULL;
}
