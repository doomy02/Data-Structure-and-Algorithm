#include <stdio.h>
#include <stdlib.h>

int ver(int *v, int n)
{
    if(n == 0)
        return 1;
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
            if(v[i] == v[j])
                return 0;
    return 1;
}

void BT(int *v, int k, int n)
{
    print(v, k, n);
    for(int i = 1; i <= n; i++)
    {
        v[k] = i;
        if(k < n)
            BT(v, k + 1, n);
    }
}

void print(int *v, int n, int m)
{
   for(int i = 0; i < n; i++)
        printf("%d ", v[i]);
   if(ver(v, n) == 1 && m == n)
        printf("-solution!");
   printf("\n");
}

void colocviu(int *v, int n, int a, int b, int x, int k)
{
    print(v, x, n);
    for(int i = a; i <= b; i++)
    {
        v[k] = i;
        if(k < n)
                colocviu(v, n, a, b, x, k + 1);
    }
}

int main()
{
    int n = 3;
    int *v = calloc(n, sizeof(int));
    colocviu(v, 2, 2, 4, 2, 0);

    return 0;
}
