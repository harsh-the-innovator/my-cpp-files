// codeforces global round 8 C.even picture
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{

    ll n;
    cin >> n;

    vector<pair<ll, ll>> v;
    v.pb({0, 0});
    v.pb({0, 1});
    v.pb({1, 0});
    v.pb({1, 1});

    while (n--)
    {
        ll x = v.back().first;
        ll y = v.back().second;

        v.pb({x + 1, y});
        v.pb({x, y + 1});
        v.pb({x + 1, y + 1});
    }

    cout << v.size() << endl;
    for (auto p : v)
    {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}