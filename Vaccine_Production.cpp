// codechef december long challenge 2020
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

int solve(int d1,int d2,int v1,int v2,int p){
    int ans = 0;
    ans+=min(d1,d2)-1;
    if(d1==d2){
        ans+=ceil((float)p/(v1+v2));
    }else{
        int x = abs(d1-d2);
        if(d1<d2){
            if(v1*x>=p){
                ans+=(int)ceil((float)p/v1);
            }else{
                ans+=(int)ceil((float)(p-v1*x)/(v1+v2)) + x;
            }
        }else{
            if(v2*x>=p){
                ans+=(int)ceil((float)p/v2);
            }else{
                ans+=(int)ceil((float)(p-v2*x)/(v1+v2)) + x;
            }
        }
    }

    return ans;
}

int main()
{
    fast int d1,v1,d2,v2,p;
    cin>>d1>>v1>>d2>>v2>>p;
    cout<<solve(d1,d2,v1,v2,p)<<endl;

    return 0;
}