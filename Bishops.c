#include<stdio.h>
#include<stdlib.h>

int ver(int n, int k, int *v)
{
    for(int i = 0; i < k; i++)
        if(v[i] != v[k])
            return 0;
    return 1;
}

void print(int n, int R[n])
{
    char m[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            m[i][j] = '.';

    for(int i = 0; i < n; i++)
        m[i][R[i]] = 'B';

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%c", m[i][j]);
        printf("\n");
    }
    printf("\n");
}

void ture(int n, int k, int R[n])
{
    for(int i = 0; i < n; i++)
    {
        R[k] = i;
        if(ver(n, k, R))
        {
            if(k == n - 1)
                print(k + 1, R);
            else
                ture(n, k + 1, R);
        }
    }
}

int main()
{
    int n = 4;
    int R[4];
    ture(n, 0, R);

    return 0;
}
