#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

int main()
{
    fast int n, m;
    cin >> n >> m;
    string s;
    rep(i, n)
    {
        cin >> s;
        rep(j, m)
        {
            if (s[j] == '.')
            {
                if ((i + j) & 1)
                    s[j] = 'W';
                else
                    s[j] = 'B';
            }
        }
        cout << s << endl;
    }

    return 0;
}