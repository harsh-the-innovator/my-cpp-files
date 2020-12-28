// codechef august long challenge 2020
#include<bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);
int main() {
    fast
        int t;
    cin>>t;
    while (t--) {
        int h, p;
        cin>>h>>p;
        while (h>0 && p>0) {
            h = h-p;
            p = floor(p/2.0);
        }

        if (h<=0 && p>0) {
            cout<<"1\n";
        }
        else if (h>0 && p<=0) {
            cout<<"0\n";
        }
        else {
            cout<<"1\n";
        }
    }
}