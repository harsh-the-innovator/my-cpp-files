#include <iostream>
using namespace std;

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
        return (x % m + m) % m;
    }
}

int modFact(int n, int p)
{
    if (n >= p)
        return 0;
    int res = (p - 1);
    for (int i = n + 1; i < p; i++)
    {
        res = (res * modInverse(i, p)) % p;
    }
    return res;
}

int main()
{
    int n = 21, p = 71;
    cout << "n%p = " << modFact(n, p);
    return 0;
}