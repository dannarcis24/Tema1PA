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
    nod->height = -1;

    return nod;
}

int verifOrd(Team *elem1, Team *elem2)
{
    if(elem1->punctaj_echipa > elem2->punctaj_echipa)
        return 1;
    else
        if(elem1->punctaj_echipa < elem2->punctaj_echipa)
            return 0;
        else
            return (strcmp(elem1->nume_echipa, elem2->nume_echipa)>0 ? 1 : 0);
}

void addInBST(Tree *root, TeamList *elem)
{
    if(!root)
        return;

    if(verifOrd(((TeamList*)root->val)->echipa, elem->echipa))
        if(!root->left)
        {
            root->left = createTree();
            root->left->val = elem;
        }
        else
            addInBST(root->left, elem);
    else
        if(!root->right)
        {
            root->right = createTree();
            root->right->val = elem;
        }
        else
            addInBST(root->right, elem);
}

Tree* createBST(TeamList *list)
{
    Tree *root = createTree();
    root->val = list;

    for(register TeamList *p = list->next; p; p = p->next)
            addInBST(root, p);

    return root;
}

void writeTree(Tree *root, FILE *f)
{
    if(root)
    {
        writeTree(root->right, f);
        fprintf(f, "%-34s-  %.2f\n", ((TeamList*)root->val)->echipa->nume_echipa, ((TeamList*)root->val)->echipa->punctaj_echipa);
        writeTree(root->left, f);    
    }
}

void writeLevel2(Tree *root, int nivel, FILE *f)
{
    if(!root)
        return;

    if(!nivel)
        fprintf(f, "%s\n", ((TeamList*)((Tree*)root->val)->val)->echipa->nume_echipa);
    else
        if(nivel > 0)
            {
                nivel--;
                writeLevel2(root->right, nivel, f);
                writeLevel2(root->left, nivel, f);
            }
}

int height(Tree *root)
{
    if(!root)
        return -1;

    int hs, hd;
    hs = height(root->left);
    hd = height(root->right);

    return 1 + ((hs > hd) ? hs : hd);
}

void calcHeight(Tree *root)
{
    if(root)
    {
        calcHeight(root->left);
        calcHeight(root->right);

        root->height = height(root->left) - height(root->right);
    }
}

Tree* leftRotation(Tree *root)
{
    Tree *a = root->right;
    Tree *b = a->left;

    a->left = root;
    root->right = b;

    return a;
}

Tree* rightRotation(Tree *root)
{
    Tree *a = root->left;
    Tree *b = a->right;

    a->right = root;
    root->left = b;

    return a;
}

void createAVL(Tree **AVL, Tree *root)
{
    if(root)
    {
        createAVL(AVL, root->right);
        *AVL = addInAVL(*AVL, root);
        createAVL(AVL, root->left);
    }
}

Tree* addInAVL(Tree *AVL, Tree *elem)
{
    if(!AVL)
    {
        AVL = createTree();
        AVL->val = elem;
        
        return AVL;
    }
    
    if(verifOrd(((TeamList*)(((Tree*)AVL->val)->val))->echipa, ((TeamList*)elem->val)->echipa))
        AVL->left = addInAVL(AVL->left, elem);
    else
        AVL->right = addInAVL(AVL->right, elem);

    calcHeight(AVL);
    int dezechilibru = AVL->height;

    if(dezechilibru > 1 && verifOrd(((TeamList*)(((Tree*)AVL->val)->val))->echipa, ((TeamList*)elem->val)->echipa))
        return rightRotation(AVL);
    if(dezechilibru < -1 && !verifOrd(((TeamList*)(((Tree*)AVL->val)->val))->echipa, ((TeamList*)elem->val)->echipa))
        return leftRotation(AVL);
    if(dezechilibru > 1 && !verifOrd(((TeamList*)(((Tree*)AVL->val)->val))->echipa, ((TeamList*)elem->val)->echipa))
    {
        AVL->left = leftRotation(AVL->left);
        return rightRotation(AVL);
    }
    if(dezechilibru < -1 && verifOrd(((TeamList*)(((Tree*)AVL->val)->val))->echipa, ((TeamList*)elem->val)->echipa))
    {
        AVL->right = rightRotation(AVL->right);
        return leftRotation(AVL);
    }

    return AVL;
}

void delTree(Tree **root)
{
    if(*root)
    {
        delTree(&(*root)->left);
        delTree(&(*root)->right);

        free(*root);
        *root = NULL;
    }
}
