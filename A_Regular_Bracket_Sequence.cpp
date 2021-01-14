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
        string s;
        cin>>s;
        if(s.length()%2!=0) cout<<"NO";
        else{
            stack<char> st;
            bool flag = 1;
            rep(i,s.length()){
                if(s[i]=='(' || s[i]=='?'){
                    st.push(s[i]);
                }else if(s[i]==')'){
                    if(st.empty()){
                        flag = 0;
                        break;
                    }else if(st.top()=='('){
                        st.pop();
                    }
                }
            }
            if(!st.empty()) cout<<"NO";
            else if(flag==0) cout<<"NO";
            else cout<<"YES";
        }
        cout<<endl;
    }

    return 0;
}