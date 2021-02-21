#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[1001][1001];
ll knapsack(ll wt[], ll val[], ll n, ll W)
{

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][W];
}

void solve()
{
    ll n, W;
    cin >> n >> W;
    ll val[n], wt[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    for (ll i = 0; i < n; i++)
    {

        cin >> wt[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << knapsack(wt, val, n, W) << endl;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}