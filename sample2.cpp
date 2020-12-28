#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

int main()
{
    int n;
    cin >> n;
    int t = n - 1;
    int mat[n][n];
    memset(mat, -1, sizeof(mat));
    rep(i, n)
    {
        rep(j, n)
        {
            if (i == j)
                mat[i][j] = 1;
        }
    }
    while (t--)
    {
        int u, v;
        cin >> u >> v;
        mat[--u][--v] = 1;
    }
    int arr[n];
    rep(i, n) cin >> arr[i];
    int m;
    cin >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int ans = 0, count;
        int i = a;
        while (i <= b)
        {
            count = 0;
            if (arr[i] == 1)
            {
                int j = i;
                while (j <= b && arr[j] == 1 && mat[j - 1][j] == 1)
                {
                    j++;
                    count++;
                }
                ans = max(count, ans);
                i = j;
            }
            else
            {
                i++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}