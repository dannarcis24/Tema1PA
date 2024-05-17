#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// APELUL PENTRU FUNCTIA DE CONSTRUIRE A UNUI SIR
char* readString(FILE*, int);

// TIPURILE DE STRUCT
//          (tipuri, liste inlantuite)
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
    float punctaj_echipa;
    PlayerList *lista_concurenti;
} Team;

typedef struct b{
    Team *echipa;
    struct b *next;
} TeamList;

// APELURILE PENTRU FUNCTIILE DE LISTE INLANTUITE 
//          (creare, adaugare la inceput, copiere si adaugare la inceput, stergerea unui element, stergere)
Player* createPlayer();
PlayerList* createPlayerList();
Team* createTeam();
TeamList* createTeamList();
void addPlayer(PlayerList**, Player*);
void addTeam(TeamList**, Team*);
void copyTeam(TeamList**, Team*);
void delTeamPoints(TeamList**, float);
void delPlayerTeam(PlayerList**);
void delTeamList(TeamList**);

// APELURI PENTRU ALTE FUNCTII
//        (generarea listei principale, afisarea echipelor)
TeamList* Input(char*, int*);
void writeTeams(TeamList*, char*);
void delTeams(TeamList**, int*);

// APELURI PENTRU FUNCTII CU DIVERSE CALCULE
int sumPoints(PlayerList*);
int twoPower(int);
void minimum(TeamList*, float*);
