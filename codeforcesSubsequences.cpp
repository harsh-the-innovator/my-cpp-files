#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll k;
    cin >> k;
    string s = "codeforces";
    int count[11];
    for (ll i = 0; i < 11; i++)
        count[i] = 1;

    ll prod = 1;
    while (prod < k)
    {
        for (ll i = 0; i < 10; i++)
        {
            count[i]++;
            prod = prod / (count[i] - 1);
            prod = prod * count[i];

            if (prod >= k)
                break;
        }
    }

    for (ll i = 0; i < 10; i++)
    {
        while (count[i] > 0)
        {
            cout << s[i];
            count[i]--;
        }
    }

    cout << endl;
}
