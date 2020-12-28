// https: //codeforces.com/contest/633/problem/A
// ebony and ivory

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool linearDio(int a, int b, int c, int &x0, int &y0, int &g)
{
    g = gcd(a, b, x0, y0);
    if (c % g)
    {
        return false;
    }
    x0 *= c / g;
    y0 *= c / g;
    return true;
}

int main()
{
    int x1, y1;
    int g1 = gcd(4, 7, x1, y1);
    cout << x1 << " " << y1;
    int a, b, c;
    cin >> a >> b >> c;
    int x, y, g;
    bool res = linearDio(a, b, c, x, y, g);
    if (res)
    {
        if (x < 0)
        {
            while (1)
            {
                if (x >= 0)
                {
                    break;
                }
                else
                {
                    x = x + (b / g);
                    y = y - (a / g);
                }
            }
        }

        if (y < 0)
        {
            while (1)
            {
                if (y >= 0)
                {
                    break;
                }
                else
                {
                    x = x - (b / g);
                    y = y + (a / g);
                }
            }
        }

        if (x < 0 || y < 0)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
    else
    {
        cout << "No" << endl;
    }
}