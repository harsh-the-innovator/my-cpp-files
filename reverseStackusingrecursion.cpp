#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &s, int temp)
{
    // insert this element at last of reversed stack

    if (s.size() == 0)
    {
        s.push(temp);
        return;
    }

    int val = s.top();
    s.pop();
    insert(s, temp);
    s.push(val);
}

void reverseStack(stack<int> &s)
{
    if (s.size() == 1)
        return;

    int temp = s.top();
    s.pop();
    reverseStack(s);
    insert(s, temp);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        s.push(arr[i]);
    }

    reverseStack(s);

    // print reversed stack
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}