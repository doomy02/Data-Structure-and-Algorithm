#include <stdio.h>
#include <stdlib.h>

int ver(int n, int k, int v[n])
{
    for(int i = 0; i < k; i++)
        if(v[i] == v[k] || (k - i == abs(v[i] - v[k])))
            return 0;
    return 1;
}

void BT(int n, int R[n], int k)
{
    for(int i = 0; i < n; i++)
    {
        R[k] = i;
        if(ver(n, k, R) == 1)
        {
            if(k == n - 1)
                print(n, R);
            else
                BT(n, R, k + 1);
        }
    }
}

void print(int n, int R[n])
{
    char m[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            m[i][j] = '.';
    for(int i = 0; i < n; i++)
        m[i][R[i]] = 'R';
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%c", m[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int R[4];
    BT(4, R, 0);

    return 0;
}
