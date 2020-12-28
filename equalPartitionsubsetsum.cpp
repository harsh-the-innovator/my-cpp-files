// Partition problem is to determine whether a given set can be partitioned into two subsets such that the sum of elements in both subsets is same.
#include <bits/stdc++.h>
using namespace std;
bool isSubsetSum(int arr[], int n, int sum)
{
    bool dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0)
                dp[i][j] = false;
            if (j == 0)
                dp[i][j] = true;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}
bool isEqualPartition(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    if (sum % 2 != 0) //odd
    {
        return false;
    }
    else
    {
        return isSubsetSum(arr, n, sum / 2);
    }
}
int main()
{
    int arr[] = {3, 1, 1, 2, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (isEqualPartition(arr, n))
        cout << "Can be divided into two subsets of equal sum";
    else
        cout << "Can not be divided into"
             << " two subsets of equal sum";
}