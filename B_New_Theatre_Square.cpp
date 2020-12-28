// codeforces educational round 88 div2 B
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define pi (3.141592653589)
#define mod 1e9 + 7
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) cc.begin(), c.end()
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define loop(a, b) for (int i = a; i <= b; i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        char square[n][m];
        int dots = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> square[i][j];
                if (square[i][j] == '.')
                    dots++;
            }
        }

        int price2x = 2 * x;
        int price1y = y;

        if (price2x < price1y)
        {
            cout << dots * x << endl;
        }
        else
        {
            int cost = 0, j;
            for (int i = 0; i < n; i++)
            {
                j = 0;
                while (j <= m - 1)
                {
                    if (j == m - 1)
                    {
                        if (square[i][j] == '.')
                            cost += x;
                        j++;
                    }
                    else
                    {
                        if (square[i][j] == '.' && square[i][j + 1] == '.')
                        {
                            cost += y;
                            j += 2;
                        }
                        else if (square[i][j] == '.')
                        {
                            cost += x;
                            j++;
                        }
                        else
                        {
                            j++;
                        }
                    }
                }
            }

            cout << cost << endl;
        }
    }
    return 0;
}