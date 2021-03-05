#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll a[n];
        rep(i, n) cin >> a[i];
        sort(a, a + n);

        ll ans1 = a[n - 1] * a[n - 2] + (a[n - 1] - a[n - 2]);
        ll ans2 = a[1] * a[0] + (a[1] - a[0]);

        cout << max(ans1, ans2) << endl;
    }

    return 0;
}