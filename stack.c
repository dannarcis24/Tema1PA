#include "structs.h"
Node* createNode()
{
    Node *nod = (Node*)malloc(sizeof(Node));
    if(!nod)
    {
        printf("variabilei nod nu i s-a putut aloca memorie");
        exit(1);
    }

    nod->echipa = NULL;
    nod->next = NULL;

    return nod;
}

void push(Node **stiva, TeamList *elem)
{
    Node *nod = createNode();
    nod->echipa = elem;
    nod->next = *stiva;
    *stiva = nod;
}

TeamList* pop(Node **stiva)
{
    if(!(*stiva))
        return NULL;

    TeamList *nod = (*stiva)->echipa;

    Node* p = *stiva;
    *stiva = (*stiva)->next;
    p->next = NULL;
    free(p);

    return nod;
}

void delStack(Node **stiva)
{
    if(!(*stiva))
        return;

    TeamList *p;
    while((*stiva))
        p = pop(stiva); 

    free(*stiva);
    *stiva = NULL;
}
