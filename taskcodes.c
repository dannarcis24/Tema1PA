#include "tasks.h"
void task1(TeamList **list, char *argv[])
{
    *list = Input(argv[2]);
    writeTeams(*list, argv[3]);
}

// void task2()
// void task3()
// void task4()