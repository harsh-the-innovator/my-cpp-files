// may 2020 long challenge codechef
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    set<int> s;
    int count;
    int i = 1;
    while (i < n)
    {
        int temp = i;
        int j = i + 1;
        while (j <= n && temp <= n && arr[j] - arr[temp] <= 2)
        {
            j++;
            temp++;
            if (j > n || temp > n)
                break;
        }

        count = j - i;
        s.insert(count);
        i = j;
    }

    if (i == n)
        s.insert(1);

    set<int>::iterator itrmin = min_element(s.begin(), s.end());
    set<int>::iterator itrmax = max_element(s.begin(), s.end());
    cout << *itrmin << " " << *itrmax;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}