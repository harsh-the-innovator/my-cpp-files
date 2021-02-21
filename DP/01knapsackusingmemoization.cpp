#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[1001][1001];
ll knapsack(ll wt[], ll val[], ll n, ll W)
{
    if (n == 0 || W == 0)
        return 0;

    if (dp[n][W] != -1)
        return dp[n][W];

    if (wt[n - 1] <= W)
    {
        return dp[n][W] = max(val[n - 1] + knapsack(wt, val, n - 1, W - wt[n - 1]), knapsack(wt, val, n - 1, W));
    }
    else
    {
        return dp[n][W] = knapsack(wt, val, n - 1, W);
    }
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