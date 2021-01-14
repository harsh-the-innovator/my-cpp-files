// codechef long challenge jan 2021
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

void solve(int a[],int n,int k,int d){
    if(n==1){
        if(a[0]<k) cout<<"0";
        else{
            int x = a[0]/k;
            if(x<=d) cout<<x;
            else cout<<d;
        }
    }else{
        int i=0;
        int prevSum = 0;
        int ans = 0;
        while(d>0 && i<n){
            int x = (a[i]+prevSum)/k;
            prevSum = (a[i]+prevSum)%k;
            if(x<=d){
                ans+=x;
            }else{
                ans+=d;
            }
            d-=x;
            i++;
        }

        cout<<ans;
    }
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n,k,d;
        cin>>n>>k>>d;
        int a[n];
        rep(i,n) cin>>a[i];
        solve(a,n,k,d);
        cout<<endl;
    }

    return 0;
}