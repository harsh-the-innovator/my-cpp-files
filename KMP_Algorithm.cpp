// pattern searching algorithm in string
// time complexity = O(n+m);
// n = length of string, m = length of pattern
#include<bits/stdc++.h>
using namespace std;

// creating lps array
void createLPS(string pattern, int m, int lps[]) {
    int i=1, j=0;
    lps[0] = 0;

    while (i<m) {
        if (pattern[i]==pattern[j]) {
            lps[i] = j+1;
            i++;
            j++;
        }
        else {
            if (j!=0) {
                j = lps[j-1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }

    }
}


void KMPpatternMatch(string s, string pattern, int n, int m) {
    // KMP pattern searching algo
    int lps[m];
    createLPS(pattern, m, lps);

    int i = 0, j=0;

    while (i<n) {
        if (s[i]==pattern[j]) {
            // j is at last
            if (j==m-1) {
                cout<<"Pattern found at index "<<(i-j)<<endl;
                return;
            }
            else {
                i++;
                j++;
            }
        }
        else {
            if (j!=0) {
                j = lps[j-1];
            }
            else {
                i++;
            }
        }
    }

    cout<<"Pattern not found\n";
}

int main() {
    string s = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    int n = s.length();
    int m = pattern.length();
    KMPpatternMatch(s, pattern, n, m);
}