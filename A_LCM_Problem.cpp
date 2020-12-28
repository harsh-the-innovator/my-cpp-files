// codeforces educational round #92 div2 A
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
        ll l, r;
        cin >> l >> r;
        if (r % l == 0)
        {
            cout << l << " " << r << endl;
            continue;
        }

        if (r - l == 1)
        {
            cout << "-1 -1" << endl;
        }
        else
        {
            if (r - l > l)
            {
                int rem = r % l;
                cout << l << " " << r - rem << endl;
            }
            else
            {
                cout << "-1 -1" << endl;
            }
        }
    }
}