#include <bits/stdc++.h>
using namespace std;

int dp[502][502];

bool isPal(string s, int i, int j)
{
    if (i > j)
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] != s[j])
        return dp[i][j] = 0;

    return dp[i][j] = isPal(s, i + 1, j - 1);
}

int solve(string s, int n)
{
    memset(dp, -1, sizeof(dp));
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (isPal(s, i, j))
                count++;
        }
    }
    return count;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n;
        cin >> s;
        cout << solve(s, n) << endl;
    }
    return 0;
}