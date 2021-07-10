// The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate span of stock’s price for all n days.
// The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
// For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}
#include <bits/stdc++.h>
using namespace std;

void solve(int arr[], int n)
{
    vector<int> ans;
    stack<pair<int, int>> st;

    for (int i = 0; i < n; i++)
    {
        if (st.empty())
        {
            ans.push_back(-1);
        }
        else if (!st.empty() && st.top().first > arr[i])
        {
            ans.push_back(st.top().second);
        }
        else if (!st.empty() && st.top().first <= arr[i])
        {
            while (!st.empty() && st.top().first <= arr[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(st.top().second);
            }
        }

        st.push({arr[i], i});
    }

    for (int i = 0; i < n; i++)
    {
        ans[i] = i - ans[i];
    }

    for (auto el : ans)
    {
        cout << el << " ";
    }
}

int main()
{
    int arr[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(arr) / sizeof(arr[0]);
    solve(arr, n);
    cout << endl;
}

// NOTE:- we have to find consecutive smaller or equal to current element i.e we need to find previous greater element index
//  and subtract it from current index