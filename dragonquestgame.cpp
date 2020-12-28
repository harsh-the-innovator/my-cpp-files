#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define ll long long
#define pb push_back
#define vint vector<int>
#define vll vector<long long>
#define pint pair<int, int>
#define pll pair<long long, long long>
#define pi 3.1415926535898
#define INF 1000000000000
#define INFM -1000000000000
#define mod1 1000000007
#define mod2 998244353
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
bool outoflimit(ll x, ll i, ll j, ll n, ll m)
{
    if (i > n || j > m)
    {
        return true;
    }
    return false;
}

ll absorb(ll x)
{
    return x / 2 + 10;
}
ll strike(ll x)
{
    return x - 10;
}

bool decNum(ll x, ll i, ll j, ll n, ll m)
{
    if (x <= 0)
    {
        return true;
    }
    if (!outoflimit(x, i + 1, j, n, m))
    {
        if (decNum(absorb(x), i + 1, j, n, m))
        {
            return true;
        }
    }

    if (!outoflimit(x, i, j + 1, n, m))
    {
        if (decNum(strike(x), i, j + 1, n, m))
        {
            return true;
        }
    }

    return false;
}

void solve()
{
    ll x, n, m;
    cin >> x >> n >> m;

    if (decNum(x, 0, 0, n, m) == false)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
}

int main()
{
    fastIO int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
