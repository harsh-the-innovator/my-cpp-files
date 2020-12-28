// facebook hackercup 2020
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define all(c) c.begin(), c.end()
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define fast ios_base::sync_with_stdio(0), cin.tie(0);

void solve(string s, int n)
{
    int cntA = count(all(s), 'A');
    int cntB = n - cntA;
    if (abs(cntA - cntB) == 1)
    {
        cout << "Y";
    }
    else
    {
        cout << "N";
    }
}

int main()
{
    fast int t;
    cin >> t;
    loop(i, 1, t)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << "Case #" << i << ": ";
        solve(s, n);
        cout << endl;
    }
    return 0;
}