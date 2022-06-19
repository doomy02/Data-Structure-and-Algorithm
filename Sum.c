#include<stdio.h>
#include<stdlib.h>

int MoneyNo(int *v, int n)
{
    int k = 0;
    for(int i = 0; i < n; i++)
        k += v[i];
    return k;
}

void opti(int *v, int n, int *ops)
{
    int x = MoneyNo(v, n);
    if(x < ops[0])
    {
        ops[0] = x;
        for(int i = 0; i < n; i++)
            ops[i + 1] = v[i];
    }
}

void print(int *v, int n, int *money)
{
    for(int i = 0; i < n; i++)
        printf("%d ", money[i] * v[i]);
    printf("\n");
}

void BT(int *v, int k, int n, int *money, int sum, int *sop)
{
    if(sum == 0)
    {
        opti(v, n, sop);
        print(v, n, money);
    }
    if(k < n)
    {
        for(int i = 0; i <= 1; i++)
        {
            v[k] = i;
            if(sum - money[k]*i >= 0)
                BT(v, k + 1, n, money, sum - money[k] * i, sop);
        }
    }
}

int main()
{
    int n = 6, sum = 30;
    int *v = calloc(n, sizeof(int));
    int *sop = calloc(n + 1, sizeof(int));
    int *money = calloc(n, sizeof(int));
    sop[0] = n + 1;
    for(int i = 0; i < n; i++)
        scanf("%d ", &money[i]);
    BT(v, 0, n, money, sum, sop);

    printf("\nOptimal solution: ");
    for(int i = 1; i <= n; i++)
        printf("%d ", sop[i]*money[i - 1]);

    return 0;
}
