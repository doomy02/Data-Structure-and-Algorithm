#include <stdio.h>
#include <stdlib.h>
///I have a sum of money and I want to decompose it using s[i] coins.
///In how many ways can I do that?
///It does not matter in which way I choose the coins, but it does matter how often was it used!
///dp[k][x] = in how many ways I can obtain x with the first k coins
///dp[0][0] = 1;
///dp[1][0] = 1, dp[1][x] = 1
///dp[k][x] = dp[k][x-a[k-i]] - using at least one coin, s[i]
///         + dp[k - i][x] -not using the coin, s[i]

void sum2(int *s, int n, int sum)
{
    int **dp = calloc(n + 1, sizeof(int*));
    for(int i = 0; i <= n; i++)
        dp[i] = calloc(sum + 1, sizeof(int));

    dp[0][0] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= sum; j++)
        {
            dp[i][j] += dp[i - 1][j];
            if(j - s[i - 1] >= 0)
                dp[i][j] += dp[i][j - s[i - 1]];
        }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= sum; j++)
            printf("(%d %d) ", j, dp[i][j]);
        printf("\n");
    }
}

int main()
{
    int sum = 10;
    int s[] = {1, 2, 3};
    int n = sizeof(s)/sizeof(int);
    sum2(s, n, sum);

    return 0;
}
