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
#define all(c) c.begin(), c.end()
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

int main()
{
    fast int n, d;
    cin >> n >> d;
    string s;
    cin >> s;
    int i = 0, j;
    int jumps = 0;
    while (i != n - 1)
    {
        j = i + d;
        while ((s[j] - '0') != 1 && j >= i + 1)
        {
            j--;
        }
        if (j != i)
        {
            jumps++;
            i = j;
        }
        else
        {
            break;
        }
    }

    if (i != n - 1)
        cout << "-1";
    else
        cout << jumps;

    cout << endl;

    return 0;
}