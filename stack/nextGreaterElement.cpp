#include <bits/stdc++.h>
using namespace std;

void findNextGreaterElement(int arr[], int n)
{
    vector<int> ans;
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty())
        {
            ans.push_back(-1);
        }
        else if (!st.empty() && st.top() > arr[i])
        {
            ans.push_back(st.top());
        }
        else if (!st.empty() && st.top() <= arr[i])
        {
            while (!st.empty() && st.top() <= arr[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(st.top());
            }
        }

        st.push(arr[i]);
    }

    reverse(ans.begin(), ans.end());

    for (auto el : ans)
    {
        cout << el << " ";
    }
}

int main()
{
    int arr[] = {1, 3, 0, 0, 1, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    findNextGreaterElement(arr, n);
    cout << endl;
}