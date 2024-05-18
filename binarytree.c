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

Tree* createBinarySearchTree(TeamList *list)
{
    Tree *root = createTree();
    root->val = list;

    for(register TeamList *p = list->next; p; p = p->next)
            addInTree(root, p);

    return root;
}

void writeTree(Tree *root, FILE *f)
{
    if(root)
    {
        writeTree(root->right, f);
        fprintf(f, "%-34s-  %.2f\n", root->val->echipa->nume_echipa, root->val->echipa->punctaj_echipa);
        writeTree(root->left, f);    
    }
}

void writeLevel2(Tree *root, int nivel, FILE *f)
{
    if(!nivel)
        fprintf(f, "%s\n", root->val->echipa->nume_echipa);
    else
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

Tree* isBalanced(Tree *root)
{
    if(!root)
        return NULL;

    if(root->height > 1 || root->height < -1)
        return root;
    
    Tree *left = isBalanced(root->left);
    if(left)
        return left;
    
    Tree *right = isBalanced(root->right);
    return right;
}

Tree* searchFather(Tree *root, Tree *nod)
{
    if(!root)
        return NULL;

    if(root->left == nod || root->right == nod)
        return root;

    if(root->left)
        return searchFather(root->left, nod);
    if(root->right)
        return searchFather(root->right, nod);
}

Tree* leftRotation(Tree *root)
{
    Tree *a = root->right;
    Tree *b = root->left;

    a->left = root;
    root->right = b;

    return a;
}

Tree* rightRotation(Tree *root)
{
    Tree *a = root->left;
    Tree *b = root->right;

    a->right = root;
    root->left = b;

    return a;
}

void createAVL(Tree **root) {
    if (!(*root))
        return;

    calcHeight(*root);
    Tree *nod = NULL;
    while ((nod = isBalanced(*root))) {
        Tree *tata = searchFather(*root, nod);

        Tree *rotatie = NULL;
        if(nod->height > 1) 
            rotatie = rightRotation(nod);
        else 
            if(nod->height < -1) 
                rotatie = leftRotation(nod);

        if (tata == NULL) 
            *root = rotatie;
        else
            if (tata->left == nod)
                tata->left = rotatie;
            else 
                tata->right = rotatie;

        calcHeight(*root);
    }
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
