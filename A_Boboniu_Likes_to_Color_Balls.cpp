// codeforces #644 div2 A
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

void doOperation(ll &r, ll &g, ll &b, ll &w)
{
    r--;
    g--;
    b--;
    w += 3;
}

void solve(ll r, ll g, ll b, ll w)
{
    ll val = min({r, g, b});
    ll count = 0;
    if (r % 2 == 1)
        count++;
    if (g % 2 == 1)
        count++;
    if (b % 2 == 1)
        count++;
    if (w % 2 == 1)
        count++;

    if (count <= 1)
        cout << "Yes" << endl;
    else if (val != 0)
    {
        doOperation(r, g, b, w);
        count = 0;
        if (r % 2 == 1)
            count++;
        if (g % 2 == 1)
            count++;
        if (b % 2 == 1)
            count++;
        if (w % 2 == 1)
            count++;

        if (count <= 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    else
        cout << "No" << endl;
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        ll r, g, b, w;
        cin >> r >> g >> b >> w;
        solve(r, g, b, w);
    }

    return 0;
}