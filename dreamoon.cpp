#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <climits>
using namespace std;
void solve()
{
    int n, x;
    cin >> n >> x;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    unordered_set<int> s;
    unordered_set<int>::iterator itr, max;

    for (int i = 1; i <= n; i++)
    {
        s.insert(a[i]);
    }
    max = max_element(s.begin(), s.end());
    int count = 0;
    for (int i = 1; i <= INT_MAX; i++)
    {
        itr = s.find(i);
        if (itr != s.end())
        {
            count++;
        }
        else
        {
            if (x != 0)
            {
                x--;
                count++;
            }
            else
            {
                break;
            }
        }
    }

    cout << count << endl;
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