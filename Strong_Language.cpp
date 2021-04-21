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
        int k, n;
        string s;
        cin >> n >> k;
        cin >> s;
        int i = 0;
        int cnt = 0;
        bool flag = false;
        while (i < n)
        {
            if (s[i] == '*')
                cnt++;
            else
                cnt = 0;

            if (cnt >= k)
            {
                flag = true;
                break;
            }
            i++;
        }

        if (flag == true)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}