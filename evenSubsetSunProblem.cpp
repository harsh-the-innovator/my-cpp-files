// codeforces Round #626 div2 A. Even Subset sum problrm
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 == 0)
            {
                flag = true;
                cout << "1\n"
                     << i + 1 << "\n";
                break;
            }
            else
            {
                v.push_back(i + 1);
                if (v.size() == 2)
                {
                    flag = true;
                    cout << "2\n"
                         << v[0] << " " << v[1] << "\n";
                    break;
                }
            }
        }

        if (flag == false)
            cout << "-1\n";
    }
}