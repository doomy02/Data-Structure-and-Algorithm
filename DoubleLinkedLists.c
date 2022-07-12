#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
    int key;
    struct list *next, *prev;
} nodeT;

void fprint(nodeT *first)
{
    printf("Frontwards DLL is: ");
    for(nodeT *a = first; a != NULL; a = a -> next)
        printf("%d ", a -> key);
    printf("\n");
}

void bprint(nodeT *last)
{
    printf("Backwards DLL is: ");
    for(nodeT *a = last; a != NULL; a = a -> prev)
        printf("%d ", a -> key);
    printf("\n");
}

void insert_first(nodeT **first, nodeT **last, int x)
{
    nodeT *p = (nodeT*)malloc(sizeof(nodeT));
    p -> key = x;
    p -> next = p -> prev = NULL;

    if(*first == NULL)
        *first = *last = p;
    else
    {
        p -> next = *first;
        (*first) -> prev = p;
        *first = p;
    }
}

void insert_last(nodeT **first, nodeT **last, int x)
{
    nodeT *p = (nodeT*)malloc(sizeof(nodeT));
    p -> key = x;
    p -> next = p -> prev = NULL;

    if(*first == NULL)
        *first = *last = p;
    else
    {
        p -> prev = *last;
        (*last) -> next = p;
        *last = p;
    }
}

void insert_after(nodeT **first, nodeT **last, int x, int after)
{
    nodeT *p = (nodeT*)malloc(sizeof(nodeT));
    p -> key = x;
    p -> next = p -> prev = NULL;
    nodeT *q = *first;

    while(q != NULL)
    {
        if(q -> key == after)
            break;
        q = q -> next;
    }

    if(q != NULL)
    {
        p -> prev = q;
        p -> next = q -> next;
        if(q -> next != NULL)
            q -> next -> prev = p;
        q -> next = p;
        if(*last == q)
            *last = p;
    }
}

void insert_before(nodeT **first, nodeT **last, int x, int before)
{
    nodeT *p = (nodeT*)malloc(sizeof(nodeT));
    p -> key = x;
    p -> next = p -> prev = NULL;
    nodeT *q = *first;

    while(q != NULL)
    {
        if(q -> key == before)
            break;
        q = q -> next;
    }

    if(q != NULL)
    {
        p -> prev = q -> prev;
        p -> next = q;
        if(q -> prev != NULL)
            p -> prev -> next = p;
        q -> prev = p;
        if(*first == q)
            *first = p;

    }
}

void search(nodeT **first, nodeT **last, int x)
{
    int k = 1;
    nodeT *q = *first;

    while(q != NULL)
    {
        if(q -> key == x)
        {
            printf("\n%d node is at: %d", x, k);
            return 0;
        }
        else
        {
            q = q -> next;
            k++;
        }
    }
}

void delete_first(nodeT **first, nodeT **last)
{
    nodeT *q = *first;
    nodeT *p = NULL;

    if(q == NULL)
    {
        puts("EMPTY DLL!");
        return;
    }
    else
    {
        p = *first;
        *first = (*first) -> next;
        if(*first == NULL)
            *last = NULL;
        else
            (*first) -> prev = NULL;
        free(p);
    }
}

void delete_last(nodeT **first, nodeT **last)
{
    nodeT *p = NULL;
    nodeT *q = *first;

    if(q == NULL)
    {
        puts("EMPTY DLL!");
        return;
    }
    else
    {
        p = *last;
        *last = (*last) -> prev;
        if(*last == NULL)
            *first = NULL;
        else
            (*last) -> next = NULL;
        free(p);
    }
}

void delete_key(nodeT **first, nodeT **last, int x)
{
    nodeT *p = NULL;
    nodeT *q = *first;

    while(q != NULL)
    {
        if(q -> key == x)
            break;
        q = q -> next;
    }

    if(q != NULL)
    {
        if(q -> prev != NULL)
            q -> prev -> next = q -> next;
        else
            *first = q -> next;

        if(q -> next != NULL)
            q -> next -> prev = q -> prev;
        else
            *last = q -> prev;
        free(q);
    }
}

int main()
{
    nodeT *first = NULL;
    nodeT *last = NULL;

    insert_first(&first, &last, 10);
    insert_last(&first, &last, 20);
    insert_after(&first, &last, 30, 10);
    insert_before(&first, &last, 30, 10);
    delete_first(&first, &last);
    delete_last(&first, &last);
    delete_key(&first, &last, 20);

    fprint(first);
    bprint(last);

    search(&first, &last, 10);
}
