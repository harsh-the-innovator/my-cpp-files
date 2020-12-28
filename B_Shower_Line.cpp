// codeforces #247 div2 B
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

int g[6][6];

int main()
{
    fast int n = 5;
    rep(i, n)
    {
        rep(j, n)
        {
            cin >> g[i][j];
        }
    }

    int p[6], ans = -1, temp;
    rep(i, n)
    {
        p[i] = i;
    }

    do
    {
        //01234
        temp = g[p[0]][p[1]] + g[p[1]][p[0]];
        temp += g[p[2]][p[3]] + g[p[3]][p[2]];

        //1234
        temp += g[p[1]][p[2]] + g[p[2]][p[1]];
        temp += g[p[3]][p[4]] + g[p[4]][p[3]];

        //234
        temp += g[p[2]][p[3]] + g[p[3]][p[2]];

        //34
        temp += g[p[3]][p[4]] + g[p[4]][p[3]];

        if (temp > ans)
        {
            ans = temp;
        }
    } while (next_permutation(p, p + n));

    cout << ans << endl;
    return 0;
}