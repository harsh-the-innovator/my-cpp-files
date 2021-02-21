#include <bits/stdc++.h>
using namespace std;
int findnCr(int n, int r)
{
    if (r == 0 || n == r)
        return 1;

    return findnCr(n - 1, r) + findnCr(n - 1, r - 1);
}
int main()
{
    cout << "Enter n and r:\n";
    int n, r;
    cin >> n >> r;
    cout << "nCr = " << findnCr(n, r) << endl;
}