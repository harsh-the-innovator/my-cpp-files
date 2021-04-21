#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

int main()
{
    fast int a, b, c;
    cin >> a >> b >> c;

    if (a != b && b != c && a != c)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;

    return 0;
}