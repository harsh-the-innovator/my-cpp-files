#include <bits/stdc++.h>
using namespace std;
#define I INT_MAX

int dp[501][501];

int getSum(int arr[], int from, int to)
{
    int sum = 0;
    for (int i = from; i <= to; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int partition(int arr[], int n, int k)
{
    if (n == 1)
        return dp[n][k] = arr[0];

    if (k == 1)
        return dp[n][k] = getSum(arr, 0, n - 1);

    if (dp[n][k] != -1)
        return dp[n][k];

    int minTime = I;
    for (int i = 1; i <= n; i++)
    {
        minTime = min(minTime, max(partition(arr, i, k - 1), getSum(arr, i, n - 1)));
    }

    return dp[n][k] = minTime;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k, n;
        cin >> k >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        memset(dp, -1, sizeof(dp));

        cout << partition(a, n, k) << endl;
    }
    return 0;
}