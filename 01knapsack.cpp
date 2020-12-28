#include <iostream>
using namespace std;

class Item
{
private:
    int profit, weight;

public:
    void getpairs()
    {
        cin >> profit;
        cin >> weight;
    }
    void putpairs()
    {
        cout << "{" << profit << "," << weight << "}" << endl;
    }
    friend int knapsack(Item obj[], int W, int n);
};

int knapsack(Item obj[], int W, int n)
{

    int i, w;
    int dp[n + 1][W + 1];

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if (obj[i - 1].weight <= W)
            {
                dp[i][w] = max(obj[i - 1].profit + dp[i - 1][w - obj[i - 1].weight], dp[i - 1][w]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main()
{
    //  int val[] = { 60, 100, 120 };
    // int wt[] = { 10, 20, 30 };
    // ans = 220
    int W = 50, n = 3;
    Item obj[3];
    for (int i = 0; i < n; i++)
    {
        obj[i].getpairs();
    }

    int totalProfit = knapsack(obj, W, n);

    cout << "Total Profit = " << totalProfit << endl;
}