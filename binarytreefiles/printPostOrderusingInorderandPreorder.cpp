#include <bits/stdc++.h>
using namespace std;
int preIndex = 0;

void printPost(int in[],int pre[],int start,int end,map<int,int> mp){
    if(start>end) return;
    
    int inIndex = mp[pre[preIndex++]];
    
    printPost(in,pre,start,inIndex-1,mp);
    printPost(in,pre,inIndex+1,end,mp);
    
    cout<<in[inIndex]<<" ";
}

void printPostOrder(int in[], int pre[], int n)
{
    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[in[i]] = i;
    }
    printPost(in,pre,0,n-1,mp);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int pre[n],in[n];
        for(int i=0;i<n;i++) cin>>in[i];
        for(int i=0;i<n;i++) cin>>pre[i];
        printPostOrder(in,pre,n);
        cout<<endl;
    }
}