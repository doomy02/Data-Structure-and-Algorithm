#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
typedef struct Tlist
{
    int curent;
    struct Tlist *next;
} list;
typedef struct
{
    int n;
    int m;
    list **a;
    int *vizitat;
    int *parinte;
    int *fin;
} graf;
list *listanoua(int nod)
{
    list *p=calloc(1,sizeof(list));
    p->curent=nod;
    p->next=NULL;
    return p;
}
void read(graf *g)
{
    FILE *f = fopen("graf.txt", "r");
    fscanf(f, "%d %d", &g -> n, &g -> m);
    g -> a = calloc(g -> n, sizeof(list*));
    g -> parinte = calloc(g -> n, sizeof(int));
    g -> vizitat = calloc(g -> n, sizeof(int));

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

void DFS_REC(int s, graf *g, int *k)
{
    printf("%d ", s);
    (*k)++;
    g -> vizitat[s] = *k;
    for(list *a = g -> a[s]; a != NULL; a = a -> next)
    {
        if(g -> vizitat[a -> curent] == 0)
        {
            g -> parinte[a -> curent] = s;
            DFS_REC(a -> curent, g, k);
        }
    }
    (*k)++;
    g -> fin[s] = *k;
}
void dfs(graf *g)
{
    int k = 0;
    for(int i = 0; i < g -> n; i++)
    {
        if(g -> vizitat[i] == 0)
        {
            g -> parinte[i] = 1;
            DFS_REC(i, g, &k);
            printf("\n");
        }
    }
}
void cicluri(graf g)
{
    int *ciclu=calloc(g.n,sizeof(int));
    for(int i=0;i<g.n;i++)
        if(g.fin[i]-g.vizitat[i])
    for(int i=0;i<g.n;i++)
        printf("%d ",ciclu[i]);
}
int main()
{
    graf g;
    read(&g);
    dfs(&g);

    for(int i=0;i<g.n;i++)
        printf("%d ",g.parinte[i]);
    return 0;
}
