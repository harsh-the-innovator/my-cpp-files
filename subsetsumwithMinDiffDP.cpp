// Partition a set into two subsets such that the difference of subset sums is minimum
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll minDiff(ll arr[], ll n, ll Range)
{
    // subset sum dp
    bool dp[n + 1][Range + 1];
    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= Range; j++)
        {
            if (i == 0)
                dp[i][j] = false;
            if (j == 0)
                dp[i][j] = true;
        }
    }

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= Range; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // for (ll i = 0; i <= Range; i++)
    // {
    //     cout << dp[n][i] << " ";
    // }
    // cout << endl;

    // store last row in vector till half way where it is true
    vector<ll> v;
    for (ll i = 0; i <= Range / 2; i++)
    {
        if (dp[n][i] == true)
            v.push_back(i);
    }

    // find minimum difference
    ll m = INT_MAX;
    for (ll i = 0; i < v.size(); i++)
    {
        m = min(m, Range - 2 * v[i]);
    }
    return m;
}

int32_t main()
{
    ll n;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
    ll range = (n * (n + 1)) / 2;
    cout << minDiff(arr, n, range);
}