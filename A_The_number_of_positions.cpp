// codeforces Beta Round #92 div2 A
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int ans = 0;
    if (n == a)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << min(n - a, b + 1) << endl;
    }

    return 0;
}