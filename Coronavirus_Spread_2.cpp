// codechef september long challenge 2020
#include <bits/stdc++.h>
using namespace std;
#define I INT_MAX
#define endl ("\n")
#define pb push_back
#define all(c) c.begin(), c.end()
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

void solve(int speed[], int n)
{
    int minAns = I;
    int maxAns = -1;
    double position[n + 1];
    loop(i, 1, n)
    {
        position[i] = (double)i;
    }

    set<double> time;
    double distance;
    loop(i, 1, n - 1)
    {
        loop(j, i + 1, n)
        {
            if (speed[i] > speed[j])
            {
                distance = position[j] - position[i];
                time.insert((double)distance / (double)(speed[i] - speed[j]));
            }
        }
    }

    bool infected[n + 1]{0};
    int count = 0;
    vector<int> ans;
    loop(i, 1, n)
    {
        memset(infected, 0, sizeof(infected));
        infected[i] = 1;
        for (auto t : time)
        {
            map<string, vector<int>> m;
            loop(j, 1, n)
            {
                double distance = (position[j] + (double)speed[j] * t);
                m[to_string(distance)].pb(j);
            }

            for (auto itr : m)
            {
                int flag = 0;
                for (auto x : itr.second)
                {
                    if (infected[x] == 1)
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 1)
                {
                    for (auto x : itr.second)
                    {

                        infected[x] = 1;
                    }
                }
            }
        }

        count = 0;
        loop(x, 1, n)
        {
            if (infected[x] == 1)
            {
                count++;
            }
        }

        minAns = min(minAns, count);
        maxAns = max(maxAns, count);
    }

    cout << minAns << " " << maxAns << endl;
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int speed[n + 1];
        loop(i, 1, n) cin >> speed[i];
        solve(speed, n);
    }

    return 0;
}