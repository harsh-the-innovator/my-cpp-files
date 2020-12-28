// codechef august long challenge 2020
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

void solve(int pc, int pr) {
    if (pc<=9 && pr>9) {
        cout<<"0 1"<<endl;
    }
    else if (pc>9 && pr<=9) {
        cout<<"1 1"<<endl;
    }
    else if (pc<=9 && pr<=9) {
        cout<<"1 1"<<endl;
    }
    else {
        int digits1 = pc/9;
        int digits2 = pr/9;
        if (pc%9!=0) digits1++;
        if (pr%9!=0) digits2++;

        if (digits1 < digits2) {
            cout<<"0 "<<digits1<<endl;
        }
        else {
            cout<<"1 "<<digits2<<endl;
        }
    }
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int pc, pr;
        cin>>pc>>pr;
        solve(pc, pr);
    }

    return 0;
}