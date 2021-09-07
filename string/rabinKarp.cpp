#include <bits/stdc++.h>
using namespace std;
#define P 683303 // PRIME NUMBER
#define d 256    // TOTAL CHARACTERS IN ALBHABET IN GENERAL

// int findHash()
// {
// }

void rabinKarp(string text, string pattern)
{
    int m = text.length();
    int n = pattern.length();

    int hashPattern = 0;
    int hashText = 0;
    int h = 1;
    // The value of h would be "pow(d, n-1)%Prime"
    for (int i = 0; i < n - 1; i++)
        h = (h * d) % P;

    // Calculating Hash value for pattern and first window of text
    for (int i = 0; i < n; i++)
    {
        hashPattern = (d * hashPattern + pattern[i]) % P;
        hashText = (d * hashText + pattern[i]) % P;
    }

    // NOW comparing every substring hash values with pattern hash value and sliding the window

    for (int i = 0; i <= m - n; i++)
    {
        if (hashPattern == hashText)
        {
            // since hashes match so now we will compare characters
            bool flag = true;
            int j;
            for (j = 0; j < n; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                cout << "Pattern found at index = " << i << endl;
            }
        }
        else
        {
            if (i < m - n)
            {
                hashText = (d * (hashText - text[i] * h) + text[i + n]) % P;

                if (hashText < 0)
                {
                    hashText = hashText + P;
                }
            }
        }
    }
}

int main()
{
    string text = "ccabccdabc";
    string pattern = "abc";
    rabinKarp(text, pattern);
}