#include <stdio.h>
#include <stdlib.h>

int ver(int v[], int n)
{
    if(n == 0)
        return 1;
    for(int i = 0; i< n - 1; i++)
        for(int j = i + 1; j < n; j++)
            if(v[i] >= v[j])
                return 0;
    return 1;
}

void BT(int v[], int k, int n, int nf)
{
    for(int i = 1; i <= n; i++)
    {
        v[k] = i;
        if(ver(v, k + 1))
            if(k == nf - 1)
                print(v, k + 1);
            else
                BT(v, k + 1, n, nf);
    }
}

void print(int v[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int main()
{
    int n = 5, m = 4;
    int *v = calloc(n, sizeof(int));
    BT(v, 0, n, m);

    return 0;
}
