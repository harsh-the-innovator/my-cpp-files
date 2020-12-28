#include <bits/stdc++.h>
using namespace std;
int t[101][101];
int lengthLCS(string X, string Y, int n, int m)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }

    if (t[n][m] != -1)
    {
        return t[n][m];
    }

    if (X[n - 1] == Y[m - 1])
    {
        return t[n][m] = 1 + lengthLCS(X, Y, n - 1, m - 1);
    }
    else
    {
        return t[n][m] = max(lengthLCS(X, Y, n, m - 1), lengthLCS(X, Y, n - 1, m));
    }
}

int main()
{
    string X = "abcf";
    string Y = "abcdaf";
    int n = X.length();
    int m = Y.length();
    memset(t, -1, sizeof(t));
    cout << "Length of LCS = " << lengthLCS(X, Y, n, m) << endl;
}