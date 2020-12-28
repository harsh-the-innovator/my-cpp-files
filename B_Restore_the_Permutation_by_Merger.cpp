// codeforces #656 div3
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast ios_base::sync_with_stdio(0), cin.tie(0);

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n;
        int arr[2 * n];
        unordered_set<int> s;
        rep(i, 2 * n)
        {
            cin >> arr[i];
        }

        rep(i, 2 * n)
        {
            if (s.find(arr[i]) == s.end())
            {
                cout << arr[i] << " ";
                s.insert(arr[i]);
            }
        }
        cout << endl;
    }
    return 0;
}