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

#define ppi pair<int,pair<int,int>>


void solve(int arr[4][4],int n,int k){
    priority_queue<ppi,vector<ppi>,greater<ppi>> pq;
    
    rep(i,n){
        //storing valu row and col in min heap
        pq.push({arr[i][0],{i,0}});
    }
    
    ppi temp;
    rep(i,k){
        temp = pq.top();
        pq.pop();
        int row = temp.second.first;
        int col = temp.second.second;

        int nextVal = (col < n-1) ? arr[row][col+1] : INT_MAX;
        pq.push({nextVal,{row,col+1}});
    }

    cout<<temp.first<<endl;
}

int main(){
    fast int t;
    cin>>t;
    while(t--){
        
        int mat[4][4] = { {10, 20, 30, 40}, 
                    {15, 25, 35, 45}, 
                    {25, 29, 37, 48}, 
                    {32, 33, 39, 50}, 
                }; 
        solve(mat,4,7);
    }
}