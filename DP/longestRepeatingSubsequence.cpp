// longest repeating subsequence
// #DP
// #LCS
#include <bits/stdc++.h>
using namespace std;
int lengthLRS(string X, string Y, int n, int m)
{
    // all code is same as LCS
    int dp[n + 1][m + 1];

    // initialization
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // just add condition i!=j
            if (X[i - 1] == Y[j - 1] && i != j)
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}
int main()
{
    string x = "AABEBCDD";
    cout << "Length of Longest Repeating Subsequence = " << lengthLRS(x, x, x.length(), x.length()) << endl;
}