#include <iostream>
#include <climits>
using namespace std;
int mask_when_visited_all = (1 << 4) - 1;
int dist[10][10] = {{0,10, 15, 20}, {10, 0, 35, 25}, {15,35,0,30}, {20,25,30,0}};
int dp[16][4];
int n = 4; //represents number of cities I am currently taking
int tsp(int mask, int pos)
{
    int ans = INT_MAX;
    //Base Case
    if (mask == mask_when_visited_all)
    {
        return dist[pos][0];
    }
    if (dp[mask][pos] != (-1))
    {
        return dp[mask][pos];
    }
    //Trying to visit an unvisited city
    for (int city = 0; city < n; city++)
    {
        if ((mask & (1 << city)) == 0)
        {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }
    dp[mask][pos] = ans;
    return ans;
}
int main()
{
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            dp[i][j] = (-1);
        }
    }
    cout << tsp(1, 0) << endl;
}