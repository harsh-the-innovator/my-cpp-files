// codechef july 2020 long challenge div 2
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(a, b) for (int i = a; i <= b; i++)
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll arr[n];
        ll total = 0;
        rep(0, n - 1)
        {
            cin >> arr[i];
        }

        rep(1, n - 1)
        {
            total += (abs(arr[i] - arr[i - 1]) - 1);
        }
        cout << total << endl;
    }
}