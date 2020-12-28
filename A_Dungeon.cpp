//codeforces educational round 100
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int k = (a+b+c)/9;
        if((a+b+c)%9==0 && a>=k && b>=k && c>=k) cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }
    
}