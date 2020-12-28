#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a;
    int cnt = 0;
    for(a=0;a*a<=n;a++){
        int b = n-a*a;
        if(a+b*b==m){
            cnt++;
        }
    }
    cout<<cnt<<endl;
}