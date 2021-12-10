#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (auto &x : a)
            cin >> x;
        ll ans = 0;
        for (ll i = 0; i < n; i++)
        {
            for (ll k = i + 2; k < n; k++)
            {
                auto f = [&](int j)
                {
                    return (a[i] - a[j]) * (a[j] - a[k]);
                };

                ll j = upper_bound(a.begin() + i, a.begin() + k, (a[i] + a[k]) / 2) - a.begin();
                j = min(j, k - 1);
                ans += max(f(j), f(j - 1));
            }
        }
        cout << ans << endl;
    }

    return 0;
}