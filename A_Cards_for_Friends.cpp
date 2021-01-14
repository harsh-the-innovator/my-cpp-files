// codeforces #693 div 3
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

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int w,h,n;
        cin>>w>>h>>n;
        if(w%2!=0 && h%2!=0){
            if(n==1) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }else if(w%2==0 || h%2==0){
            int i=0;
            int x = 1,y=1;
            while(w%2==0){
                w=w/2;
                i++;
                x=x*2;
            }
            i=0;
            while(h%2==0){
                h=h/2;
                i++;
                y=y*2;
            }

            if(n>x*y) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }

    return 0;
}
