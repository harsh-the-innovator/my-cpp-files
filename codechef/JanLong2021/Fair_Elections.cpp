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

void solve(int A[],int B[],int n,int m){
    ll aSum = 0,bSum = 0;
    rep(i,n){
        aSum+=A[i];
    }
    rep(i,m){
        bSum+=B[i];
    }

    sort(A,A+n);
    sort(B,B+m,greater<int>());

    if(aSum>bSum) cout<<"0";
    else{
        int count = 0;
        ll diff = bSum-aSum;
        int i=0,j=0;
        while(i<n && j<m && diff>=0){
            if(A[i]<B[j]){
                diff = diff - 2*(B[j] - A[i]);
                i++;
                j++;
                count++;
            }else break;
        }

        if(diff>=0) cout<<"-1";
        else cout<<count;
    }

}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        int A[n],B[m];
        rep(i,n) cin>>A[i];
        rep(i,m) cin>>B[i];
        solve(A,B,n,m);
        cout<<endl;
    }

    return 0;
}