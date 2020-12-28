// codeforces  #196 div2
#include <bits/stdc++.h>
using namespace std;
#define I INT_MAX
#define vi vector<int>
#define all(c) c.begin(), c.end()
#define rep(i, n) for (int i = 0; i < n; i++)
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);
int main()
{
    int n, m;
    cin >> n >> m;
    vi a(m);
    rep(i, m) cin >> a[i];
    sort(all(a));
    int ans = I;
    loop(i, 0, m - n)
    {
        ans = min(ans, a[i + n - 1] - a[i]);
    }
    cout << ans << endl;
}