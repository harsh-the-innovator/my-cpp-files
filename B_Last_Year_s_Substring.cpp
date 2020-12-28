//codeforces #690 div 3 B
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define pi (3.141592653589)
#define mod 1e9 + 7
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

string solve(string s,int n){
    if(s=="2020"){
        return "YES";
    }else if(s.substr(0,4)=="2020"){
        return "YES";
    }else if (s.substr(n-4,4)=="2020")
    {
        return "YES";
    }else if (s[0]=='2' && s.substr(n-3,3)=="020")
    {
         return "YES";
    }else if (s.substr(0,2)=="20" && s.substr(n-2,2)=="20")
    {
         return "YES";
    }else if (s.substr(0,3)=="202" && s[n-1]=='0')
    {
         return "YES";
    }

    return "NO";
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        cout<<solve(s,n);
        cout<<endl;
    }

    return 0;
}