// codeforces beta round #54 div2
#include <bits/stdc++.h>
using namespace std;
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);
int main()
{
    fast
        string s;
    cin >> s;
    int n = s.length();
    int i = 0;
    int flag = 0;
    while (i <= n - 5)
    {
        if (s[i] == 'h')
        {
            flag = 1;
            break;
        }
        i++;
    }
    if (flag == 0)
        cout << "NO" << endl;
    else
    {
        i++;
        flag = 0;
        while (i <= n - 4)
        {
            if (s[i] == 'e')
            {
                flag = 1;
                break;
            }
            i++;
        }
        if (flag == 0)
            cout << "NO" << endl;
        else
        {
            i++;
            flag = 0;
            while (i <= n - 3)
            {
                if (s[i] == 'l')
                {
                    flag = 1;
                    break;
                }
                i++;
            }
            if (flag == 0)
                cout << "NO" << endl;
            else
            {
                i++;
                flag = 0;
                while (i <= n - 2)
                {
                    if (s[i] == 'l')
                    {
                        flag = 1;
                        break;
                    }
                    i++;
                }

                if (flag == 0)
                    cout << "NO" << endl;
                else
                {
                    i++;
                    flag = 0;
                    while (i < n)
                    {
                        if (s[i] == 'o')
                        {
                            flag = 1;
                            break;
                        }
                        i++;
                    }
                    if (flag == 0)
                        cout << "NO" << endl;
                    else
                        cout << "YES" << endl;
                }
            }
        }
    }
}