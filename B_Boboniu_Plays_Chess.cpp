// codeforces #644 div2 B
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define revloop(i, a, b) for (int i = a; i >= b; i--)
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

int main()
{
    fast int n, m, x, y;
    cin >> n >> m >> x >> y;
    cout << x << " " << y << endl;
    loop(i, 1, n)
    {
        if (i != x)
            cout << i << " " << y << endl;
    }

    int dir = 0; //means at bottom
    loop(i, 1, m)
    {
        if (i == y)
            continue;

        if (dir == 0)
        {
            cout << n << " " << i << endl;
            revloop(j, n - 1, 1)
            {
                cout << j << " " << i << endl;
            }
            dir = 1;
        }
        else
        {
            cout << "1 " << i << endl;
            loop(j, 2, n)
            {
                cout << j << " " << i << endl;
            }
            dir = 0;
        }
    }

    return 0;
}