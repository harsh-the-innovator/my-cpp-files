// codeforces #667 div3 2020
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define pi (3.141592653589)
#define mod 1e9 + 7
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

ll ok(ll a, ll b, ll x, ll y, ll n)
{
    ll d1 = a - x;
    ll d2 = b - y;
    ll c1 = min(d1, n);
    a -= c1;
    n -= c1;
    ll c2 = min(d2, n);
    b -= c2;
    n -= c2;
    ll ans = a * b;
    return ans;
}

void solve(ll a, ll b, ll x, ll y, ll n)
{
    ll ans = min(ok(a, b, x, y, n), ok(b, a, y, x, n));
    cout << ans << "\n";
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        ll a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        solve(a, b, x, y, n);
    }

    return 0;
}