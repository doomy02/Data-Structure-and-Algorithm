#include <stdio.h>
#include <stdlib.h>

typedef struct _list
{
    int curent;
    struct _list *next;
} list;

typedef struct
{
    int n, m;
    int **a;
    int *parinte, *vizitat;
} graf;

void read(graf *g)
{
    FILE *f = fopen("graf.txt", "r");
    fscanf(f, "%d %d", &g -> n, &g -> m);
    g -> a = calloc(g -> n, sizeof(list*));
    g -> vizitat = calloc(g -> n, sizeof(int));
    g -> parinte = calloc(g -> n, sizeof(int));

    for(int i = 0; i < g -> m; i++)
    {
        int u, v;
        fscanf(f, "%d %d", &u, &v);
        list *p = calloc(1, sizeof(int));
        p -> curent = u;
        p -> next = g -> a[u];
        g -> a[u] = p;

        p -> curent = v;
        p -> next = g -> a[v];
        g -> a[v] = p;
    }
    fclose(f);
}

void DFS(int s, graf *g)
{
    int *stack = calloc(g -> n, sizeof(int));
    int *vizitat = calloc(g -> n, sizeof(int));
    int top = 0;

    stack[top++] = s;
    vizitat[s] = 1;

    while(top != 0)
    {
        int v = stack[--top];
        printf("%d ", v);
        for(list *a = g -> a[v]; a != NULL; a = a -> next)
            if(g -> vizitat[a -> curent] == 0)
        {
            g -> vizitat[a -> curent] = 1;
            g -> parinte[a -> curent] = v;
            stack[top++] = a -> curent;
        }
    }
    free(vizitat);
    free(stack);
}

int main()
{
    graf g;
    read(&g);
    DFS(0, &g);

    return 0;
}
