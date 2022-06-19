#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int n,m;
    int **a;
} graf;

typedef struct Tlist
{
    int curent;
    struct Tlist *next;
} list;

void read(graf *g)
{
    FILE *f = fopen("graf.txt", "r");
    fscanf(f, "%d %d", &g -> n, &g -> m);
    g -> a = calloc(g -> n, sizeof(int*));

    for(int i = 0; i < g -> m; i++)
    {
        int u, v;
        fscanf(f, "%d %d", &u, &v);
        list *p = calloc(1, sizeof(list));
        p -> curent = v;
        p -> next = g -> a[u];
        g -> a[u] = p;
    }
    fclose(f);
}

void BFS(int s, graf *g)
{
    int *coada = calloc(g -> n, sizeof(int));
    int *vizitat = calloc(g -> n, sizeof(int));
    int head = 0, tail = 0;

    coada[tail++] = s;
    vizitat[s] = 1;
    while(head != tail)
    {
        int v = coada[head++];
        printf("%d ", v);
        vizitat[v] = 1;
        for(list *a = g -> a[v]; a != NULL; a++)
            if(vizitat[a -> curent] == 0)
            {
                coada[tail++] = a -> curent;
                vizitat[a -> curent] = 1;
            }
    }
    free(coada);
    free(vizitat);
}

int main()
{
    graf g;
    read(&g);
    BFS(5, &g);
    return 0;
}
