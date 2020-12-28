// codeforces div3 #656
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long

#define fast ios_base::sync_with_stdio(0), cin.tie(0);

void solve(ll x, ll y, ll z)
{
    if (x == y and y == z)
    {
        cout << "YES\n"
             << x << " " << y << " " << z << endl;
    }
    else if (x == y and x != z)
    {
        if (z > x)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES\n"
                 << x << " " << z << " " << z << endl;
        }
    }
    else if (y == z and y != x)
    {
        if (x > y)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES\n"
                 << x << " " << x << " " << y << endl;
        }
    }
    else if (x == z and x != y)
    {
        if (y > x)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES\n"
                 << y << " " << x << " " << y << endl;
        }
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    fast ll t;
    cin >> t;
    while (t--)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        solve(x, y, z);
    }
    return 0;
}