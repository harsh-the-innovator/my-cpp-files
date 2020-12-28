// codechef july 2020 long challenge div 2
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
ll solve(vector<ll> &v, ll n, ll x)
{
    ll minDays = 0;
    ll i = 0;
    while (i < n && 2 * v[i] < x)
    {
        minDays++;
        i++;
    }

    while (i < n)
    {
        minDays++;
        if (v[i] > x && 2 * (v[i] - x) >= v[i])
        {
            x = 2 * x;
            continue;
        }
        if (v[i] <= x)
        {
            x = v[i];
            i++;
        }
        x = 2 * x;
    }

    return minDays;
}

int main()
{
    fastIO int t;
    cin >> t;
    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        cout << solve(v, n, x) << endl;
    }
}
