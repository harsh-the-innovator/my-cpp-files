#include <iostream>
using namespace std;

// C function for extended Euclidean Algorithm
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

void modInverse(int a, int m)
{
    int x, y;
    int g = gcdExtended(a, m, x, y);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else
    {
        // m is added to handle negative x
        int res = (x % m + m) % m;
        cout << "Modular multiplicative inverse is " << res;
    }
}

// Driver Program
int main()
{
    int a = 3, m = 11;
    modInverse(a, m);
    return 0;
}