#include <stdio.h>
#include <stdlib.h>
///I have a napsack with a capacity, c, and n objects, each one having a volume, v[i], and a value, w[i].
/// Which is the maximum value if the sum of volume can not be above it's capacity and each object can be used only once?
///dp[x] = the maximum value if the final volume is x
///dp[0] = 0
///dp[x] = max(dp[x- v[i]] + w[i], dp[x]), x decending

int MAX(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

void napsack(int c, int n, int *v, int *w)
{
    int dp[c + 1];
    dp[0] = 0;

    for(int i = 0; i <= c; i++)
        dp[i] = -1; //branding each object as "unused"

    for(int i = 0; i < n; i++)
        dp[v[i]] = w[i]; //giving each object it's supposed value

    for(int i = 0; i < n; i++)
        for(int j = c; j >= 0; j--)
            if(j - v[i] >= 0 && dp[j - v[i]] != -1)
                dp[i] = MAX(dp[j], dp[j - v[i]] + w[i]);

    int ma = 0;
    for(int i = 1; i <=c; i++)
        ma = MAX(dp[i], ma);
    printf("%d", ma);

}

int main()
{
    int c = 5;
    int v[] = {5, 2, 3};
    int w[] = {7, 1, 8};
    napsack(c, 3, v, w);

    return 0;
}
