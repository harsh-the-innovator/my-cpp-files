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
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

void solve(int n,int k,int x,int y){
    
    vector<pair<int,int>> vp(4);

    if(x==y){
        cout<<n<<" "<<n;
        return;
    }else if(x>y){
        vp[0] = {n,n+(y-x)};
        vp[1] = {n+(y-x),n};
        vp[2] = {0,x-y};
        vp[3] = {x-y,0}; 
    }else if(x<y){
        vp[0] = {n+(x-y),n};
        vp[1] = {n,n+(x-y)};
        vp[2] = {y-x,0};
        vp[3] = {0,y-x};
    }
    cout<<vp[(k-1)%4].first<<" "<<vp[(k-1)%4].second;
}


int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n,k,x,y;
        cin>>n>>k>>x>>y;
        solve(n,k,x,y);
        cout<<endl;
    }

    return 0;
}