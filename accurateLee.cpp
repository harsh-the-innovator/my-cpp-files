// codeforces #652 div2 B

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string str;
        cin >> str;

        int i = n - 2;
        while (i >= 0)
        {
            if (str[i] == '1' && str[i + 1] == '0')
            {
                if (i + 2 != n && str[i + 2] == '0')
                {
                    str.erase(str.begin() + i + 1);
                }
                else
                {
                    str.erase(str.begin() + i);
                }
                i = str.length() - 2;
            }
            else
            {
                i--;
            }
        }

        cout << str << endl;
    }
}