#include <stdio.h>
#include <stdlib.h>

int BinarySort(int *a, int p, int q, int x)
{
    if(p > q) return -1;
    else
    {
        int m = (p + q) / 2;
        if(a[m] == x) return m;
        if(a[m] > x) return BinarySort(a, p, m - 1, x);
        if(a[m] < x) return BinarySort(a, m + 1, q, x);
    }
}

int* generate(int n)
{
    int *a = calloc(n, sizeof(int));
    int c = 1,d = 10;

    for(int i = 0; i < n; i++)
        a[i] = rand() % d + c;

    return a;
}

int main()
{
    int n = 10;
    int *a = generate(n);
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
    printf("%d ", BinarySort(a, 0, 9, 5));

    return 0;
}
