// goldmine problem gfg
#include <bits/stdc++.h>
using namespace std;
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define MAX 21

int solve(int gold[MAX][MAX], int n, int m)
{
    int dp[n + 1][m + 1];

    // intitalization
    int result = -1;
    loop(i, 1, n)
    {
        dp[i][1] = gold[i][1];
        result = max(result, dp[i][1]);
    }

    loop(j, 2, m)
    {
        loop(i, 1, n)
        {
            if (n == 1)
            {
                dp[i][j] = gold[i][j] + dp[i][j - 1];
            }
            else
            {
                if (i == 1)
                {
                    dp[i][j] = gold[i][j] + max(dp[i][j - 1], dp[i + 1][j - 1]);
                }
                else if (i == n)
                {
                    dp[i][j] = gold[i][j] + max(dp[i][j - 1], dp[i - 1][j - 1]);
                }
                else
                {
                    dp[i][j] = gold[i][j] + max({dp[i][j - 1], dp[i + 1][j - 1], dp[i - 1][j - 1]});
                }
            }

            result = max(result, dp[i][j]);
        }
    }

    return result;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int gold[MAX][MAX];
        loop(i, 1, n)
        {
            loop(j, 1, m)
            {
                cin >> gold[i][j];
            }
        }
        cout << solve(gold, n, m) << endl;
    }
}