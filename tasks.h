#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* citireSir(FILE*, int);

typedef struct{
    char *nume, *prenume;
    int punctaj;
} Player;

typedef struct a{
    Player *concurent;
    struct a *next; 
} PlayerList;

typedef struct{
    char *nume_echipa;
    int numar_concurenti;
    PlayerList *lista_concurenti;
} Team;

typedef struct b{
    Team *echipa;
    struct b *next;
} TeamList;

Player* createPlayer();
PlayerList* createPlayerList();
Team* createTeam();
TeamList* createTeamList();
void addPlayer(PlayerList**, Player*);
void addTeam(TeamList**, Team*);
void delPlayerTeam(PlayerList**);
void delTeamList(TeamList**);

TeamList* Input();