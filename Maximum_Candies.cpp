// codechef july lunchtime 2020
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        int half = ceil((n * m) / 2.0);
        int ans;
        if (n * m == 1)
        {
            cout << x << endl;
            continue;
        }
        if (x <= y)
        {
            if (x <= y / 2)
            {
                ans = x * n * m;
            }
            else
            {
                ans = x * half + (n * m - half) * (y - x);
            }
        }
        else
        {
            ans = y * half;
        }

        cout << ans << endl;
    }
    return 0;
}