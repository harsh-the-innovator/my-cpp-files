#include <bits/stdc++.h>
using namespace std;

// this is memoized optimized version
// see also simple recursive and bottom up dp solution

int dp[500][500];

bool isPal(string str, int i, int j)
{

    while (i < j)
    {
        if (str[i] == str[j])
        {
            i++;
            j--;
        }
        else
            return false;
    }

    return true;
}
int solve(string str, int i, int j)
{
    if (i >= j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (isPal(str, i, j) == true)
        return 0;

    int ans = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int left, right;

        if (dp[i][k] != -1)
            left = dp[i][k];
        else
        {
            left = solve(str, i, k);
            dp[i][k] = left;
        }

        if (dp[k + 1][j] != -1)
            right = dp[k + 1][j];
        else
        {
            right = solve(str, k + 1, j);
            dp[k + 1][j] = right;
        }

        int temp = 1 + left + right;
        if (temp < ans)
            ans = temp;
    }

    return dp[i][j] = ans;
}

int palindromicPartition(string str)
{
    int n = str.length();
    if (n == 0)
        return 0;

    memset(dp, -1, sizeof(dp));

    return solve(str, 0, n - 1);
}
int main()
{
    string str = "ababbbabbababa";
    cout << "Minimum number of cuts = " << palindromicPartition(str);
}