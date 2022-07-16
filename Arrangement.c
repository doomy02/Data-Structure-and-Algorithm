#include<stdio.h>
#include<stdlib.h>

int ver(int n, int *v)
{
    if(n == 0)
        return 1;
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
            if(v[i] == v[j])
                return 0;
    return 1;
}

void print(int n, int *v)
{
    for(int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

void aran(int n, int m, int k, int *v)
{
    for(int i = 1; i <= n; i++)
    {
        v[k] = i;
        if(ver(k, v))
        {
            if(k == m && i == m)
                print(k, v);
            else
                aran(n, m, k + 1, v);
        }
    }
}

int main()
{
    int n = 5;
    int m = 3;
    int *v = calloc(n, sizeof(int));
    aran(n, m, 0, v);

    return 0;
}
