// codeforces chinese remainder theorem question A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int ch;
    string str;
    cin >> str;
    ll sum = 0, counteven = 0;
    bool zero = false;
    for (ll i = 0; i < str.length(); i++)
    {
        int ch = str[i] - '0';
        if (ch % 2 == 0)
            counteven++;
        if (ch == 0)
            zero = true;
        sum += ch;
    }

    if (sum % 3 == 0 && counteven > 1 && zero == true)
        cout << "red" << endl;
    else
        cout << "cyan" << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}