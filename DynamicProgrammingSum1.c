#include <stdio.h>
#include <stdlib.h>
///I have a sum of money and I want to decompose it using s[i] coins.
///In how many ways can I do that?
///It matters in which way I choose the coins, because 1 + 2 is different from 2 + 1.
/// s[] = {1, 2, 3}, dp[1] = 1,dp[2] = 2,dp[3] = 4
///dp[x] = how many ways I can obtain x
///dp[0] = 1
///dp[x] = dp[x - s[0]] + dp[x - s[1]] + ... + dp[x - s[n - 1]]
///x=b1 + b2 + ... + bk = b1 + b2+ ... +b(k - 1) + bk = dp[x - bk] + bk

void sum1(int *a, int n, int sum)
{
    int dp[sum + 1];
    dp[0] = 1;

    for(int x = 1; x <= sum; x++)
    {
        dp[x] = 0;
        for(int i = 0; i < n; i++)
            if(x - a[i] >= 0)
                dp[x] += dp[x - a[i]];
    }
    for(int i = 1; i <= sum; i++)
        printf("%d : %d\n", i, dp[i]);
}

int main()
{
    int sum = 10;
    int s[] = {1, 2, 3};
    int n = sizeof(s)/sizeof(int);
    sum1(s, n, sum);
    return 0;
}
