#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node *next;
}NodeT;

void print(NodeT *stack)
{
    if(stack == NULL)
        printf("EMPTY STACK!");
    else
    {
        for(NodeT *a = stack; a != NULL; a = a -> next)
            printf("%d ", a -> key);
    }
}

void push(NodeT **stack, int x) ///insert-first
{
    NodeT *p = (NodeT*)malloc(sizeof(NodeT));
    p -> key = x;
    p -> next = NULL;

    if(*stack == NULL)
        *stack = p;
    else
    {
        p -> next = *stack;
        *stack = p;
    }
}

int pop(NodeT **stack) ///delete-first
{
    NodeT *p;
    if(*stack == NULL)
        return -1;
    else
    {
        int v = (*stack) -> key;
        p = (*stack);
        (*stack) = (*stack) -> next;
        free(p);
        return v;
    }
}

int main()
{
    NodeT *stack = NULL;

    push(&stack, 3);
    push(&stack, 4);
    printf("Pop: %d\n", pop(&stack));

    print(stack);
    return 0;
}
