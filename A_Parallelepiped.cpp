// codeforces #138 div 2
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0);

int main()
{
    fast ll lb, bh, hl;
    cin >> lb >> bh >> hl;
    ll lbh = sqrt(lb * bh * hl);
    cout << 4 * (lbh / bh + lbh / hl + lbh / lb) << endl;

    return 0;
}