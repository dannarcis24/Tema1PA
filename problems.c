#include "libs.h"
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