
#include <bits/stdc++.h>
using namespace std;

int maxSubstring(string S)
{
    int n = S.length();
    int dp[n + 1];
    dp[0] = 0;
    int res = -1;
    for (int i = 1; i <= n; i++)
    {
        if (S[i - 1] == '0')
        {
            dp[i] = max(dp[i - 1] + 1, 1);
        }
        else if (S[i - 1] == '1')
        {
            dp[i] = max(dp[i - 1] - 1, -1);
        }

        res = max(res, dp[i]);
    }
    return res;
}

int main()
{
    string s;
    cin >> s;
    cout << maxSubstring(s) << endl;
}