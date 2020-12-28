#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long power(long long a, long long b)
{
    a = a % mod;
    long long res = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            res *= a;
            res %= mod;
        }

        a *= a;
        a %= mod;
        b /= 2;
    }

    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, a;
        cin >> n >> a;
        long long product = 1, pval, ans = 0;
        for (int i = 0; i < n; i++)
        {
            pval = power(a * product, 2 * i - 1) % mod;
            ans = (ans + pval) % mod;
            product = (product * pval) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}