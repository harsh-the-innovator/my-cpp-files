// codechef july 2020 long challenge div 2
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(a, b) for (int i = a; i <= b; i++)

ll digitSum(ll n)
{
    ll sum = 0;
    while (n != 0)
    {
        sum += n % 10;
        n = n / 10;
    }
    return sum;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll x, y;
        ll CP = 0, MP = 0;
        ll sum1;
        ll sum2;
        rep(1, n)
        {
            cin >> x >> y;
            if (x == y)
            {
                sum1 = sum2 = digitSum(x);
            }
            else
            {
                sum1 = digitSum(x);
                sum2 = digitSum(y);
            }

            if (sum1 > sum2)
            {
                CP++;
            }
            else if (sum1 == sum2)
            {
                CP++;
                MP++;
            }
            else
            {
                MP++;
            }
        }

        if (CP > MP)
        {
            // CASE CP WINS
            cout << "0 " << CP;
        }
        else if (CP == MP)
        {
            cout << "2 " << CP;
        }
        else
        {
            cout << "1 " << MP;
        }
        cout << endl;
    }
}