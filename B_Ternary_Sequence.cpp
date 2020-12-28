// codeforces #655 div 2 B
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        ll x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1;
        cin >> x2 >> y2 >> z2;

        ll ans = 0;
        ans += 2 * (min(z1, y2));
        if (y1 > x2 && z2 > x1)
        {
            ans -= 2 * (min(y1 - x2, z2 - x1));
        }
        cout << ans << endl;
    }

    return 0;
}