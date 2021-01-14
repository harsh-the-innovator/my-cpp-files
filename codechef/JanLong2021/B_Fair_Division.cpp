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
        int n;
        cin>>n;
        int a[n];
        rep(i,n) cin>>a[i];
        if(n==1) cout<<"NO";
        else{
            map<int,int> mp;
            rep(i,n){
                mp[a[i]]++;
            }
            if(mp[1]%2==0 && mp[2]%2==0) cout<<"YES";
            else{
                sort(a,a+n);
                int i=0,j=n-1;
                int left = 0,right  = 0;
                while(i<j){
                    if(left+a[i]<right+a[j]){
                        left+=a[i++];
                    }else if(left+a[i]>right+a[j]){
                        right+=a[j--];
                    }else{
                        left+=a[i++];
                        right+=a[j--];
                    }
                }

                if(i==j) cout<<"NO";
                else if(j>i && left==right) cout<<"YES";
                else cout<<"NO";

            }
        }
        cout<<endl;
    }

    return 0;
}