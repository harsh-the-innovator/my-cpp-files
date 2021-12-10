#include <bits/stdc++.h>
using namespace std;

int findLength(string str, int k)
{
    int n = str.length();
    unordered_map<char, int> mp;
    int maxLength = 0;
    int start = 0;

    for (int end = 0; end < n; end++)
    {
        char rightChar = str[end];
        mp[rightChar]++;

        while (mp.size() > k)
        {
            char leftChar = str[start];
            mp[leftChar]--;

            if (mp[leftChar] == 0)
            {
                mp.erase(leftChar);
            }
            start++;
        }

        maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
}

int main()
{
    string s = "araaci";
    int k = 2;
}

// hello worls