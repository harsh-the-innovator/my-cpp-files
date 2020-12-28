#include <iostream>
#include <algorithm>
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
    friend bool compareVal(Item obj1, Item obj2);
    friend int knapsack(Item obj[], int W, int n);
};

bool compareVal(Item obj1, Item obj2)
{
    double r1 = (double)obj1.profit / obj1.weight;
    double r2 = (double)obj2.profit / obj2.weight;

    return r1 > r2;
}

int knapsack(Item obj[], int W, int n)
{
    int curWeight = 0;
    double finalProfit = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (curWeight + obj[i].weight <= W)
        {
            curWeight += obj[i].weight;
            finalProfit += obj[i].profit;
        }
        else
        {
            int remain = W - curWeight;
            finalProfit += obj[i].profit * (double)remain / obj[i].weight;
            break;
        }
    }

    return finalProfit;
}

int main()
{

    // double profits[4] = {280,100,120,120};
    // double weights[4] = {40,10,20,24};
    int W = 60, n = 4;
    Item obj[n];
    for (int i = 0; i < n; i++)
    {
        obj[i].getpairs();
    }
    sort(obj, obj + n, compareVal);

    // after sorted
    for (int i = 0; i < n; i++)
    {
        obj[i].putpairs();
    }

    double totalProfit = knapsack(obj, W, n);

    cout << "\nTotal profit = " << totalProfit;

    return 0;
}