#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node *next;
    struct node *prev;
}NodeDL;

void print_forwards(NodeDL **first, NodeDL **last)
{
    printf("Double linked list is: ");
    for(NodeDL *a = *first; a != NULL; a = a -> next)
        printf("%d ", a -> key);
}

void print_backwards(NodeDL **first, NodeDL **last)
{
    printf("Double linked list is: ");
    for(NodeDL *a = *last; a != NULL; a = a -> prev)
        printf("%d ", a -> key);
}

void insert_first(NodeDL **first, NodeDL **last, int x)
{
    NodeDL *p = (NodeDL*)malloc(sizeof(NodeDL));
    p -> key = x;
    p -> next = NULL;
    p -> prev = NULL;

    if(*first == NULL)
        *first = *last = p;
    else
    {
        p -> next = *first;
        (*first) -> prev = p;
        *first = p;
    }
}

void insert_last(NodeDL **first, NodeDL **last, int x)
{
    NodeDL *p = (NodeDL*)malloc(sizeof(NodeDL));
    p -> key = x;
    p -> next = NULL;
    p -> prev = NULL;

    if(*first == NULL)
        *first = *last = p;
    else
    {
        p -> prev = *last;
        (*last) -> next = p;
        *last = p;
    }
}

void insert_after(NodeDL **first, NodeDL **last, int x, int after)
{
    NodeDL *p = (NodeDL*)malloc(sizeof(NodeDL));
    p -> key = x;
    p -> next = NULL;
    p -> prev = NULL;

    NodeDL *q = *first;

    if(q == NULL)
        *first = *last = p;
    else
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

void insert_before(NodeDL **first, NodeDL **last, int x, int before)
{
    NodeDL *p = (NodeDL*)malloc(sizeof(NodeDL));
    p -> key = x;
    p -> next = NULL;
    p -> prev = NULL;

    NodeDL *q = *first;

    if(q == NULL)
        *first = *last = p;
    else
    {
        p -> next = q;
        p -> prev = q -> prev;
        if(q -> prev != NULL)
            q -> prev -> next = p;
        q -> prev = p;
        if(*first == q)
            *first = p;
    }
}

int search(NodeDL **first, NodeDL **last, int x)
{
    NodeDL *q = *first;
    int k = 0;

    if(q == NULL)
        return -1;
    else
    {
        while(q != NULL)
        {
            if(q -> key == x)
                break;
            q = q -> next;
                k++;
        }
    }
    return k;
}

void delete_first(NodeDL **first, NodeDL **last)
{
    NodeDL *q = *first;
    NodeDL *p = NULL;

    if(q == NULL)
    {
        puts("EMPTY DLS!");
        return;
    }
    else
    {
        p = *first;
        *first = (*first) -> next;
        if(*first == NULL)
            *last == NULL;
        else
            (*first) -> prev = NULL;
        free(p);
    }
}

void delete_last(NodeDL **first, NodeDL **last)
{
    NodeDL *q = *last;
    NodeDL *p = NULL;

    if(q == NULL)
    {
        puts("EMPTY DLS!");
        return;
    }
    else
    {
        p = *last;
        *last = (*last) -> prev;
        if(*last == NULL)
            *first == NULL;
        else
            (*last) -> next = NULL;
        free(p);
    }
}

void delete_key(NodeDL **first, NodeDL **last, int x)
{
    NodeDL *q = *first;
    NodeDL *p = NULL;

    while(q != NULL)
    {
        if(q -> key == x)
            break;
        q = q -> next;
    }

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

int main()
{
    NodeDL *first = NULL;
    NodeDL *last = NULL;

    insert_first(&first, &last, 3);
    insert_first(&first, &last, 7);
    insert_last(&first, &last, 4);
    insert_first(&first, &last, 10);
    insert_after(&first, &last, 4, 10);
    insert_before(&first, &last, 999, 10);
    print_forwards(&first, &last);
    printf("\n");
    print_backwards(&first, &last);
    printf("\n");

    printf("\n%d\n", search(&first, &last, 3));

    delete_last(&first, &last);
    delete_first(&first, &last);
    delete_key(&first, &last, 4);
    print_forwards(&first, &last);
    printf("\n");

    return 0;
}
