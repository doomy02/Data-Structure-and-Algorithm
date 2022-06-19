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

int LiniarSort(int *a, int n, int x)
{
    for(int i = 0; i < n; i++)
        if(a[i] == x)
            return i;
    return -1;
}

int main()
{
    int n = 10;
    int *a = generate(n);
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    printf("%d", LiniarSort(a, n, 5));

    return 0;
}
