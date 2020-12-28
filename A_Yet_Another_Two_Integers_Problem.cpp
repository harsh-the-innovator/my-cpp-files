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

void solve(ll a, ll b)
{
    ll ans = 0;
    if (a == b)
    {
        cout << "0" << endl;
    }
    else
    {
        ll diff = abs(a - b);
        if (diff % 10 == 0)
        {
            ans = diff / 10;
        }
        else
        {
            ans = diff / 10 + 1;
        }
        cout << ans << endl;
    }
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        solve(a, b);
    }

    return 0;
}