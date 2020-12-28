// codeforces 2020 #653 div3 C
#include <bits/stdc++.h>
using namespace std;
#define rep(a, b) for (int i = a; i < b; i++)
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 0;
        int total = 0;
        rep(0, n)
        {
            if (s[i] == '(')
            {
                total++;
            }
            else
            {
                total--;
            }

            if (total < 0)
            {
                ans++;
                total = 0;
            }
        }
        cout << ans << endl;
    }
}