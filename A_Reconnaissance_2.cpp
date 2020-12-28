// codeforces #34 div 2
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast ios_base::sync_with_stdio(0), cin.tie(0);

int main()
{
    fast int n;
    cin >> n;
    int arr[n];
    rep(i, n)
    {
        cin >> arr[i];
    }
    int min = INT_MAX;
    int a;
    rep(i, n - 1)
    {
        if (abs(arr[i] - arr[i + 1]) < min)
        {
            min = abs((arr[i] - arr[i + 1]));
            a = i;
        }

        if (min == 0)
        {
            break;
        }
    }

    if (min == 0)
    {
        cout << a + 1 << " " << a + 2 << endl;
    }
    else
    {
        if (abs(arr[n - 1] - arr[0]) < min)
        {
            cout << n << " " << 1 << endl;
        }
        else
        {
            cout << a + 1 << " " << a + 2 << endl;
        }
    }

    return 0;
}