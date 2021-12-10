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

void solve(ll x)
{
    if (x == 0)
    {
        cout << "1";
        return;
    }

    ll p = floor(log2(x));
    ll temp = pow(2, p);
    ll bitwiseOR = temp * 2 - 1;
    ll ans;
    if (bitwiseOR > x)
    {
        ans = temp;
    }
    else
    {
        ans = temp * 2;
    }

    cout << ans;
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        ll x;
        cin >> x;
        solve(x);
        cout << endl;
    }

    return 0;
}