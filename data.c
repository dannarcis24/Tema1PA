#include "tasks.h"
char *citireSir(FILE *f, int ok)
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

TeamList *Input()
{
    FILE *f = fopen("date/t1/d.in", "rt");
    if (!f)
    {
        printf("fisierul d.in nu s-a putut deschide\n");
        exit(1);
    }

    int numar_echipe;
    fscanf(f, "%d", &numar_echipe);

    TeamList *lista_echipe = createTeamList();
    for (register int i = 0; i < numar_echipe; i++)
    {
        Team *grup = createTeam();
        grup->lista_concurenti = createPlayerList();

        fscanf(f, "%d", &grup->numar_concurenti);
        fseek(f, 1L, SEEK_CUR);
        grup->nume_echipa = citireSir(f, 1);

        for (register int j = 0; j < grup->numar_concurenti; j++)
        {
            Player *jucator = createPlayer();

            jucator->nume = citireSir(f, 0);
            jucator->prenume = citireSir(f, 0);
            fscanf(f, "%d", &jucator->punctaj);
            fseek(f, 2L, SEEK_CUR);

            addPlayer(&grup->lista_concurenti, jucator);
        }
        addTeam(&lista_echipe, grup);
    }
    fclose(f);

    return lista_echipe;
}