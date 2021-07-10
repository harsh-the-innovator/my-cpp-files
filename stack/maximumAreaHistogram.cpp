#include <bits/stdc++.h>
using namespace std;

void findNextSmallerElementIndex(int arr[], int n, vector<int> &left)
{
    stack<pair<int, int>> st;

    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty())
        {
            left.push_back(-1);
        }
        else if (!st.empty() && st.top().first < arr[i])
        {
            left.push_back(st.top().second);
        }
        else if (!st.empty() && st.top().first >= arr[i])
        {
            while (!st.empty() && st.top().first >= arr[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                left.push_back(-1);
            }
            else
            {
                left.push_back(st.top().second);
            }
        }

        st.push({arr[i], i});
    }

    reverse(left.begin(), left.end());
}

void findPreviousSmallerElementIndex(int arr[], int n, vector<int> &right)
{
    stack<pair<int, int>> st;

    for (int i = 0; i < n; i++)
    {
        if (st.empty())
        {
            right.push_back(-1);
        }
        else if (!st.empty() && st.top().first < arr[i])
        {
            right.push_back(st.top().second);
        }
        else if (!st.empty() && st.top().first >= arr[i])
        {
            while (!st.empty() && st.top().first >= arr[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                right.push_back(-1);
            }
            else
            {
                right.push_back(st.top().second);
            }
        }

        st.push({arr[i], i});
    }
}

int findMaxAreaInHistogram(int height[], int n)
{
    vector<int> left, right;
    findPreviousSmallerElementIndex(height, n, left);
    findNextSmallerElementIndex(height, n, right);

    int width[n];
    int maxarea = -1;
    for (int i = 0; i < n; i++)
    {
        width[i] = right[i] - left[i] - 1;
        maxarea = max(maxarea, width[i] * height[i]);
    }

    return maxarea;
}

int main()
{
    int arr[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Max area = " << findMaxAreaInHistogram(arr, n) << endl;
}

// NOTE:- we have to calculate NSR - NSL -1 and then take maximum from array
