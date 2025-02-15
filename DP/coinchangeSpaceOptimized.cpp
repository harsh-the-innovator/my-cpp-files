// find minimum no. of coins to make a given sum
// A Dynamic Programming based C++ program to find minimum of coins
// to make a given change sum
#include <bits/stdc++.h>
using namespace std;

// m is size of coins array (number of different coins)
int minCoins(int coins[], int n, int sum)
{
    // table[i] will be storing the minimum number of coins
    // required for i value.  So table[sum] will have result
    int table[sum + 1];

    // Base case (If given value sum is 0)
    table[0] = 0;

    // Initialize all table values as Infinite
    for (int i = 1; i <= sum; i++)
        table[i] = INT_MAX;

    // Compute minimum coins required for all
    // values from 1 to sum
    for (int i = 1; i <= sum; i++)
    {
        // Go through all coins smaller than i
        for (int j = 0; j < n; j++)
            if (coins[j] <= i)
            {
                int sub_res = table[i - coins[j]];
                if (sub_res != INT_MAX && sub_res + 1 < table[i])
                    table[i] = sub_res + 1;
            }
    }
    if (table[sum] == INT_MAX)
        return -1;
    else
        return table[sum];
}

// Driver program to test above function
int main()
{
    int coins[] = {9, 6, 5, 3};
    int n = sizeof(coins) / sizeof(coins[0]);
    int sum = 2;
    cout << "Minimum coins required is "
         << minCoins(coins, n, sum);
    return 0;
}