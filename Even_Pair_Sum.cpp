// codechef dec long challenge 2020
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

ll solve(ll a,ll b){
    ll even1 = a/2;
    ll odd1 = a-even1;
    ll even2 = b/2;
    ll odd2 = b-even2;
    return (even1*even2 + odd1*odd2);
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        ll a,b;
        cin>>a>>b;
        cout<<solve(a,b)<<endl;
    }

    return 0;
}