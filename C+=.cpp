// codeforces 2020 Global Round 8
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(ll a, ll b, ll n)
{
    ll count = 0;
    while (1)
    {
        if (a > n || b > n)
        {
            break;
        }
        else
        {
            if (a <= b)
            {
                a = a + b;
            }
            else
            {
                b = b + a;
            }

            count++;
        }
    }

    return count;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, n;
        cin >> a >> b >> n;
        cout << solve(a, b, n) << endl;
    }
}
