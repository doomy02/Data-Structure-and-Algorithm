#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int key;
    struct node *left, *right;
}NodeT;

NodeT *create(FILE *fp)
{
    NodeT *p;
    int x;
    fscanf(fp, "%d", &x);

    if(x == 0)
        return 0;
    else
    {
        p = (NodeT*)malloc(sizeof(NodeT));
        if(p == NULL)
            return -1;
        p -> key = x;
        p -> left = create(fp);
        p -> right = create(fp);
    }
    return p;
}

void preordine(NodeT *p)
{
    if(p != NULL)
    {
        printf("%d ", p -> key);
        preordine(p -> left);
        preordine(p -> right);
    }
}

void postordine(NodeT *p)
{
    if(p != NULL)
    {
        postordine(p -> left);
        postordine(p -> right);
        printf("%d ", p -> key);
    }
}

void inordine(NodeT *p)
{
    if(p != NULL)
    {
        inordine(p -> left);
        printf("%d ", p -> key);
        inordine(p -> right);
    }
}

int leaves(NodeT *p)
{
    if(p == NULL)
        return 0;
    else if(p -> left == NULL && p -> right == NULL)
        return 1;
    else
        return leaves(p -> left) + leaves(p -> right);
}

int internals(NodeT *p)
{
    if(p == NULL)
        return 0;
    else if(p -> left == NULL && p -> right == NULL)
        return 0;
    else
        return 1 + internals(p -> left) + internals(p -> right);
}

int nodes(NodeT *p)
{
    if(p == NULL)
        return 0;
    else
        return 1 + nodes(p -> left) + nodes(p -> right);
}

int MAX(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int height(NodeT *p)
{
    if(p == NULL)
        return -1;
    else
        return 1 + MAX(height(p -> left), height(p -> right));
}

NodeT *search(NodeT *p, int x)
{
    if(p != NULL)
    {
        if(p -> key == x)
            return p;
        NodeT *a = search(p -> left, x);
        if(a == NULL)
        {
            NodeT *b = search(p -> right, x);
            if(b == NULL)
                return NULL;
            else
                return b;
        }
        else
            return a;
    }
    return NULL;
}

int main()
{
    FILE* fp = fopen("arbore.txt", "r");
    if(!fp)
        return -1;
    NodeT *root = create(fp);

    printf("Preordine: ");
    preordine(root);

    printf("\nPostordine: ");
    postordine(root);

    printf("\nInordine: ");
    inordine(root);

    int res = nodes(root);
    printf("\n\nNumer of nodes: %d", res);

    int res1 = leaves(root);
    printf("\nNumber of leaf nodes: %d", res1);

    int res2 = internals(root);
    printf("\nNumber of internal nodes: %d", res2);

    int res3 = height(root);
    printf("\nHeight: %d", res3);

    int res4 = search(root, 7);
    if(res4 != NULL)
        printf("\nNode found!");
    else
        printf("\nNode not found!");

    fclose(fp);
    return 0;
}
