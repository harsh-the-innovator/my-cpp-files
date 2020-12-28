// question 5.1
// insert n into m such that m starts at bit j and end at bit i 
// n and m are binaty strings
#include<bits/stdc++.h>
using namespace std;
int main() {
    string n, m;
    cin>>n>>m;
    int j, i;
    cin>>i>>j;
    // first clear the bit from j to i
    for (int bit = j;bit>=i;bit--) {
        int mask = ~(1<<bit);
        cout<<(stoi(n)&mask)<<endl;
    }
}