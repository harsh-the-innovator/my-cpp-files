// codeforces 2020 #654 div2 B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, r;
        cin >> n >> r;
        ll result = 0;
        if (r < n)
        {
            result = (r * (r + 1)) / 2LL;
            cout << result << endl;
        }
        else
        {
            result = ((n - 1) * n) / 2LL;
            cout << result + 1 << endl;
        }
    }
}