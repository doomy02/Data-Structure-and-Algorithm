#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int key;
    struct node *next;
} NodeT;

void print(NodeT *first)
{
    printf("Lista este: ");
    for(NodeT *a = first; a != NULL; a = a -> next)
        printf("%d ", a -> key);
}

void insert_first(NodeT **first, NodeT **last, int x)
{
    NodeT *p = (NodeT*)malloc(sizeof(NodeT));
    p -> key = x;
    p -> next = NULL;

    if(*first == NULL)
    {
        *first = p;
        *last = p;
    }
    else
    {
        p -> next = *first;
        *first = p;
    }
}

void insert_last(NodeT **first, NodeT **last, int x)
{
    NodeT *p = (NodeT*)malloc(sizeof(NodeT));
    p -> key = x;
    p -> next = NULL;

    if(*first == NULL)
    {
        *first = p;
        *last = p;
    }
    else
    {
        (*last) -> next = p;
        *last = p;
    }
}

void insert_after(NodeT **first, NodeT **last, int x, int after)
{
    NodeT *p = (NodeT*)malloc(sizeof(NodeT));
    NodeT *q = *first;
    p -> key = x;

    while(q != NULL)
    {
        if(q -> key == after)
            break;
        q = q -> next;
    }

    if(q != NULL)
    {
        p -> next = q -> next;
        q -> next = p;
        if(p == *last)
            (*last) = p;
    }
}

void insert_before(NodeT **first, NodeT **last, int x, int before)
{
    NodeT *p = (NodeT*)malloc(sizeof(NodeT));
    NodeT *q = *first;
    NodeT *q1 = NULL;
    p -> key = x;

    while(q != NULL)
    {
        if(q -> key == before)
            break;
        q1 = q;
        q = q -> next;
    }

    if(q != NULL)
    {
        if(q == *first)
        {
            p -> next = (*first);
            (*first) = p;
        }
        else
        {
            q1 -> next = p;
            p -> next = q;
        }
    }
}

void search(NodeT **first, NodeT **last, int x)
{
    int k = 1;
    NodeT *p = *first;
    while(p != NULL)
    {
        if(p -> key == x)
        {
            printf("\nNodul %d se afla in lista pe pozitia %d.", x, k);
            return 0;
        }
        else
        {
            k++;
            p = p -> next;
        }
    }
    printf("\nNodul %d nu se afla in lista!", x);
}

void delete_first(NodeT **first, NodeT **last)
{
    int k;
    NodeT *p;
    if(*first != NULL)
    {
        p = *first;
        k = p -> key;
        (*first) = (*first) -> next;
        free(p);

        if(*first == NULL)
            *last = NULL;
    }
    printf("Nodul sters este %d\n", k);
}

void delete_last(NodeT **first, NodeT **last)
{
    int k;
    NodeT *p, *q;
    q = NULL;
    p = *first;

    if(p != NULL)
    {
        while(p != *last)
        {
            q = p;
            p = p -> next;
        }
        if(p == *first)
            *first = *last = NULL;
        else
        {
            q -> next = NULL;
            *last = q;
        }
        k = p -> key;
        free(p);
    }
    printf("Nodul sters este %d\n", k);
}

void delete_key(NodeT **first, NodeT **last, int x)
{
    NodeT *q1 = NULL;
    NodeT *q = *first;

    while(q != NULL)
    {
        if(q -> key == x)
            break;
        q = q -> next;
    }
    if(q != NULL)
    {
        if(q == *first)
        {
            *first = (*first) -> next;
            free(q);
            if(*first == NULL)
                *last = NULL;
        }
        else
        {
            q1 -> next = q -> next;
            if(q == *last)
                *last = q1;
            free(q);
        }
    }
}

int main()
{
    NodeT *first = NULL;
    NodeT *last = NULL;

    insert_first(&first, &last, 3);
    insert_last(&first, &last, 2);
    insert_after(&first, &last, 1, 3);
    insert_before(&first, &last, 6, 1);
    delete_first(&first, &last);
    delete_last(&first, &last);
    delete_key(&first, &last, 6);
    print(first);

    search(&first, &last, 10);

    return 0;
}
