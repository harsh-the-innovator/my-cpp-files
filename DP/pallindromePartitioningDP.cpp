#include <bits/stdc++.h>
using namespace std;

//see gfg fore reference

int palindromicPartition(string str)
{
    int n = str.length();
    int C[n];
    bool P[n][n];

    // when length is 1 then it is pallindrome
    for (int i = 0; i < n; i++)
    {
        P[i][i] = 1;
    }

    // now filling from length 2 to n
    for (int L = 2; L <= n; L++)
    {
        for (int i = 0; i < n - L + 1; i++)
        {
            int j = i + L - 1;

            if (L == 2)
            {
                P[i][j] = str[i] == str[j];
            }
            else
            {
                P[i][j] = str[i] == str[j] ? P[i + 1][j - 1] : false;
            }
        }
    }

    //now after filling pallindrome matrix , we will find minimum number of cuts
    for (int i = 0; i < n; i++)
    {
        // if already pallindrome the cuts = 0;
        if (P[0][i])
            C[i] = 0;
        else
        {
            C[i] = INT_MAX;
            for (int j = 0; j < i; j++)
            {
                if (P[j + 1][i] == true & C[j] + 1 < C[i])
                    C[i] = C[j] + 1;
            }
        }
    }

    return C[n - 1];
}
int main()
{
    string str = "ababbbabbababa";
    cout << "Minimum number of cuts = " << palindromicPartition(str);
    //ans = 3
}