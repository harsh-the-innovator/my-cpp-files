// codeforces beta round #89 div2
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);
int main()
{
    fast
        string s;
    cin >> s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    int i = 0;
    while (i < s.length())
    {
        if (s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u' or s[i] == 'y')
        {
            s.erase(i, 1);
        }
        else
        {
            i++;
        }
    }

    rep(i, s.length())
    {
        cout << "." << s[i];
    }
    cout << endl;
}