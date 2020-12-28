// #codeforces #660 div 2 A
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (n < 31)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            if (n == 36)
            {
                cout << "5 6 10 15" << endl;
            }
            else if (n == 40)
            {
                cout << "6 10 15 9" << endl;
            }
            else if (n == 44)
            {
                cout << "6 7 10 21" << endl;
            }
            else
            {
                cout << "6 10 14 " << (n - 6 - 10 - 14) << endl;
            }
        }
    }

    return 0;
}