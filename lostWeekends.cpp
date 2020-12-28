// https://www.codechef.com/LTIME84B/problems/LOSTWKND

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int arr[5];
    int sum = 0, p;
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    cin >> p;
    sum *= p;
    if (sum > 120)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}