// codeforces #650 2020 div3
#include <iostream>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int count = 0;
    int zero = 0;
    int one = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 != a[i] % 2)
        {
            if (a[i] % 2 == 0)
                zero++;
            if (a[i] % 2 == 1)
                one++;
            count++;
        }
    }

    if (count == 0)
    {
        cout << "0" << endl;
    }
    else if (one != zero)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << count / 2 << endl;
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