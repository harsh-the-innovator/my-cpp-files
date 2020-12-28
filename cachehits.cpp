// codechef june cook off div2

#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, b, m;
    cin >> n >> b >> m;
    int arr[m];
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }

    int curBlock = arr[0] / b;
    int count = 1;
    for (int i = 1; i < m; i++)
    {
        int block = arr[i] / b;
        if (block != curBlock)
        {
            curBlock = block;
            count++;
        }
    }
    cout << count << endl;
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