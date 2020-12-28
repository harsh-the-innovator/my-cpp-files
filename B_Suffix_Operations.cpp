// codeforces round #688 div 2
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

void solve(vl &v,int n){
   ll sum = 0;
   loop(i,1,n-1){
       sum+=abs((v[i]-v[i-1]));
   }

   ll res = min(sum - abs(v[0]-v[1]),sum-abs(v[n-2]-v[n-1]));

   loop(i,1,n-2){
       res = min(res,sum-(abs(v[i]-v[i-1])+abs(v[i+1]-v[i])-abs(v[i-1]-v[i+1])));
   }
    cout<<res<<endl;
    
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        vl v(n);
        rep(i,n) cin>>v[i];
        solve(v,n);   
    }

    return 0;
}