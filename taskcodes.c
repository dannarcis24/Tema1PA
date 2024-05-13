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
// void task3()
// void task4()
// void task5()
