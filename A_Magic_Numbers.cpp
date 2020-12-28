// codeforces #189 div2 A
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

bool solve(string str)
{
    if (str[0] != '1')
        return false;

    rep(i, str.length())
    {
        if (str[i] != '4' && str[i] != '1')
        {
            return false;
        }
    }

    if (str.find("444") != str.npos)
    {
        return false;
    }

    return true;
}

int main()
{
    fast string str;
    cin >> str;
    if (solve(str))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}