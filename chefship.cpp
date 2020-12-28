//2020 codechef may cook off CHEFSHIP
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 100000007
#define MAX 100005

int p = 31;

ll hashf[MAX], power[MAX];

void compute_hash(string s, int n)
{
    for (int i = 0; i < n; i++)
    {
        hashf[i + 1] = (hashf[i] * p + s[i] - 'a' + 1) % MOD;
    }
}

int gethash(int l, int r)
{
    return (hashf[r + 1] - (hashf[l] * power[r - l + 1] % MOD) + MOD) % MOD;
}

void solve()
{
    string s;
    cin >> s;

    int count = 0;
    int n = s.length();
    compute_hash(s, n);
    for (int i = 2; i <= n - 2; i += 2)
    {
        int t1 = gethash(0, i / 2 - 1);
        int t2 = gethash(i / 2, i - 1);
        int t3 = gethash(i, (n + i) / 2 - 1);
        int t4 = gethash((i + n) / 2, n - 1);

        if (t1 == t2 && t3 == t4)
            count++;
    }

    cout << count << endl;
}

int main()
{
    power[0] = 1;
    for (int i = 1; i < MAX; i++)
    {
        power[i] = (power[i - 1] * p) % MOD;
    }
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}