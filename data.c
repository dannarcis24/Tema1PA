#include "tasks.h"
char *readString(FILE *f, int ok)
{
    char c;
    int k = 0;

    char *sir = (char *)malloc(sizeof(char));
    if (!sir)
    {
        printf("variabilei sir nu i s-a putut aloca memorie\n");
        exit(1);
    }

    fscanf(f, "%c", &c);
    while ((ok == 1 && c != '\n') || (ok == 0 && c != ' '))
    {
        sir[k++] = c;
        fscanf(f, "%c", &c);

        sir = (char *)realloc(sir, sizeof(char) * (k + 1));
        if (!sir)
        {
            printf("variabilei sir nu i s-a putut realoca memorie\n");
            exit(1);
        }

        if (feof(f))
            break;
    }
    sir[k] = '\0';

    return sir;
}

TeamList *Input(char *fisier, int *numar_echipe)
{
    FILE *f = fopen(fisier, "rt");
    if (!f)
    {
        printf("fisierul d.in nu s-a putut deschide\n");
        exit(1);
    }

    fscanf(f, "%d", numar_echipe);

    TeamList *lista_echipe = createTeamList();
    for (register int i = 0; i < *numar_echipe; i++)
    {
        Team *grup = createTeam();
        grup->lista_concurenti = createPlayerList();

        fscanf(f, "%d", &grup->numar_concurenti);
        fseek(f, 1L, SEEK_CUR);
        grup->nume_echipa = readString(f, 1);

        for (register int j = 0; j < grup->numar_concurenti; j++)
        {
            Player *jucator = createPlayer();

            jucator->nume = readString(f, 0);
            jucator->prenume = readString(f, 0);
            fscanf(f, "%d", &jucator->punctaj);
            fseek(f, 2L, SEEK_CUR);

            addPlayer(&grup->lista_concurenti, jucator);
        }
        addTeam(&lista_echipe, grup);
    }
    fclose(f);

    return lista_echipe;
}

void writeTeams(TeamList *list, char *fisier)
{
    FILE *f = fopen(fisier, "wt");
    if(!f)
    {
        printf("fisierul r.out nu s-a putut deschide");
        exit(1);
    }

    for(register TeamList* p = list; p; p = p->next)
        fprintf(f, "%s\n", p->echipa->nume_echipa);
        
    fclose(f);
}

int sumPoints(PlayerList *list)
{
    if(list)
        return list->concurent->punctaj + sumPoints(list->next);
    return 0;
}

int twoPower(int nr)
{
    if(nr == 1)
        return 1;
    else
        if(nr%2)
            return 0;
        else
            return twoPower(nr/2);
}

void minimum(TeamList *list, float *mi)
{
    if(list)
    {
        if(*mi > list->echipa->punctaj_echipa)
            *mi = list->echipa->punctaj_echipa;

        minimum(list->next, mi);
    }
}

void delTeams(TeamList **list, int *numar)
{
    for(register TeamList *p = *list; p; p = p->next)
        p->echipa->punctaj_echipa = 1.* sumPoints(p->echipa->lista_concurenti)/p->echipa->numar_concurenti;

    if(twoPower(*numar))
        return;

    while(!twoPower(*numar))
    {
        float mi = (*list)->echipa->punctaj_echipa;
        minimum((*list)->next, &mi);

        delTeamPoints(list, mi);
        (*numar)--;
    }   
}
