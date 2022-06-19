#include <stdio.h>
#include <stdlib.h>

int *generate(int n)
{
    int *a = calloc(n, sizeof(int));
    int c = 1, d = 10;
    for(int i = 0; i < n; i++)
        a[i] = rand() % d + 1;
    return a;
}

void interclasare(int *a,int n,int *b,int m,int *c)
{
    int i = 0,j = 0,k = 0;
    int *aux = calloc(n + m, sizeof(int));
    while(i < n && j < m)
    {
        if(a[i] < b[j])
        {
            aux[k++] = a[i];
            i++;
        }
        else
        {
            aux[k++] = b[j];
            j++;
        }
    }
    for(; i < n; i++)
        aux[k++] = a[i];
    for(; j < m; j++)
        aux[k++] = b[j];
    for(int p = 0; p < n + m; p++)
        c[p] = aux[p];
    free(aux);
}

void mergesort(int *a, int p ,int q, int n)
{
    if(p < q)
    {
        int m = (p + q) / 2;
        mergesort(a, p, m, n);
        mergesort(a, m + 1, q, n);
        interclasare(a + p, m - p + 1, a + m + 1, q - m, a + p);
    }
}

int verificare(int *a, int n)
{
    for(int i = 0;i < n - 1;i++)
        if(a[i] > a[i + 1])
            return -1;
    return 1;
}

int main()
{
    int n = 10;
    int *a = generate(n);

    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    mergesort(a, 0, n - 1, n);
    printf("%d",verificare(a,n));

    return 0;
}
