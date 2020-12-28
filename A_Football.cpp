// codeforces beta round #77 dov2 A
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int ans = 1, temp = 1;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == s[i - 1])
        {
            temp++;
        }
        else
        {
            ans = max(ans, temp);
            temp = 1;
        }
    }
    ans = max(ans, temp);

    if (ans >= 7)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}