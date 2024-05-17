#include "structs.h"
Tree* createTree()
{
    Tree *nod = (Tree*)malloc(sizeof(Tree));
    if(!nod)
    {
        printf("variabilei nod nu i s-a putut aloca memorie");
        exit(1);
    }
    
    nod->left = nod->right = NULL;
    nod->val = NULL;

    return nod;
}

int verifOrd(Team *elem1, Team *elem2)
{
    if(elem1->punctaj_echipa < elem2->punctaj_echipa)
        return 1;
    else
        if(elem1->punctaj_echipa > elem2->punctaj_echipa)
            return 0;
        else
            return (strcmp(elem1->nume_echipa, elem2->nume_echipa)<0 ? 1 : 0);
}

void addInTree(Tree *root, TeamList *elem)
{
    if(!root)
        return;

    if(verifOrd(root->val->echipa, elem->echipa))
        if(!root->left)
        {
            root->left = createTree();
            root->left->val = elem;
        }
        else
            addInTree(root->left, elem);
    else
        if(!root->right)
        {
            root->right = createTree();
            root->right->val = elem;
        }
        else
            addInTree(root->right, elem);
}

TeamList* whoIsRoot(TeamList *list)
{
    TeamList *root = list;

    for(register TeamList *p = list->next; p; p = p->next)
        if(verifOrd(root->echipa, p->echipa))
            root = p;
    
    return root;
}

Tree* createBinarySearchTree(TeamList *list)
{
    Tree *root = createTree();
    root->val = whoIsRoot(list);

    for(register TeamList *p = list; p; p = p->next)
        if(root->val != p)
            addInTree(root, p);

    return root;
}

void writeTree(Tree *root, FILE *f)
{
    if(root)
    {
        writeTree(root->left, f);
        fprintf(f, "%-34s-  %.2f\n", root->val->echipa->nume_echipa, root->val->echipa->punctaj_echipa);
        writeTree(root->right, f);    
    }
}

void delTree(Tree **root)
{
    if(*root)
    {
        delTree(&(*root)->left);
        delTree(&(*root)->right);

        free(*root);
    }
}