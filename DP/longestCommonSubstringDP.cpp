#include <bits/stdc++.h>
using namespace std;

int lengthLCSubstring(string X, string Y, int n, int m)
{
    int dp[n + 1][m + 1];
    int result = 0;
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
                result = max(result, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    return result;
}

int main()
{
    string X = "abcf";
    string Y = "abcdaf";
    int n = X.length();
    int m = Y.length();
    cout << "Length of LC Substring = " << lengthLCSubstring(X, Y, n, m) << endl;
}