// CODECHEF STARTERS 15
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

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;

    // count the no of even and odd prime factors
    int even = 0, odd = 0;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            n = n / i;
            (i % 2 == 0 ? even++ : odd++);
        }
    }

    if (n > 1)
        (n % 2 == 0 ? even++ : odd++);

    int ans;

    if (a >= 0 and b >= 0)
        ans = even * a + odd * b;
    if (a >= 0 and b < 0)
        ans = (even > 0 ? even * a : b);
    if (a < 0 and b >= 0)
        ans = (odd * b + (even > 0 ? a : 0));
    if (a < 0 and b < 0)
        ans = (even > 0 ? a : b);

    cout << ans << endl;
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}