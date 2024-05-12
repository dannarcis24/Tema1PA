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
    nod->numar_concurenti = -1;

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

void delTeamList(TeamList **list)
{
    TeamList *p = *list;
    while(p)
    {
        TeamList *q = p->next;

        delPLayerList(&p->echipa->lista_concurenti);
        free(p->echipa);
        free(p);
        
        p = q;
    }

    *list = NULL;
}