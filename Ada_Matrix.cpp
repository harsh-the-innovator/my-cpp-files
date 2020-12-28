// codechef september long challenge 2020
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

int mat[65][65];
bool arr[65]{0};

void solve(bool a[], int n)
{
    int ans = 0;
    int i = n;
    while (i >= 2)
    {
        if (a[i] == 0)
        {
            // do something

            a[i] = 1;
            ans++;
            int j;
            for (j = i - 1; j >= 2; j--)
            {
                a[j] = a[j] == 1 ? 0 : 1;
            }
        }
        i--;
    }

    cout << ans << endl;
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        memset(mat, 0, sizeof(mat));
        loop(i, 1, n)
        {
            loop(j, 1, n)
            {
                cin >> mat[i][j];
            }
        }
        loop(i, 2, n)
        {
            if (mat[1][i] == i)
            {
                arr[i] = 1;
            }
            else
            {
                arr[i] = 0;
            }
        }

        solve(arr, n);
    }

    return 0;
}