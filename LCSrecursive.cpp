#include <bits/stdc++.h>
using namespace std;
int lengthLCS(string X, string Y, int n, int m)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }

    if (X[n - 1] == Y[m - 1])
    {
        return 1 + lengthLCS(X, Y, n - 1, m - 1);
    }
    else
    {
        return max(lengthLCS(X, Y, n, m - 1), lengthLCS(X, Y, n - 1, m));
    }
}

int main()
{
    string X = "abcf";
    string Y = "abcdaf";
    int n = X.length();
    int m = Y.length();
    cout << "Length of LCS = " << lengthLCS(X, Y, n, m) << endl;
}