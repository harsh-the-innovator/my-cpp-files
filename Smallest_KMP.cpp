// codechef august long challenge 2020
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define pb push_back
#define all(c) c.begin(), c.end()
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);


string solve(string s, string p) {
    sort(all(s));
    rep(i, p.length()) {
        auto pos = s.find(p[i]);
        s.erase(s.begin()+pos);
    }

    string ans = "";
    string str1="", str2="", str3="";
    int i = 0;
    while (i<s.length()) {
        if (s[i]<p[0]) {
            str1.push_back(s[i]);
        }
        else if (s[i]==p[0]) {
            str2.push_back(s[i]);
        }
        else {
            str3.push_back(s[i]);
        }
        i++;
    }
    ans = ans+str1;
    if (str2.length()>0) {
        if ((str2+p)<=(p+str2)) {
            ans = ans+str2+p;
        }
        else {
            ans = ans+p+str2;
        }
    }
    else {
        ans = ans+p;
    }

    ans=ans+str3;
    return ans;
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        string s, p;
        cin>>s>>p;
        cout<<solve(s, p)<<endl;
    }

    return 0;
}