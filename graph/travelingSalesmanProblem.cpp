// Given a set of cities and distances between every pair of cities, the problem is to
// find the shortest possible route that visits every city exactly once and returns to the starting point.
// see coding blocks video for reference
#include <bits/stdc++.h>
using namespace std;
#define V 4

int dp[1 << V][V]; //dp table for storing values of size 2^V,V since mask can take values upto 2^V
// and city can take values upto V

int VISITED_ALL = (1 << V) - 1; //means all ones

int tsp(int dist[][V], int mask, int curCity)
{
    if (mask == VISITED_ALL)
    {
        //return distance from current city to starting city
        return dist[curCity][0];
    }

    if (dp[mask][curCity] != -1)
        return dp[mask][curCity];

    int ans = INT_MAX;

    //  now we will try to go to every unvisited city from this city
    for (int city = 0; city < V; city++)
    {

        //checking the ith bit in mask if it is 0 then current city is not visited
        if ((mask & (1 << city)) == 0)
        {
            //update mask - make new city as visitede
            int sub_result = dist[curCity][city] + tsp(dist, mask | (1 << city), city);
            ans = min(ans, sub_result);
        }
    }

    return dp[mask][curCity] = ans;
}

int main()
{
    // matrix representation of graph
    int graph[][V] = {{0, 10, 15, 20},
                      {10, 0, 35, 25},
                      {15, 35, 0, 30},
                      {20, 25, 30, 0}};

    for (int i = 0; i < (1 << V); i++)
    {
        for (int j = 0; j < V; j++)
        {
            dp[i][j] = -1;
        }
    }

    //starting from city 0 ans marking it visited so mask is 1
    cout << tsp(graph, 1, 0);
}