#include "tasks.h"

void WriteTeams(TeamList *list)
{
    FILE *f = fopen("out/r.out", "wt");
    if(!f)
    {
        printf("fisierul r.out nu s-a putut deschide");
        exit(1);
    }

    for(register TeamList* p = list; p; p = p->next)
        fprintf(f, "%s\n", p->echipa->nume_echipa);
        
    fclose(f);
}

int main()
{
    TeamList *lista = Input();
    WriteTeams(lista);

    delTeamList(&lista);
    return 0;
}