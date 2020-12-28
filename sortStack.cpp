// sorting stack using recursion
#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &s, int temp)
{
    if (s.size() == 0 || s.top() <= temp)
    {
        s.push(temp);
        return;
    }

    int val = s.top();
    s.pop();
    insert(s, temp);
    s.push(val);
}

void sortStack(stack<int> &s)
{
    if (s.size() == 1)
        return;

    int temp = s.top();
    s.pop();
    sortStack(s);
    insert(s, temp);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    stack<int> s;

    // inserting element into stack
    for (int i = 0; i < n; i++)
    {
        s.push(arr[i]);
    }

    sortStack(s);

    // printing elements of stack
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}