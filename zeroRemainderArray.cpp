// codeforces 2020 #653 div3 D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(a, b) for (int i = a; i < b; i++)
map<ll, ll> m;
int main()
{
    int t;
    ll x;
    cin >> t;
    while (t--)
    {
        m.clear();
        ll n, k;
        cin >> n >> k;
        rep(0, n)
        {
            cin >> x;
            m[x % k]++;
        }

        ll mx = 0;
        for (auto itr : m)
        {
            ll count = itr.second;
            ll i = itr.first;

            if (i != 0)
            {
                mx = max(mx, count * k - i);
            }
        }
        if (mx)
            mx++;
        cout << mx << endl;
    }
}