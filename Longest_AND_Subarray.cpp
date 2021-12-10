#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
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

void dfile()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("input.txt", "w", stdout);
#endif
}

void solve(ll n)
{
    if (n == 1)
    {
        cout << "1";
        return;
    }

    ll x = floor(log2(n * 1.0));
    ll temp = pow(2, x);
    ll ans = max(temp / 2, n - temp + 1);

    cout << ans;
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        solve(n);
        cout << endl;
    }

    return 0;
}