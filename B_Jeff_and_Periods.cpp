// codeforces #204 div2 B
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define vi vector<int>
#define vp vector<pair<int,int>>
#define pb push_back
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

const int MAX = 1000*100 + 5;

int main()
{
    fast int n, x;
    cin>>n;
    vi a[MAX];
    vp ans;
    rep(i, n) {
        cin>>x;
        a[x].pb(i);
    }

    rep(i, MAX) {
        if (a[i].size()==1) {
            ans.pb({ i, 0 });
        }
        else if (a[i].size()>1) {
            sort(all(a[i]));
            bool flag = true;
            int y = a[i][1] - a[i][0];
            rep(j, a[i].size()-1) {
                flag &= (a[i][j+1] - a[i][j])==y;
            }

            if (flag) {
                ans.pb({ i, y });
            }
        }
    }

    cout<<ans.size()<<endl;
    rep(i, ans.size()) {
        cout<<ans[i].ff<<" "<<ans[i].ss<<endl;
    }


    return 0;
}