// codeoforces #180 div2B
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define int long long
#define rep(i, n) for (i = 0; i < n; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

int32_t main()
{
    fast int t, sx, sy, ex, ey;
    cin >> t >> sx >> sy >> ex >> ey;
    string s;
    cin >> s;
    int index = 0;
    int i;
    rep(i, t)
    {
        if (s[i] == 'N')
        {
            if (ey > sy)
            {
                sy++;
            }
        }
        else if (s[i] == 'S')
        {
            if (ey < sy)
            {
                sy--;
            }
        }
        else if (s[i] == 'E')
        {
            if (ex > sx)
            {
                sx++;
            }
        }
        else if (s[i] == 'W')
        {
            if (ex < sx)
            {
                sx--;
            }
        }

        if (sx == ex && sy == ey)
        {
            break;
        }
    }

    if (sx == ex && sy == ey)
    {
        cout << i + 1 << endl;
    }
    else
    {
        cout << "-1" << endl;
    }

    return 0;
}