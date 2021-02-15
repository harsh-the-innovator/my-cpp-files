// print denominations used for minimum number of coins
#include <bits/stdc++.h>
using namespace std;
#define I INT_MAX
const int coin[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};

int solve(int sum)
{
    int dp[11][sum + 1];

    // intitalize
    for (int i = 0; i <= 10; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= sum; j++)
    {
        dp[0][j] = I - 1;
    }

    for (int i = 1, j = 1; j <= sum; j++)
    {
        if (j % coin[0] != 0)
            dp[i][j] = I - 1;
        else
            dp[i][j] = j / coin[0];
    }

    for (int i = 2; i <= 10; i++)
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

    // for printing the coins used
    int i = 10, j = sum;
    while (i != 0 && j != 0)
    {
        if (dp[i][j] == dp[i - 1][j])
            i--;
        else
        {
            cout << coin[i - 1] << " ";
            j = j - coin[i - 1];
        }
    }
    cout << endl;

    return dp[10][sum];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}