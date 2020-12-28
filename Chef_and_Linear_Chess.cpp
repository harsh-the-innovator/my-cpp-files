// codechef august long challenge 2020
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long
#define vl vector<long long>
#define all(c) c.begin(), c.end()
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

void solve(vl &a, int n, ll k) {
    sort(all(a));
    ll ans = -1;
    rrep(i, n) {
        if (a[i] < k && (k % a[i]) == 0) {
            ans = a[i];
            break;
        }
    }

    cout<<ans<<endl;
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n;
        ll k;
        cin>>n>>k;
        vl a(n);
        rep(i, n) cin>>a[i];
        solve(a, n, k);
    }

    return 0;
}