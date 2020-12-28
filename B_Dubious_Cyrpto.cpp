#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define fast ios_base::sync_with_stdio(0), cin.tie(0);

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        ll l, r, m, m1, m2, a, b, c;
        cin >> l >> r >> m;
        ll diff = r - l;
        loop(i, l, r)
        {
            m1 = m % i;
            m2 = i - (m % i);

            if (i <= m && m1 <= diff)
            {
                a = i;
                b = r;
                c = r - m1;
                break;
            }
            else if (m2 <= diff)
            {
                a = i;
                b = r - m2;
                c = r;
                break;
            }
        }

        cout << a << " " << b << " " << c << endl;
    }
    return 0;
}