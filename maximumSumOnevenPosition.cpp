// codeforces global round 90 div2 D
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll maxSubArraySum(vector<ll> a)
{
    ll max_so_far = a[0];
    ll curr_max = a[0];

    for (ll i = 1; i < a.size(); i++)
    {
        curr_max = max((ll)a[i], curr_max + a[i]);
        max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll sum_even = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i % 2 == 0)
        {
            sum_even += (ll)a[i];
        }
    }

    vector<ll> even, odd;
    for (ll i = 0; i + 1 < n; i += 2)
    {
        even.push_back(a[i + 1] - a[i]);
    }
    for (ll i = 1; i + 1 < n; i += 2)
    {
        odd.push_back(a[i] - a[i + 1]);
    }

    ll x = maxSubArraySum(even);
    ll y = maxSubArraySum(odd);

    cout << sum_even + max({0LL, x, y}) << endl;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}