// Count of subsets with sum equal to X gfg
#include <bits/stdc++.h>
using namespace std;

int Count(int arr[], int n, int sum)
{
    int dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
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
    int arr[] = {2, 3, 5, 6, 8, 10};
    int sum = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Number of subsets with given sum = " << Count(arr, n, sum) << endl;
}