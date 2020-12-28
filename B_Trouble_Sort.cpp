// codeforces #648 div 2
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
#define fast ios_base::sync_with_stdio(0), cin.tie(0);

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi a(n), type(n);
        rep(i, n) cin >> a[i];
        rep(i, n) cin >> type[i];
        int c1 = 0, c2 = 0;
        rep(i, n)
        {
            if (type[i] == 0)
                c1++;
            if (type[i] == 1)
                c2++;
        }

        if (c1 > 0 && c2 > 0)
        {
            cout << "Yes" << endl;
        }
        else
        {
            // check for sorted
            bool sorted = true;
            loop(i, 0, n - 2)
            {
                if (a[i] > a[i + 1])
                {
                    sorted = false;
                    break;
                }
            }
            if (sorted)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}