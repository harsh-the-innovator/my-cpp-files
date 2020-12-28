// generate all subsets using bitmasking
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int numSubsets = (1 << n) - 1;
    set<vector<int>> s;
    for (int i = 0; i <= numSubsets; i++)
    {
        vector<int> subset;
        subset.clear();
        // now looping through all bits and finding bits those are 1
        for (int j = 0; j < n; j++)
        {
            if ((i & (1 << j)) != 0)
            {
                subset.push_back(a[j]);
            }
        }

        s.insert(subset);
    }

    for (auto item : s)
    {
        sort(item.begin(), item.end());
    }
    for (auto itr = s.begin(); itr != s.end(); itr++)
    {
        vector<int> ans = *itr;
        cout << "(";
        for (int j = 0; j < ans.size(); j++)
        {
            if (j == ans.size() - 1)
            {
                cout << ans[j];
            }
            else
            {
                cout << ans[j] << " ";
            }
        }
        cout << ")";
    }
}