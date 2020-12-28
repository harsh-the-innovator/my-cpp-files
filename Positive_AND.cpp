// codechef october long challenge  2020
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

bool isPowerOf2(int n)
{
    return !(n & (n - 1));
}

void solve(int n)
{
    if (n == 1)
    {
        cout << "1" << endl;
        return;
    }
    if (n == 3)
    {
        cout << "1 3 2" << endl;
        return;
    }

    if (n == 5)
    {
        cout << "2 3 1 5 4" << endl;
        return;
    }
    if (isPowerOf2(n))
    {
        cout << "-1" << endl;
        return;
    }

    int i = 6;
    cout << "2 3 1 5 4 ";
    while (i <= n)
    {
        if (isPowerOf2(i))
        {
            cout << i + 1 << " " << i << " ";
            i += 2;
        }
        else
        {
            cout << i << " ";
            i++;
        }
    }
    cout << endl;
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        solve(n);
    }

    return 0;
}