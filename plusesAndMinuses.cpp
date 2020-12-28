// codeforces round 90 div 2 C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        ll res = 0;
        ll cur = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '+')
                cur++;
            if (s[i] == '-')
                cur--;
            if (cur < 0)
            {
                res += (i + 1);
                cur = 0;
            }
        }
        cout << res + s.length() << endl;
    }
}