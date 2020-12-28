// https://www.codechef.com/LTIME84B/problems/WWALK

// weird walk
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n;
    cin >> n;
    ll aSpeed[n + 1];
    ll bSpeed[n + 1];
    for (ll i = 1; i <= n; i++)
    {
        cin >> aSpeed[i];
    }
    for (ll i = 1; i <= n; i++)
    {
        cin >> bSpeed[i];
    }

    ll ax = 0, bx = 0;
    ll weird = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (aSpeed[i] == bSpeed[i] && ax == bx)
        {
            weird += aSpeed[i];
        }
        ax += aSpeed[i];
        bx += bSpeed[i];
    }

    cout << weird << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}