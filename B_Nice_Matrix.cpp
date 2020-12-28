// codeforces #675 div 2 B 2020
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define pi (3.141592653589)
#define mod 1e9 + 7
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

ll mat[101][101];

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        memset(mat, 0, sizeof(mat));
        loop(i, 1, n)
        {
            loop(j, 1, m)
            {
                cin >> mat[i][j];
            }
        }

        int rstart = 1, rend = n, cstart = 1, cend = m;
        ll res = 0;
        while (rstart <= rend)
        {
            cstart = 1, cend = m;
            while (cstart <= cend)
            {
                ll a = mat[rstart][cstart];
                ll b = mat[rstart][cend];
                ll c = mat[rend][cstart];
                ll d = mat[rend][cend];
                if (rstart == rend && cstart != cend)
                {
                    ll avg = (a + b) / 2;
                    res += abs(avg - a) + abs(avg - b);
                }
                else if (rstart != rend && cstart == cend)
                {
                    ll avg = (a + c) / 2;
                    res += abs(avg - a) + abs(avg - c);
                }
                else if (rstart != rend && cstart != cend)
                {
                    ll avg = (a + b + c + d) / 4;
                    res += abs(avg - a) + abs(avg - b) + abs(avg - c) + abs(avg - d);
                }

                cstart++;
                cend--;
            }
            rstart++;
            rend--;
        }
        cout << res << endl;
    }

    return 0;
}