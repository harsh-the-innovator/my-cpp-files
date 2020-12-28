#include <bits/stdc++.h>
using namespace std;

void solve(string X, string Y, int n, int m, int k)
{
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
            if (X[i - 1] == Y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int lcs = dp[n][m];

    int i = n, j = m;
    string result = "";
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            result.push_back(X[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i][j - 1] > dp[i - 1][j])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }
    reverse(result.begin(), result.end());
}

int main()
{
    string A = "abcba";
    string B = "acyx";
    int k = 3;
    solve(A, B, A.length(), B.length(), k);
}