// codeforces #655 div 2 A
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

void solve(int n, int k)
{
    if (k == 0)
    {
        if (n % 2 == 0)
            cout << "0" << endl;
        else
            cout << "1" << endl;
    }
    else
    {
        if (k >= n)
        {
            cout << k - n << endl;
        }
        else
        {
            if ((k + n) % 2 == 0)
            {
                cout << "0" << endl;
            }
            else
            {
                cout << "1" << endl;
            }
        }
    }
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        solve(n, k);
    }

    return 0;
}