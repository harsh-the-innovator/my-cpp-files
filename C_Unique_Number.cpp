//codeforces #690 div 3 C
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

void solve(int x){
    if(x>=1 && x<=9){
        cout<<x<<endl;
    }else if(x>=10 && x<=17){
        cout<<(x-9)<<"9"<<endl;
    }else if (x>=18 && x<=24)
    {
       cout<<(x-17)<<"89"<<endl;
    }else if (x>=25 && x<=30)
    {
       cout<<(x-24)<<"789"<<endl;
    }
    else if (x>=31 && x<=35)
    {
       cout<<(x-30)<<"6789"<<endl;
    }
    else if (x>=36 && x<=39)
    {
       cout<<(x-35)<<"56789"<<endl;
    }
    else if (x>=40 && x<=42)
    {
       cout<<(x-39)<<"456789"<<endl;
    }else if (x>=43 && x<=44)
    {
       cout<<(x-42)<<"3456789"<<endl;
    }else if (x==45)
    {
        cout<<"123456789"<<endl;
    }
    else
    {
        cout<<"-1"<<endl;
    }
    
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin>>x;
        solve(x);
    }

    return 0;
}