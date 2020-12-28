// codechef may 2020 long challege
#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll ts, js;
        cin >> ts;
        // ll count;
        if (ts % 2 != 0)
        { //odd
            cout << ts / 2 << endl;
        }
        else
        {
            while (ts % 2 == 0)
            {
                ts = ts / 2;
            }
            cout << ts / 2 << endl;
        }
    }
}