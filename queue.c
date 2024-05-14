#include "structs.h"
Queue* createQueue()
{
    Queue *nod = (Queue*)malloc(sizeof(Queue));
    if(!nod)
    {
        printf("variabilei nod nu i s-a putut aloca memorie");
        exit(1);
    }

    nod->first = nod->last = NULL;
    return nod;
}

void enQueue(Queue *q, TeamList *elem)
{
    Node *nod = createNode();
    nod->echipa = elem;
    nod->next = NULL;

    if(!q->first)
    {
        q->first = q->last = nod;
        return;
    }

    q->last->next = nod;
    q->last = nod;
}

TeamList* deQueue(Queue *q)
{
    if(!q->first)
        return NULL;

    TeamList *nod = q->first->echipa;
    Node *p = q->first;
    q->first = q->first->next;
    if(!q->first)
        q->last = NULL;
    
    free(p);

    return nod;
}

void delQueue(Queue **q)
{
    if(!(*q))
        return;
    
    while((*q)->first)
    {
        Node *p = (*q)->first;
        (*q)->first = p->next;

        free(p);
    }

    free(*q);
    *q = NULL;
}