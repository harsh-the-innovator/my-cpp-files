#include <bits/stdc++.h>
using namespace std;
int t[21];
int printFibonacci(int n)
{
    for (int i = 0; i <= n; i++)
    {
        if (i <= 1)
        {
            t[i] = i;
        }
        else
        {
            t[i] = t[i - 1] + t[i - 2];
        }
    }

    return t[n];
}
int main()
{
    int n;
    cin >> n;
    memset(t, -1, sizeof(t));
    cout << printFibonacci(n) << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << t[i] << " ";
    }
}