// print shortest common supersequence
// #SCS
// #DP
// #LCS
#include <bits/stdc++.h>
using namespace std;

string printSCS(string X, string Y, int n, int m)
{

    // first make table for lcs
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

    // now code for printing:-
    int i = m, j = n;
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
                // add Y[j-1]
                result.push_back(Y[j - 1]);
                // move left
                j--;
            }
            else
            {
                // add X[i-1]
                result.push_back(X[i - 1]);
                // move up
                i--;
            }
        }
    }

    // after looping above, if one of the two string is empty

    // if Y is empty and X is non empty then add remaining char of string X to result
    while (i > 0)
    {
        result.push_back(X[i - 1]);
        i--;
    }

    // if X is empty and Y is non empty then add remaining char of string Y to result
    while (j > 0)
    {
        result.push_back(Y[j - 1]);
        j--;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string x = "acbcf";
    string y = "abcdaf";
    cout << printSCS(x, y, x.length(), y.length()) << endl;
}