#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        float k1, k2, k3, v;
        cin >> k1 >> k2 >> k3 >> v;

        float t = 9.58;
        float newv = k1 * k2 * k3 * v;
        float newt = 100.0 / newv;
        newt = round(newt * 100) / 100;

        if (newt < t)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}