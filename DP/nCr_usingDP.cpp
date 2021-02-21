#include <bits/stdc++.h>
using namespace std;
int findnCr(int n, int r)
{
    int dp[n + 1][r + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i, r); j++)
        {
            if (j == 0 || j == i)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            }
        }
    }

    return dp[n][r];
}
int main()
{
    cout << "Enter n and r:\n";
    int n, r;
    cin >> n >> r;
    cout << "nCr = " << findnCr(n, r) << endl;
}