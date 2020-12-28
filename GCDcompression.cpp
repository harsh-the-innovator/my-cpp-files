// codeforces #651 div2 B
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int x;
    vector<int> even, odd;
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> x;
        if (x & 1)
            odd.push_back(i + 1);
        else
            even.push_back(i + 1);
    }

    if (odd.size() % 2 != 0)
    {
        odd.pop_back();
        even.pop_back();
    }
    else if (even.size() >= 2)
    {
        even.pop_back();
        even.pop_back();
    }
    else
    {
        odd.pop_back();
        odd.pop_back();
    }

    for (int i = 0; i < even.size(); i += 2)
    {
        cout << even[i] << " " << even[i + 1] << endl;
    }
    for (int i = 0; i < odd.size(); i += 2)
    {
        cout << odd[i] << " " << odd[i + 1] << endl;
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