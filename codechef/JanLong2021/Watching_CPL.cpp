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

const ll MAX = 1e9;
const ll N = 4001;
int dp[N][N];
int height[N], suffix[N];

void solve(){
    int n, k;
    cin>>n>>k;
    for(int i = 0; i < n; i++)
        cin>>height[i];
    sort(height, height + n);
    suffix[n] = 0;
    for(int i = n-1; i >= 0; i--)
        suffix[i] = suffix[i+1] + height[i];
    for(int i = 0; i <= n ; i++)
        for(int j = 0; j <= k; j++)
            dp[i][j] = MAX;

    dp[n][0] = 0;
    for(int i = n-1; i >= 0; i--){
        for(int j = k; j >= 0; j--){
            if(j <= height[i]){
                dp[i][j] = height[i];
                continue;
            }
            if(dp[i+1][j-height[i]] == MAX)
                dp[i][j] = MAX;
            else
                dp[i][j] = min(dp[i+1][j], dp[i+1][j-height[i]] + height[i]);
        }
    }
    for(int i = n-1; i >= 0; i--)
        if(suffix[i] - dp[i][k] >= k){
            cout<<n-i<<"\n";
            return ;
        }
    cout<<-1<<"\n";
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}