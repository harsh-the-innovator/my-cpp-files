// codeforces #647 div 2
#include <bits/stdc++.h>
using namespace std;
#define ll long long
void output(ll a, ll b, ll x, ll y, ll z)
{
    int count = 0;
    if (a % b == 0)
    {
        while (a % x == 0 && a / x >= b)
        {
            count += 1;
            a = a / x;
        }

        while (a % y == 0 && a / y >= b)
        {
            count += 1;
            a = a / y;
        }

        while (a % z == 0 && a / z >= b)
        {
            count += 1;
            a = a / z;
        }
        if (a == b)
            cout << count << endl;
        else
        {
            cout << "-1" << endl;
        }
    }
    else
    {
        cout << "-1" << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        ll x = 8, y = 4, z = 2;
        if (a == b)
        {
            cout << "0" << endl;
        }
        else if (a > b)
        {
            output(a, b, x, y, z);
        }
        else
        {
            output(b, a, x, y, z);
        }
    }
}