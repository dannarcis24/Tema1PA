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

void task3(TeamList *list, Node **list_final, int numar, char *argv[])
{
    *list_final = top8(list, numar, argv);
}
// void task4()
// void task5()
