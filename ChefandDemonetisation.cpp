// codechef june lunch time div2 2020
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll s, n;
        cin >> s >> n;
        ll count = 0;
        if (s % 2 != 0)
        {
            count += 1;
            s -= 1;
        }
        if (s == 0)
        {
            cout << "1" << endl;
        }
        else
        {
            if (s > n)
            {
                ll q = s / n;
                count += q;
                ll rem = s % n;
                if (rem != 0)
                {
                    count += 1;
                }
            }
            else
            {
                count += 1;
            }

            cout << count << endl;
        }
    }
}