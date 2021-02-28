#include <bits/stdc++.h>
using namespace std;

int solve(string str, int i, int j)
{
    if (i > j)
        return 0;

    if (i == j)
        return 1;

    if (str[i] == str[j])
    {
        int remainingStringLength = j - i - 1;
        if (remainingStringLength == solve(str, i + 1, j - 1))
        {
            return 2 + remainingStringLength;
        }
    }
    return max(solve(str, i + 1, j), solve(str, i, j - 1));
}

int main()
{
    string x = "agbcba";
    cout << "Longest Pallindromic substring length = " << solve(x, 0, x.length()) << endl;
}