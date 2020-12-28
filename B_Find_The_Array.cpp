//codeforces educational round 100
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

void solve(vi &a,int n){
    ll odd = 0,even = 0;
    rep(i,n){
        if(i%2==0) even+=a[i];
        else odd+=a[i];
    }

    if(even<=odd){
        for(int i=0;i<n;i+=2){
            a[i] = 1;
        }
    }else{
        for(int i=1;i<n;i+=2){
            a[i] = 1;
        }
    }

    for(auto i : a){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        vi a(n);
        rep(i,n) cin>>a[i];
        solve(a,n);
    }

    return 0;
}