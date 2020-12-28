#include <bits/stdc++.h>
using namespace std;

void solve(int n, int s, int d, int h)
{
    if (n == 1)
    {
        cout << "Moving plate " << n << " from " << s << " to " << d << "\n";
        return;
    }

    solve(n - 1, s, h, d);
    cout << "Moving plate " << n << " from " << s << " to " << d << "\n";
    solve(n - 1, h, d, s);
}

int main()
{
    int n;
    cout << "Enter number of plates: \n";
    cin >> n;
    int s = 1, h = 2, d = 3; // s = source, h = helper, d = destination
    solve(n, s, d, h);
}