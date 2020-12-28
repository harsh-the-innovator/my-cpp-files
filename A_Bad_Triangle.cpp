// codeforces educational round 93 div2
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long
#define vl vector<long long>
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
        vl a(n);
        rep(i, n) cin >> a[i];
        if (a[0] + a[1] <= a[n - 1])
        {
            cout << "1 2 " << n << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }

    return 0;
}