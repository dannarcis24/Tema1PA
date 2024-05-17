#include "tasks.h"
void task1(TeamList **list, int *numar, char *argv[])
{
    *list = Input(argv[2], numar);
    writeTeams(*list, argv[3]);
}

void task2(TeamList **list, int *numar, char *argv[])
{
    delTeams(list, numar);
    writeTeams(*list, argv[3]);
}

void task3(TeamList *list, TeamList **list_final, int numar, char *argv[])
{
    *list_final = top8(list, numar, argv);
}

void task4(TeamList* list, Tree **root, char *argv[])
{
    *root = createBinarySearchTree(list);
    FILE *f = fopen(argv[3], "at");
    if(!f)
    {
        printf("nu s-a putut deschide fisierul %s\n", argv[3]);
        exit(1);
    }

    fprintf(f, "\nTOP 8 TEAMS:\n");
    writeTree(*root, f);
    fclose(f);
}
// void task5()
