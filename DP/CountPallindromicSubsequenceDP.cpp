#include <bits/stdc++.h>
using namespace std;
int countPS(string str, int n)
{
    // create a 2D array to store the count of palindromic
    // subsequence
    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    //for first diagonal where gap = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
    }

    for (int gap = 1; gap < n; gap++)
    {
        for (int i = 0; i < n - gap; i++)
        {
            int j = i + gap;
            if (str[i] == str[j])
            {
                dp[i][j] = 1 + dp[i + 1][j] + dp[i][j - 1];
            }
            else
            {
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
            }
        }
    }

    return dp[0][n - 1];
}
int main()
{
    string str = "abcb";
    cout << "Total palindromic subsequence are : "
         << countPS(str, str.length()) << endl;
    return 0;
}