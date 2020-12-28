// codeforces #650 2020 div3
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    set<int> st;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            st.insert(i);
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            auto itr = st.lower_bound(i - k); //return first element equal or greater than i-k
            if (itr == st.end() || *itr > i + k)
            {
                s[i] = '1';
                st.insert(i);
                count++;
            }
        }
    }
    cout << count << endl;
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