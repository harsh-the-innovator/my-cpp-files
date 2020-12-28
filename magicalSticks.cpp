// codeforces 2020 #654 div2 A
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
        if (n % 2 == 0)
        {
            cout << n / 2;
        }
        else
        {
            cout << (n - 1) / 2 + 1;
        }
        cout << endl;
    }
}