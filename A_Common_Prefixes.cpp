// codeforces #659 div2 A
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define fast ios_base::sync_with_stdio(0), cin.tie(0);

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n + 1];
        int count[n + 2]{0};
        string ans[n + 2];

        loop(i, 1, n)
        {
            cin >> arr[i];
        }
        int len;
        string str = "";
        loop(i, 1, n)
        {
            len = arr[i];
            str = "";
            if (count[i] < len)
            {
                count[i + 1] = count[i] = len;
                loop(j, 1, len)
                {
                    str = str + "a";
                }
                ans[i + 1] = str;
            }
            else if (count[i] == len)
            {
                if (len == 0)
                {
                    ans[i] = "a";
                    ans[i + 1] = "b";

                    count[i + 1] = count[i] = 1;
                }
                else
                {
                    ans[i + 1] = ans[i];
                    count[i + 1] = count[i];
                }
            }
            else
            {
                if (len == 0)
                {
                    if (ans[i][0] == 'a')
                    {
                        ans[i + 1] = "b";
                    }
                    else if (ans[i][0] == 'b')
                    {
                        ans[i + 1] = "a";
                    }
                    count[i + 1] = 1;
                }
                else
                {
                    loop(j, 1, len)
                    {
                        str = str + "a";
                    }
                    ans[i + 1] = str;
                    count[i + 1] = len;
                }
            }
        }

        // printing vector
        loop(i, 1, n + 1)
        {
            cout << ans[i] << endl;
        }
    }
    return 0;
}