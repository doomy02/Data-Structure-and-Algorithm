#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
typedef struct
{
    int n;
    int m;
    int **a;
} graf;

void read(graf *g)
{
    FILE *f = fopen("graf.txt", "r");
    fscanf(f, "%d %d", &g -> n, &g -> m);
    g -> a = calloc(g -> n, sizeof(int*));
    for(int i = 0; i < g -> m; i++)
        g -> a[i] = calloc(g -> n, sizeof(int));

    for(int i = 0; i < g -> m; i++)
    {
        int u, v;
        fscanf(f, "%d %d", &u, &v);
        g -> a[u][v] = 1;
    }
    fclose(f);
}
void bfs(int s,graf *g)
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
        for(int i = 0; i < g -> n; i++)
            if(g -> a[v][i] == 1 && vizitat[i] == 0)
            {
                coada[tail++] = i;
                vizitat[i] = 1;
            }
    }
    free(coada);
    free(vizitat);
}
int main()
{
    graf g;
    read(&g);
    bfs(0,&g);
//    for(int i=0; i<g.n; i++)
//    {
//        for(int j=0; j<g.n; j++)
//            printf("%d ",g.a[i][j]);
//        printf("\n");
//    }
    for(int i=0; i<g.n; i++)
        free(g.a[i]);
    free(g.a);
    return 0;
}
