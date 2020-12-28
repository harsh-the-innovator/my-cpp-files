// codeforces #661 div3
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define vi vector<int>
#define all(c) c.begin(), c.end()
#define rep(i, n) for (int i = 0; i < n; i++)
#define loop(i, a, b) for (i = a; i <= b; i++)
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
        vi a(n);
        rep(i, n) cin >> a[i];
        sort(all(a));
        int i;
        loop(i, 1, n - 1)
        {
            if ((a[i] - a[i - 1]) > 1)
            {
                break;
            }
        }

        if (i == n)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}