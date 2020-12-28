//codeforces global round 12
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

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        vector<pair<int,int>> vp(n);

        for(auto &i : vp){
            cin>>i.first>>i.second;
        }
       
        int ans = -1;
        
        rep(i,n){
            int mx = 0;
            rep(j,n){
                if(i!=j){
                    int temp = abs(vp[i].first - vp[j].first) + abs(vp[i].second - vp[j].second);
                    mx = max(mx,temp);
                }
            }
            if(mx<=k) ans = 1;
        }
        cout<<ans<<endl;
    }

    return 0;
}