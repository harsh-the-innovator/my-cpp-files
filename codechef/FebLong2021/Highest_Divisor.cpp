// codechef feb long challenge 2021 div3
#include <bits/stdc++.h>
using namespace std;

#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

int main()
{
    fastIO int n;
    cin >> n;
    int ans;
    for (int i = 10; i >= 1; i--)
    {
        if (n % i == 0)
        {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}
