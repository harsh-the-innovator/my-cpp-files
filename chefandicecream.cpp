#include <bits/stdc++.h>
using namespace std;

string solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int coinCount[3]{0};
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 5)
        {
            sum += 5;
            coinCount[0] += 1;
        }
        else if (arr[i] == 10)
        {
            if (sum >= 5 && coinCount[0] >= 1)
            {
                sum += 5;
                coinCount[0] -= 1;
                coinCount[1] += 1;
            }
            else
            {
                return "NO";
            }
        }
        else if (arr[i] == 15)
        {
            if (sum >= 10 && (coinCount[0] >= 2 || coinCount[1] >= 1))
            {
                sum += 5;
                coinCount[2] += 1;
                if (coinCount[1] >= 1)
                    coinCount[1] -= 1;
                else if (coinCount[0] >= 2)
                    coinCount[0] -= 2;
            }
            else
            {
                return "NO";
            }
        }
    }

    return "YES";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cout << solve() << endl;
    }
}