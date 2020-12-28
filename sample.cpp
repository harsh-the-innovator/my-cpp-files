#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q, t, k;
    string w;
    cin >> q;
    stack<string> st;
    string s = "";
    while (q--)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> w;
            st.push(s);
            s = s + w;
        }
        if (t == 2)
        {
            cin >> k;
            st.push(s);
            s.erase(s.size() - k);
        }
        if (t == 3)
        {
            cin >> k;
            cout << s[k - 1] << endl;
        }
        if (t == 4)
        {
            s = st.top();
            st.pop();
        }
    }
    return 0;
}
