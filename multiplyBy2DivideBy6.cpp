// codeforces #653 div3 B
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        int s2 = 0, s3 = 0;
        while (n % 2 == 0)
        {
            n = n / 2;
            s2++;
        }

        while (n % 3 == 0)
        {
            n = n / 3;
            s3++;
        }

        if (n == 1)
        {
            if (s3 >= s2)
            {
                cout << 2 * s3 - s2 << endl;
            }
            else
            {
                cout << "-1" << endl;
            }
        }
        else
        {
            cout << "-1" << endl;
        }
    }
}