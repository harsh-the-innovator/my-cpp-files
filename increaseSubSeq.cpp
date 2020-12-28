#include <iostream>
#include <algorithm>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (s[j] < s[i])
            {
                arr[i] = max(arr[i], arr[j] + 1);
            }
        }
    }
    int *ptr = max_element(arr, arr + n);
    cout << *ptr << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}