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
    int num[] = {3, 4, 5};
    int rem[] = {2, 3, 1};
    // output 11
    int prod = 1;
    for (int i = 0; i < 3; i++)
    {
        prod *= num[i];
    }

    int pp[3];
    for (int i = 0; i < 3; i++)
    {
        pp[i] = prod / num[i];
    }

    int res = 0;
    for (int i = 0; i < 3; i++)
    {
        res = (res + (pp[i] * rem[i] * modInverse(pp[i], num[i]))) % prod;
    }

    cout << "x = " << res;
}