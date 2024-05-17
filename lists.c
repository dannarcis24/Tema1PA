#include "tasks.h"
Player* createPlayer()
{
    Player *nod = (Player*)malloc(sizeof(Player));
    if(!nod)
    {
        printf("variabilei nod nu i s-a putut aloca memorie\n");
        exit(1);
    }

    nod->nume = nod->prenume = NULL;
    nod->punctaj = -1;
    
    return nod;
}

PlayerList* createPlayerList()
{
    PlayerList *nod = (PlayerList*)malloc(sizeof(PlayerList));
    if(!nod)
    {
        printf("variabilei nod nu i s-a putut aloca memorie\n");
        exit(1);
    }

    nod->concurent = NULL;
    nod->next = NULL;

    return nod;
}

void addPlayer(PlayerList **list, Player *elem)
{
    if(!(*list)->concurent)
    {
        (*list)->concurent = elem;
        return;
    }

    PlayerList *nod = createPlayerList();
    nod->concurent = elem;
    
    nod->next = *list;
    *list = nod;
}

void delPLayerList(PlayerList **list)
{
    if(*list == NULL)
        return;

    PlayerList *p = *list;
    while(p)
    {
        PlayerList *q = p->next;

        free(p->concurent->nume);
        free(p->concurent->prenume);
        free(p->concurent);
        free(p);

        p = q;
    }

    *list = NULL;
}

Team* createTeam()
{
    Team *nod = (Team*)malloc(sizeof(Team));
    if(!nod)
    {
        printf("variabilei nod nu i s-a putut aloca memorie\n");
        exit(1);
    }

    nod->nume_echipa = NULL;
    nod->lista_concurenti = NULL;
    nod->numar_concurenti = nod->punctaj_echipa = -1;

    return nod;
}

TeamList* createTeamList()
{
    TeamList *nod = (TeamList*)malloc(sizeof(TeamList));
    if(!nod)
    {
        printf("variabilei nod nu i s-a putut aloca memorie\n");
        exit(1);
    }

    nod->echipa = NULL;
    nod->next = NULL;

    return nod;
}

void addTeam(TeamList **list, Team *elem)
{
    if(!(*list)->echipa)
    {
        (*list)->echipa = elem;
        return;
    }

    TeamList *nod = createTeamList();
    nod->echipa = elem;
    nod->next = *list;
    *list = nod;
}

void copyTeam(TeamList **list, Team *elem)
{
    Team *nod = createTeam();
    *nod = *elem;

    addTeam(list, nod);
}

void delTeamPoints(TeamList **list, float punctaj)
{
    if((*list)->echipa->punctaj_echipa == punctaj)
    {
        TeamList *p = *list;
        *list = p->next;
        p->next = NULL;
        delTeamList(&p, 1);
        
        return;
    }

    TeamList *p;
    for(p = *list; p->next; p = p->next)
        if(p->next->echipa->punctaj_echipa == punctaj)
        {
            TeamList *q = p->next;
            p->next = q->next;
            q->next = NULL;
            delTeamList(&q, 1);

            return;
        }
    
    if(p->echipa->punctaj_echipa == punctaj)
        delTeamList(&p, 1);
}

void delTeamList(TeamList **list, int ok)
{
    TeamList *p = *list;

    while(p)
    {
        TeamList *q = p->next;

        if(ok)
            delPLayerList(&p->echipa->lista_concurenti);
        else
            p->echipa->lista_concurenti = NULL;
        free(p->echipa->nume_echipa);
        free(p->echipa);
        free(p);

        p = q;
    }

    *list = NULL;
}
