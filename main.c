#include "tasks.h"

void errorInput(int argc, char *argv[])
{
    if(argc != 4)
    {
        printf("datele de intrare trebuie sa fie la numar de trei fisiere: primele doua de intrare si ultimul de iesire\n");
        exit(1);
    }
    if(!strstr(argv[1], "c.in"))
    {
        printf("primul fisier trebuie sa fie c.in\n");
        exit(1);
    }
    if(!strstr(argv[2], "d.in"))
    {
        printf("al doilea fisier trebuie sa fie d.in\n");
        exit(1);
    }
    if(!strstr(argv[3], ".out"))
    {
        printf("al treilea fisier trebuie sa fie r.out\n");
        exit(1);
    }
}

int* taskInput(char *fisier)
{
    FILE *f = fopen(fisier, "rt");
    if(!f)
    {
        printf("nu s-a putut deschide fisierul c.in\n");
        exit(1);
    }

    int *v = (int*)malloc(sizeof(int) * 5);
    if(!v)
    {
        printf("variabilei v nu i s-a putut aloca memorie\n");
        exit(1);
    }

    for(register int  i = 0; i < 5; i++)
        fscanf(f, "%d", &v[i]);
    fclose(f);

    if(!v[0])
    {
        printf("nu exista date de intrare\n");
        free(v);
        exit(1);
    }

    return v;
}

int main(int argc, char *argv[])
{
    errorInput(argc, argv);
    int *task = taskInput(argv[1]);

    TeamList *lista_echipe = NULL;
    task1(&lista_echipe, argv);

    delTeamList(&lista_echipe);
    return 0;
}