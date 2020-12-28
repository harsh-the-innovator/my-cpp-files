#include <iostream>
#include <vector>
using namespace std;
bool find(int a[], int start, int end, int l)
{
    bool p = false;
    for (int i = 1; i <= l; i++)
    {
        for (int j = start; j <= end; j++)
        {
            if (i == a[j])
            {
                p = true;
                break;
            }
            else
            {
                p = false;
            }
        }

        if (!p)
        {
            break;
        }
    }

    return p;
}
void solve()
{
    int n, l1, l2, k = 0;
    bool p1, p2;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    //partition
    int p = 1;
    bool status = false;
    while (p < n)
    {
        l1 = p;
        l2 = n - p;
        vector<int> v1, v2;
        p1 = false;
        p2 = false;

        p1 = find(a, 1, p, l1);
        if (p1)
        {
            p2 = find(a, p + 1, n, l2);
        }
        if (p1 && p2)
        {
            status = true;
            k++;
            v1.push_back(l1);
            v2.push_back(l2);
        }
        p++;
    }

    if (!status)
    {
        cout << "0" << endl;
    }

    vector<int>::iterator itr;
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