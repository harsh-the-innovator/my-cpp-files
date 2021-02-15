// Find minimum number of coins that make a given value
// unbounded knapsack variation

#include <bits/stdc++.h>
using namespace std;
#define I INT_MAX
int coinChange2(int coin[], int n, int sum)
{
    int dp[n + 1][sum + 1];
    // initialization
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j == 0)
                dp[i][j] = 0;
            if (i == 0)
                dp[i][j] = I - 1;
        }
    }

    // initialization 2nd row
    for (int i = 1, j = 1; j <= sum; j++)
    {
        if (j % coin[0] == 0)
        { // sum is divisible by 1st coin
            dp[i][j] = j / coin[0];
        }
        else
        {
            dp[i][j] = I - 1;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (coin[i - 1] <= j)
            {
                dp[i][j] = min(dp[i][j - coin[i - 1]] + 1, dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}

int main()
{
    int coin[] = {9, 6, 5, 1};
    int n = sizeof(coin) / sizeof(coin[0]);
    int sum = 11;
    int minCoins = coinChange2(coin, n, sum);
    if (minCoins == I || minCoins == I - 1)
    {
        cout << "Not posible" << endl;
    }
    else
    {
        cout << "Minimum number of coins required = " << minCoins << endl;
    }
}