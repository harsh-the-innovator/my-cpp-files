//codechef december long challenge 2020
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define pi (3.141592653589)
#define mod 1e9 + 7
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
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

void solve(vi &A,int n,int x){
    vvi v(n,vi(32,0));
    int j,p;
    rep(i,n){
        p = A[i];
        j = 0;
        while(p>0){
            v[i][j] = p%2;
            p/=2;
            j++;
        }
    }

    int flag;
    rep(i,n-1){
        rrep(j,32){
            if(x>0 && v[i][j]==1){
                flag = 0;
                loop(k,i+1,n-1){
                    if(v[k][j]==1){
                        flag = 1;
                        A[i] = A[i]^(1<<j);
                        A[k] = A[k]^(1<<j);
                        v[i][j]^=1;
                        v[k][j]^=1;
                        x--;
                        break;
                    }
                }
                if(flag==0){
                    A[i] = A[i]^(1<<j);
                    A[i+1] = A[i+1]^(1<<j);
                    v[i][j]^=1;
                    v[i+1][j]^=1;
                    x--;
                }
            }
        }
        if(x<=0) break;
    }

    if(x%2!=0){
        flag = 0;
        int i = 0;
        while(i<n-1 && A[i]==0){
            i++;
        }
        if(i==n-1){
            A[i-1]^=1;
            A[i]^=1;
        }else{
            int bitcount = (int)log2(A[i]) + 1;
            int j = i+1;
            while(j<=n-1){
                if(A[j]!=0){
                     break;
                }
                j++;
            }
            A[i]^=(1<<bitcount);
            A[j]^=(1<<bitcount);
        }
        x--;
    }

    for(auto i : A){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("./io/input.txt", "r", stdin);
	freopen("./io/output.txt", "w", stdout);
#endif
    fast int t;
    cin >> t;
    while (t--)
    {
        int n,x;
        cin>>n>>x;
        vi A(n);
        rep(i,n){
            cin>>A[i];
        }  
        solve(A,n,x); 
    }

    return 0;
}