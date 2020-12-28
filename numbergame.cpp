#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s1 = "Ashishgup";
        string s2 = "FastestFinger";

        if (n == 1)
        {
            cout << s2 << endl;
        }
        else if (n == 2)
        {
            cout << s1 << endl;
        }
        else if (n > 2 && n % 2 == 1)
        {
            cout << s1 << endl;
        }
        else
        {
            // if it is power of 2
            if ((int)(n & n - 1) == 0)
            {
                cout << s2 << endl;
            }
            else if (n % 4 == 0)
            {
                cout << s1 << endl;
            }
            else if (isPrime(n / 2))
            {
                cout << s2 << endl;
            }
            else
            {
                cout << s1 << endl;
            }
        }
    }
}