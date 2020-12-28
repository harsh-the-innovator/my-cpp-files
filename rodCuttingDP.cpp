#include <bits/stdc++.h>
using namespace std;

int rodCutting(int price[], int n)
{
    int dp[n + 1][n + 1];
    int length[n];
    for (int i = 0; i < n; i++)
    {
        length[i] = i + 1;
    }

    // initialization
    for (int i = 0; i <= n; i++) // i is for size of array
    {
        for (int j = 0; j <= n; j++) // j is for length of rod
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (length[i - 1] <= j)
            {
                dp[i][j] = max(price[i - 1] + dp[i][j - length[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][n];
}

int main()
{
    int n;
    cin >> n;
    int price[n];
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }

    cout << "Max price value = " << rodCutting(price, n);
}