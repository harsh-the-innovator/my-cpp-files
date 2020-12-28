#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define rep(i, n) for (int i = 0; i < n; i++)
int solve(vi &a,int n,int m){
    if(n==0){
        return 0;
    }

    int score = 0;
    
}
int main()
{
    int n, m;
    cin >> n >> m;
    vi a(m);
    rep(i,n) cin>>a[i];
    cout<<solve(a,n,m)<<endl;
}