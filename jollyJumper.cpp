#include <bits/stdc++.h>
using namespace std;
bool isJolly(vector<int> v, int n)
{
    vector<int> absDiffSet(n, false);
    int diff;
    for (int i = 0; i < n - 1; i++)
    {
        diff = abs(v[i] - v[i + 1]);

        if (diff == 0 || diff > n - 1 || absDiffSet[diff] == true)
        {
            return false;
        }

        absDiffSet[diff] = true;
    }
    return true;
}

int main()
{
    // 11 7 4 2 1 6
    int n, x;
    vector<int> v;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    if (isJolly(v, n))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}