#include<stdio.h>
#include<stdlib.h>
#define M 10

typedef struct node
{
    int key;
    struct node *next;
} NodeT;

int hash_f(int key)
{
    int aux = key % M;
    if(aux < 0)
        aux += M;
    return aux;
}

int print(NodeT *hTable[M])
{
    for(int i = 0; i < M; i++)
    {
        NodeT *k = hTable[i];
        printf("%d: ", i);
        while(k != NULL)
        {
            printf("[%d] -> ", k -> key);
            k = k -> next;
        }
        printf("\n");
    }
}

void insert(NodeT *hTable[M], int x)
{
    NodeT *p = (NodeT*)malloc(sizeof(NodeT));
    p -> key = x;
    p -> next = NULL;

    int hcode = hash_f(x);
    if(hTable[hcode] == NULL)
        hTable[hcode] = p;
    else
    {
        printf("Collion at %d!\n", hcode);
        p -> next = hTable[hcode];
        hTable[hcode] = p;

    }
}

NodeT *search(NodeT *hTable[M], int x)
{
    int hcode = hash_f(x);
    if(hTable[hcode] == NULL)
    {
        printf("The %dth collumn is empty!", hcode);
        return NULL;
    }
    else
    {
        NodeT *p = hTable[hcode];
        while(p != NULL)
        {
            if(p -> key == x)
            {
                printf("%d has been found!", x);
                return p;
            }
            p = p -> next;
        }
        printf("%d has not been found!", x);
        return NULL;
    }
}

void del(NodeT *hTable[M], int x)
{
    int hcode = hash_f(x);
    NodeT *p = search(hTable, x);

    if(p == NULL)
        return;
    else if(p == hTable[hcode])
    {
        hTable[hcode] = p -> next;
        free(p);
        return;
    }
    else
    {
        NodeT *pred = hTable[hcode];
        while(pred -> next -> key != x)
            pred = pred -> next;

        pred -> next = p -> next;
        free(p);

        return;
    }
}

int main()
{
    NodeT *hTable[M];
    for(int i = 0; i < M; i++)
        hTable[i] = NULL;

    printf("INITIAL HASH TABLE IS: \n");
    insert(hTable, 20);
    insert(hTable, 15);
    insert(hTable, 40);
    insert(hTable, 60);
    print(hTable);
    printf("\n\n");

    printf("SEARCHES: \n");
    search(hTable, 20);
    printf("\n\n");

    printf("POST DELETION HASH TABLE: ");
    del(hTable, 20);
    print(hTable);

    return 0;
}
