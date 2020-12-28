// codeforces educational round 15 A.Maximum Increase
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ll max = 1;
    ll len = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
            len++;
        else
        {
            if (max < len)
                max = len;
            len = 1;
        }
    }

    if (max < len)
        max = len;
    cout << max << endl;
}