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


// you are required to complete this function 
// function should print the required range
#define ppi pair<int,pair<int,int>>


void solve(int arr[3][4], int n, int k)
{
    priority_queue<ppi,vector<ppi>,greater<ppi>> pq;
    
    int range = INT_MAX;
    int minEl = INT_MAX;
    int maxEl = INT_MIN;
    rep(i,k){
        maxEl = max(maxEl,arr[i][0]);
        pq.push({arr[i][0],{i,0}});
    }

    pair<int,int> ans = {-1,-1};
    

    while(1){
        ppi temp = pq.top();
        pq.pop();
        int row = temp.second.first;
        int col = temp.second.second;
        minEl = temp.first;
        if((maxEl - minEl) < range){
            range = maxEl - minEl;
            ans = {minEl,maxEl};
        }
        
        if(col<n-1){
            if(arr[row][col+1] > maxEl){
                maxEl = arr[row][col+1];
            }
            pq.push({arr[row][col+1],{row,col+1}});
        }else break;
    }
    
    cout<<ans.first<<" "<<ans.second<<endl;
    
      
}

int main(){
    fast int t;
    cin>>t;
    while(t--){
        
        int mat[3][4] ={{1,2, 3, 4},
                    {5 ,6 ,7 ,8},
                    {9 ,10, 11, 12}};
        solve(mat,4,3);
    }
}