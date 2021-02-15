#include <bits/stdc++.h>
using namespace std;

int lengthLCS(string X, string Y, int m, int n)
{
    int dp[m + 1][n + 1];

    // initialization
    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= n; j++)
    {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
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

    //below code is for printing LCS

    int i = m, j = n;
    string s = "";
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            s.push_back(X[i - 1]);
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

    reverse(s.begin(), s.end());
    // now s is the resultant longest common subsequence

    return dp[m][n];
}

int main()
{
    string X = "abcf";
    string Y = "abcdaf";
    int m = X.length();
    int n = Y.length();
    cout << "Length of LCS = " << lengthLCS(X, Y, m, n) << endl;
}