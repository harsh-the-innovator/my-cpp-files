// codeforces #653 div3 A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll x, y, n;
        cin >> x >> y >> n;
        ll NminusY = n - y;
        if (NminusY < x)
        {
            cout << y;
        }
        else if (NminusY == x)
        {
            cout << n;
        }
        else
        {
            ll rem = NminusY % x;
            cout << (n - rem);
        }

        cout << endl;
    }
}