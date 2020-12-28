//codechef december long challenge 2020
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
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

void print(int a[],int n){
    rep(i,n){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void solve(int n,int k){
    int a[n];
    rep(i,n){
        if(i%2==0){
            a[i] = i+1;
        }else{
            a[i] = -1*(i+1);
        }
    }

    int sum[n];
    sum[0] = a[0];
    int cnt = 1;
    loop(i,1,n-1){
        sum[i] = sum[i-1]+a[i];
        if(sum[i]>0) cnt++;
    }

    if(cnt>k){
        // make postive numbers to negative from back
        int x = cnt-k;
        rrep(i,n){
            if(a[i]>0 && x>0){
                a[i] = -a[i];
                x--;
            }else if(x<=0) break;
        }

    }else if(cnt<k){
         // make negative numbers to positive from back
        int x = k-cnt;
        rrep(i,n){
            if(a[i]<0 && x>0){
                a[i] = -a[i];
                x--;
            }else if(x<=0) break;
        }
    }
    print(a,n);

}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        solve(n,k);
        
    }

    return 0;
}