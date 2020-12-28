// #codeforces #660 div 2 A
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long
#define loop(i, a, b) for (long long i = a; i <= b; i++)
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
        ll k = ceil(n / 4.0);
        loop(i, 1, n - k)
        {
            cout << "9";
        }
        loop(i, 1, k)
        {
            cout << "8";
        }
        cout << endl;
    }

    return 0;
}