#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast ios_base::sync_with_stdio(0), cin.tie(0);
int arr[26];
int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        memset(arr, 0, sizeof(arr));
        rep(i, n)
        {
            arr[s[i] - 'a']++;
        }
        int flag = 0;
        rep(i, 26)
        {
            if (arr[i] % 2 != 0)
            {
                cout << "NO";
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            cout << "YES";
        }

        cout << endl;
    }
    return 0;
}