// codeforces round #662 div2 A
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl ("\n")
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

int main() {
    fast int t;
    cin>>t;
    while (t--) {
        ll n;
        cin>>n;
        if (n%2!=0) {
            cout<<(n+1)/2<<endl;
        }
        else {
            cout<<(n+2)/2<<endl;
        }
    }
}