#include <bits/stdc++.h>
using namespace std;

int solve(string str)
{
    int n = str.length();

    // dp[i][j] will be false if substring
    // str[i..j] is not palindrome.
    // Else dp[i][j] will be true
    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    // All substrings of length 1
    // are palindromes
    int maxLength = 1;

    for (int i = 0; i < n; ++i)
        dp[i][i] = true;

    // check for sub-string of length 2.
    int start = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (str[i] == str[i + 1])
        {
            dp[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    // Check for lengths greater than 2.
    // L is length of substring
    for (int L = 3; L <= n; ++L)
    {
        // Fix the starting index
        for (int i = 0; i < n - L + 1; ++i)
        {
            // Get the ending index of substring from
            // starting index i and length L
            int j = i + L - 1;

            // checking for sub-string from ith index to
            // jth index iff str[i+1] to str[j-1] is a
            // palindrome
            if (dp[i + 1][j - 1] && str[i] == str[j])
            {
                dp[i][j] = true;

                if (L > maxLength)
                {
                    start = i;
                    maxLength = L;
                }
            }
        }
    }

    // to print the pallindromic substring:-
    // for (int i = start; i <= start + maxLength - 1; ++i)
    //     cout << str[i];
    // cout << endl;
    return maxLength;
}

int main()
{
    string str = "agbcba";
    cout << "Longest Pallindromic substring length = " << solve(str) << endl;
}