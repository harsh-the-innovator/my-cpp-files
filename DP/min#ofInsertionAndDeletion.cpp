// minimum number of insertion and deletion to convert string a to b;
// #DP
// #LCS
#include <bits/stdc++.h>
using namespace std;
int lengthLCS(string X, string Y, int n, int m)
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

    return dp[n][m];
}
int main()
{
    string x = "heap";
    string y = "pea";
    int lcs = lengthLCS(x, y, x.length(), y.length());
    cout << "Number of Deletion = " << x.length() - lcs << "\n";
    cout << "Number of Insertion = " << y.length() - lcs << "\n";
}
