//codechef dec long challenge 2020
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

void solve(int arr[],int n,int d){
    int nonrisk = 0,risk = 0;
    rep(i,n){
        if(arr[i]>=80 || arr[i]<=9){
            risk++;
        }else{
            nonrisk++;
        }
    };
    cout<<ceil((float)nonrisk/d) + ceil((float)risk/d)<<endl;
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n,d;
        cin>>n>>d;
        int arr[n];
        rep(i,n) cin>>arr[i];
        solve(arr,n,d);
    }

    return 0;
}