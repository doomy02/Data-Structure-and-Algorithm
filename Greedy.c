#include<stdio.h>
#include<stdlib.h>

int n = 7;
int money[] = {1, 5, 10, 50, 100, 200, 500};

int greedy(int x)
{
    int k = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        while(x - money[i] >= 0)
        {
            x -= money[i];
            k++;
        }
    }
    if(x == 0)
        return k;
    else
        return x;
}

int main()
{
    printf("%d ", greedy(65));

    return 0;
}
