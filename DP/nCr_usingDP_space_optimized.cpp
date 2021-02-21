#include <bits/stdc++.h>
using namespace std;
//see gfg for this solution // it is space optimized - O(r);
int findnCr(int n, int r)
{
    int C[r + 1];
    memset(C, 0, sizeof(C));

    C[0] = 1; // nC0 is 1

    for (int i = 1; i <= n; i++)
    {
        // Compute next row of pascal triangle using
        // the previous row
        for (int j = min(i, r); j > 0; j--)
            C[j] = C[j] + C[j - 1];
    }
    return C[r];
}
int main()
{
    cout << "Enter n and r:\n";
    int n, r;
    cin >> n >> r;
    cout << "nCr = " << findnCr(n, r) << endl;
}