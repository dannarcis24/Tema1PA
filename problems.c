#include "structs.h"
TeamList* whoWins(TeamList *list1, TeamList *list2) // verificare echipei castigatoare
{
    return ((list1->echipa->punctaj_echipa > list2->echipa->punctaj_echipa) ? list1 : list2);
}

void addPoints(Team *list) 
{
    list->punctaj_echipa++;
    for(register PlayerList *p = list->lista_concurenti; p; p = p->next)
        p->concurent->punctaj++;
}

void match(Queue **q, Node **castigatori, Node **pierzatori)
{
    TeamList *echipa1, *echipa2;

    while((*q)->first) // efectuarea meciurilor va avea loc atat timp cat mai exista echipe in coada
    {
        echipa1 = deQueue(*q);
        echipa2 = deQueue(*q);

        TeamList *victorie = whoWins(echipa1, echipa2);
        addPoints(victorie->echipa);
        if(victorie == echipa1) // echipa, care a invins, este introdusa in stiva de castigatori, pe cand cealalta echipa este introdusa in stiva de pierzatori
        {
            push(castigatori, echipa1);
            push(pierzatori, echipa2);
        }
        else
        {
            push(castigatori, echipa2);
            push(pierzatori, echipa1);
        }
    }
    delQueue(q); // fiind goala, coada este stearsa pana la urmatorul meci, cand are loc creare noii liste de meciuri
}

void writeRound(Queue *q, int runda, char *fisier)
{
    FILE *f = fopen(fisier, "at");
    if(!f)
    {
        printf("fisierul %s nu s-a putut deschide", fisier);
        exit(1);
    }

    fprintf(f, "\n--- ROUND NO:%d\n", runda);
    for(register Node *p = q->first; p; p = p->next->next)
        fprintf(f, "%-33s-%33s\n", p->echipa->echipa->nume_echipa, p->next->echipa->echipa->nume_echipa);
    fclose(f);
}

void writeWinners(Node *list, int runda, char *fisier)
{
    FILE *f = fopen(fisier, "at");
    if(!f)
    {
        printf("fisierul %s nu s-a putut deschide", fisier);
        exit(1);
    }

    fprintf(f, "\nWINNERS OF ROUND NO:%d\n", runda);
    for(register Node* p = list; p; p = p->next)
        fprintf(f, "%-34s-  %.2f\n", p->echipa->echipa->nume_echipa, p->echipa->echipa->punctaj_echipa);
    fclose(f);
}


TeamList* top8(TeamList* list, int numar, char *argv[])
{
    TeamList* lista_finala = createTeamList();
    Queue *q = createQueue();
    int runda = 1;

    for(register TeamList* p = list; p; p = p->next)
        enQueue(q, p);
        
    while(numar != 1)
    {
        writeRound(q, runda, argv[3]);

        Node *castigatori = NULL, *pierzatori = NULL;
        match(&q, &castigatori, &pierzatori);
        writeWinners(castigatori, runda, argv[3]);
        q = createQueue(); // se creaza coada, pentru inceperea unui nou meci

        numar /= 2;
        for(register Node *p = castigatori; p; p = p->next)
        {
            enQueue(q, p->echipa);
            if(numar == 8) // in cazul, in care au ramas ultimii 8, echipele sunt salvate cu punctajul curent
                copyTeam(&lista_finala, p->echipa->echipa); 
        }

        runda++;
        delStack(&castigatori); // stivele sunt sterse pana la inceperea unei noi runde
        delStack(&pierzatori);
    }

    delQueue(&q);
    return lista_finala;
}
