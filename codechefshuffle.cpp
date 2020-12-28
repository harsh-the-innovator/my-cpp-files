// codechef SHUFFLE
#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define ll long long
#define pb push_back
#define vint vector<int>
#define vll vector<long long>
#define pint pair<int, int>
#define pll pair<long long, long long>
#define pi 3.1415926535898
#define INF 1000000000000
#define INFM -1000000000000
#define mod1 1000000007
#define mod2 998244353
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
void print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vint v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.pb(x);
    }
    int maxIndex, count;
    int temp = n - 1;

    bool sortPossible = false;
    while (temp > 0)
    {

        maxIndex = max_element(v.begin(), v.end() - (n - 1 - temp)) - v.begin();
        if ((temp - maxIndex) % k == 0)
        {
            sortPossible = true;
            // count = (temp - maxIndex) / k;
            // while (count > 0)
            // {
            //     swap(v[maxIndex], v[maxIndex + k]);
            //     maxIndex += k;
            //     count--;
            // }
            swap(v[temp], v[maxIndex]);

            temp--;
        }
        else
        {
            sortPossible = false;
            break;
        }
        cout << endl;
    }

    if (sortPossible)
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
}

int main()
{
    fastIO int t;
    cin >> t;
    while (t--)
    {
        solve();

        cout << endl;
    }
}