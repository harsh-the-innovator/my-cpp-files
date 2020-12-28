// game of death in a circle using recursion
#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &v, int k, int index, int &ans)
{
    if (v.size() == 1)
    {
        ans = v[0];
        return;
    }

    index = (index + k) % (v.size());
    v.erase(v.begin() + index);
    solve(v, k, index, ans);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cout << "Enter number of persons and step :";
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            v[i] = i + 1;
        }

        int ans = 0;
        k--;
        solve(v, k, 0, ans);
        cout << "Safe position: " << ans << endl;
    }
}