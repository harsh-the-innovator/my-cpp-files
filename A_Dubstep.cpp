// codeforces #130 div2
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define pb push_back
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

int main()
{
    fast string s, ans = "";
    cin >> s;
    int n = s.length();
    while (s.length() >= 3 && s.substr(0, 3) == "WUB")
    {
        s.erase(0, 3);
    }

    int i = s.length() - 3;
    while (s.length() >= 3 && s.substr(i, 3) == "WUB")
    {
        s.erase(i, i + 3);
    }

    for (int i = 0; i < s.length();)
    {
        if (s.substr(i, 3) == "WUB")
        {
            if (ans.back() != ' ')
            {
                ans.pb(' ');
            }
            i += 3;
        }
        else
        {
            ans.pb(s[i]);
            i++;
        }
    }

    cout << ans << endl;

    return 0;
}