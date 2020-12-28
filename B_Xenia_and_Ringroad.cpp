// codeforces #197 div2 B
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define fast ios_base::sync_with_stdio(0), cin.tie(0);

int main()
{
    ll n, m;
    cin >> n >> m;
    ll arr[m + 1];
    loop(i, 1, m)
    {
        cin >> arr[i];
    }
    ll time = 0;
    ll i = 1, f;
    loop(j, 1, m)
    {
        f = arr[j];
        if (i <= f)
        {
            time += (f - i);
        }
        else
        {
            time += (n + f - i);
        }
        i = f;
    }

    cout << time << endl;
    return 0;
}