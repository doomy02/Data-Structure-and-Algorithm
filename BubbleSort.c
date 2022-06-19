#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int *a, int n)
{
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j <= n; j++)
        {
            if(a[i] > a[j])
            {
                int aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }
        }

    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

int* generate(int n)
{
    int *a = calloc(n, sizeof(int));
    int c = 1, d = 10;
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
    BubbleSort(a,n);

    return 0;
}
