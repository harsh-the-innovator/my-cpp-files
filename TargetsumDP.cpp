// You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.
// Find out how many ways to assign symbols to make sum of integers equal to target S.
// leetcode

// solution is same as count of subset sum with given difference
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
    int arr[] = {1, 1, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 3;
    int arrSum = 0;
    for (int i = 0; i < n; i++)
    {
        arrSum += arr[i];
    }

    sum = (sum + arrSum) / 2;
    cout << Count(arr, n, sum) << endl;
}