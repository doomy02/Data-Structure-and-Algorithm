#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 10

typedef struct _queue
{
    int vec[CAPACITY];
    int head, tail, size;
}queue;

void print(queue *Q)
{
    if(Q -> size == 0)
        return;

    if(Q -> tail > Q -> head)
    {
        for(int i = Q -> head; i < Q -> tail; i++)
            printf("%d ", Q -> vec[i]);
    }
    else
    {
        for(int i = Q -> head; i < CAPACITY; i++)
            printf("%d ", Q -> vec[i]);
        for(int i = 0; i < Q -> tail; i++)
            printf("%d ", Q -> vec[i]);
    }
}

void enqueue(queue *Q, int x)
{
    if(Q -> size == CAPACITY)
    {
        puts("FULL QUEUE!");
        return;
    }
    else
    {
        Q -> vec[Q -> tail] = x;
        (Q -> tail)++;
        if(Q -> tail == CAPACITY)
            Q -> tail = 0;
        (Q -> size)++;
    }
}

int dequeue(queue *Q)
{
    if(Q -> size == 0)
    {
        puts("EMPTY QUEUE!");
        return;
    }
    else
    {
        int x = Q -> vec[Q -> head];
        (Q -> head)++;
        if(Q -> head == CAPACITY)
            Q -> head = 0;
        (Q -> size)--;
        return x;
        free(x);
    }
}

int main()
{
    queue Q;
    Q.size = Q.head = Q.tail = 0;

    enqueue(&Q, 3);
    enqueue(&Q, 6);
    print(&Q);
    printf("\n");
    printf("Dequeued: %d\n",dequeue(&Q));
    printf("Dequeued: %d\n",dequeue(&Q));
    print(&Q);

    return 0;
}
