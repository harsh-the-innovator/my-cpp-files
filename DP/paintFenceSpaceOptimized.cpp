// C++ program for Painting Fence Algorithm
#include <bits/stdc++.h>
using namespace std;

// Returns count of ways to color k posts
// using k colors
long countWays(int n, int k)
{
    // There are k ways to color first post
    long total = k;
    int mod = 1000000007;

    // There are 0 ways for single post to
    // violate (same color_ and k ways to
    // not violate (different color)
    int same = 0, diff = k;

    // Fill for 2 posts onwards
    for (int i = 2; i <= n; i++)
    {
        // Current same is same as previous diff
        same = diff;

        // We always have k-1 choices for next post
        diff = total * (k - 1);
        diff = diff % mod;

        // Total choices till i.
        total = (same + diff) % mod;
    }

    return total;
}

// Driver code
int main()
{
    int n = 3, k = 2;
    cout << countWays(n, k) << endl;
    return 0;
}