#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &s, int k)
{
    if (k == 1)
    {
        s.pop();
        return;
    }

    int temp = s.top();
    s.pop();
    solve(s, k - 1);
    s.push(temp);
    return;
}

void deleteMid(stack<int> &s, int n)
{
    if (n == 0)
        return;
    int k = n / 2 + 1;
    solve(s, k);
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

    deleteMid(s, n);

    // print resultant stack
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}