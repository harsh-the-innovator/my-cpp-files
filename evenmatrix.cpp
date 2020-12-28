// codechef may 2020 long challenge
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll k = 1;
        ll m[n + 1][n + 1];
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= n; j++)
            {
                if (i % 2 != 0)
                {
                    m[i][j] = k;
                    k++;
                }
                else
                {
                    m[i][j] = k;
                    k--;
                }
            }
            if (i % 2 != 0)
                k += n - 1;
            else
                k += n + 1;
        }

        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= n; j++)
            {
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
    }
}