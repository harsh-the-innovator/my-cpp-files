#include <bits/stdc++.h>

using namespace std;

#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

void solve()
{
    long long a, b;
    cin >> a >> b;
    int g = gcd(a, b);
    int l = (a / g) * b;
    cout << g << " " << l << endl;
}

int main()
{
    fastIO int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
