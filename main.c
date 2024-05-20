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

int main(int argc, char *argv[])
{
    errorInput(argc, argv);
    TeamList *lista_echipe = NULL, *lista_finala = NULL;
    Tree *root = NULL, *AVL = NULL;
    int numar_echipe = -1, x;

    FILE *task = fopen(argv[1], "rt");
    if(!task)
    {
        printf("nu s-a putut deschide fisierul %s\n", argv[1]);
        return 1;
    }
    for(register int i = 1; fscanf(task, "%d", &x) != EOF; i++)
        if(x) // != 0 se va executa task-ul, == 0 nu se va executa task-ul
            switch(i)
            {
                case 1:
                    task1(&lista_echipe, &numar_echipe, argv);
                    break;
                case 2:
                    task2(&lista_echipe, &numar_echipe, argv);
                    break;
                case 3:
                    task3(lista_echipe, &lista_finala, numar_echipe, argv);
                    break;
                case 4:
                    task4(lista_finala, &root, argv);
                    break;
                case 5:
                    task5(&AVL, root, argv);
                    break;
            }
    fclose(task);

    delTree(&root);
    delTree(&AVL);
    delTeamList(&lista_echipe, 1);  delTeamList(&lista_finala, 0);
    return 0;
}
