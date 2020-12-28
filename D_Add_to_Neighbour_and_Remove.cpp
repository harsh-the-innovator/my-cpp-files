//codeforces #690 div 3
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long
#define vi vector<int>
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

int check(vi &a,int h){
    int cnt = 0; //total operations
    int sum = 0;
    int j = 0;//starting vertex
    rep(i,a.size()){
        sum+=a[i];
        if(sum==h){
            cnt+=(i-j);
            sum=0;
            j=i+1;
        }else if (sum>h)
        {
            return -1;
        }   
    }

    return cnt;
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        vi a(n);
        ll total = 0;
        rep(i,n){
            cin>>a[i];
            total+=a[i];
        }

        int ans = n-1; //max ans we can get
        for(int i=1;i*i<=total;i++){
            if(total%i==0){
                int f1 = i; //1st factor of total
                int f2 = total/i; //2nd factor of total
                int a1 = check(a,f1);
                int a2 = check(a,f2);
                if(a1!=-1) ans = min(ans,a1);
                if(a2!=-1) ans = min(ans,a2);
            }
        }
        cout<<ans<<endl;

    }

    return 0;
}