// codechef september long challenge 2020
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);
ll ans;
ll diff;
ll solve(ll i, ll j, ll &total, ll &n)
{
    ll mid = (i + j) / 2;
    ll sum = (mid * (mid + 1)) / 2;
    if (i > j)
    {
        return ans;
    }

    if (sum > total / 2)
    {
        return solve(i, mid - 1, total, n);
    }
    else if (sum < total / 2)
    {
        if ((total - 2 * sum) / 2 <= (n - 1))
        {
            if ((total - 2 * sum) / 2 <= diff)
            {
                diff = (total - 2 * sum) / 2;
                ans = n - mid;
                return solve(mid + 1, j, total, n);
            }
            else
            {
                return ans;
            }
        }
        else
        {
            return solve(mid + 1, j, total, n);
        }
    }
    else
    {
        return ((mid) * (mid - 1)) / 2 + ((n - mid) * (n - mid - 1)) / 2 + (n - mid);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    fast ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll total = (n * (n + 1)) / 2;
        if (total % 2 != 0)
        {
            cout << "0" << endl;
        }
        else
        {
            ans = 0;
            diff = LONG_MAX;
            cout << solve(1, n, total, n) << endl;
        }
    }

    return 0;
}