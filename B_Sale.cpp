// codeforces Beta Round #34 div2 B
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define vi vector<int>
#define all(c) c.begin(), c.end()
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast ios_base::sync_with_stdio(0), cin.tie(0);

int main()
{
    fast int n, m;
    cin >> n >> m;
    vi a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));
    int sum = 0;
    rep(i, n)
    {
        if (a[i] <= 0 && m > 0)
        {
            sum += (-a[i]);
            m--;
        }
    }

    cout << sum << endl;
    return 0;
}