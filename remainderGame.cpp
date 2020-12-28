// codeforces 687 b remainder game chinese remainder thorem
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int gcdExtended(int a, int b, int &x, int &y)
{
    // Base Case
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }

    int x1, y1; // To store results of recursive call
    int d = gcdExtended(b, a % b, x1, y1);

    // Update x and y using results of recursive
    // call
    x = y1;
    y = x1 - (a / b) * y1;

    return d;
}

int modInverse(int a, int m)
{
    int x, y;
    int g = gcdExtended(a, m, x, y);
    if (g != 1)
        return 0;
    else
    {
        // m is added to handle negative x
        return (x % m + m) % m;
    }
}
int main()
{
    ll n, k;
    cin >> n >> k;
    ll arr[n], pp[n];
    ll prod = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        prod *= arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        pp[i] = prod / arr[i];
    }
}