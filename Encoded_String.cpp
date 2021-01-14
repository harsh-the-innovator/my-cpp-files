//codechef long challenge jan 2021
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define pi (3.141592653589)
#define mod 1e9 + 7
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define pb push_back
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

map<int,char> mp; 

void createMap(){
    int i;
    char c;
    for(i=0,c='a';i<=15,c<='p';i++,c++){
        mp[i] = c;
    }
}

void solve(string s,int n){
    string ans = "";
    for(int i=0;i<n;i+=4){
        int x = stoi(s.substr(i,4),0,2);
        ans+=mp[x];
    }

    cout<<ans;

}

int main()
{
    fast int t;
    cin >> t;
    createMap();
    while (t--)
    {
        int n;
        string s;
        cin>>n>>s;
        solve(s,n);
        cout<<endl;
    }

    return 0;
}