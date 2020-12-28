#include <bits/stdc++.h>
using namespace std;
#define N 100
int main()
{
    string a, b;
    cin >> a >> b;
    int n = a.length();
    bitset<N> b1(a), b2(b);
    bitset<N> ans;
    for (int i = 0; i < n; i++)
    {
        ans[i] = b1[i] ^ b2[i];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        cout << ans[i];
    }
    cout << endl;
}
