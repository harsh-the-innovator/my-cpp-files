// codeforces #658 div2 A
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast ios_base::sync_with_stdio(0), cin.tie(0);

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll arr[n];
        rep(i, n)
        {
            cin >> arr[i];
        }

        bool flag = 1;
        rep(i, n)
        {
            if (arr[i] == 1)
            {
                flag = !flag;
            }
            else
            {
                flag = !flag;
                break;
            }
        }

        if (flag == 0)
        {
            cout << "First" << endl;
        }
        else
        {
            cout << "Second" << endl;
        }
    }
    return 0;
}