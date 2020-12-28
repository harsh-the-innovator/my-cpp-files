#include <bits/stdc++.h>
using namespace std;

void insert(vector<int> &v, int temp)
{
    if (v.size() == 0 || v.back() <= temp)
    {
        v.push_back(temp);
        return;
    }

    int val = v.back();
    v.pop_back();
    insert(v, temp);
    v.push_back(val);
}

void sortRecursion(vector<int> &v)
{
    if (v.size() == 1)
    {
        return;
    }

    int temp = v.back();
    v.pop_back();
    sortRecursion(v);
    insert(v, temp);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sortRecursion(arr);
    cout << endl;
    for (auto x : arr)
    {
        cout << x << " ";
    }
}