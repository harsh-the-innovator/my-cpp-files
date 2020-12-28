// codechef june lunchtime div2 2020
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    map<int, int> count;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        count[arr[i]]++;
    }
    int *ptr = max_element(arr, arr + n);
    vector<int> c1, c2;
    bool flag = false;
    for (auto itr = count.begin(); itr != count.end(); itr++)
    {
        if (itr->second > 2 || count[*ptr] == 2)
        {
            flag = true;
            break;
        }
        else
        {
            if (itr->second == 1)
                c1.push_back(itr->first);
            else if (itr->second == 2)
                c2.push_back(itr->first);
        }
    }

    if (flag)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        if (c2.size() == 0)
        {
            for (int i = 0; i < c1.size(); i++)
            {
                cout << c1[i] << " ";
            }
            cout << endl;
        }
        else
        {
            int i = 0, j = 0;
            while (i < c1.size() && j < c2.size())
            {
                if (c1[i] < c2[j])
                {
                    cout << c1[i] << " ";
                    i++;
                }
                else
                {
                    cout << c2[j] << " ";
                    j++;
                }
            }

            while (i < c1.size())
            {
                cout << c1[i] << " ";
                i++;
            }

            for (int i = c2.size() - 1; i >= 0; i--)
            {
                cout << c2[i] << " ";
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}