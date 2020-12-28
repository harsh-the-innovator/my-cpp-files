// facebook hackercup 2020
#include <bits/stdc++.h>
using namespace std;
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define revloop(i, a, b) for (int i = a; i >= b; i--)
#define fast ios_base::sync_with_stdio(0), cin.tie(0);

void solve(string I, string O, int n)
{
    char dp[n + 1][n + 1];

    loop(i, 1, n)
    {
        loop(j, 1, n)
        {
            if (i == j)
                dp[i][j] = 'Y';
            else
                dp[i][j] = '0';
        }
    }

    loop(i, 1, n - 1)
    {
        loop(j, i + 1, n)
        {
            if (dp[i][j - 1] == 'Y' && O[j - 2] == 'Y' && I[j - 1] == 'Y')
            {
                dp[i][j] = 'Y';
            }
            else
            {
                dp[i][j] = 'N';
            }
        }
    }

    revloop(i, n, 2)
    {
        revloop(j, i - 1, 1)
        {
            if (dp[i][j + 1] == 'Y' && O[j] == 'Y' && I[j - 1] == 'Y')
            {
                dp[i][j] = 'Y';
            }
            else
            {
                dp[i][j] = 'N';
            }
        }
    }

    // print
    loop(i, 1, n)
    {
        loop(j, 1, n)
        {
            cout << dp[i][j];
        }
        cout << endl;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    fast int t;
    cin >> t;
    loop(i, 1, t)
    {
        int n;
        cin >> n;
        string I, O;
        cin >> I >> O;
        cout << "Case #" << i << ":" << endl;
        solve(I, O, n);
    }
    return 0;
}