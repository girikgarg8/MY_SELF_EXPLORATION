#include <bits/stdc++.h>
#include <string.h>
#include <cstring>
/* Recursive Approach
int maxProfit(vector <int> &prices,int idx,bool own,int k){
    //Base case : when idx reaches end of array or I can make only 0 transactions
    if (idx==prices.size() || k==0){
        return 0;
    }

    //If own is false, no stock is bought
    if (own==false){
        return max(maxProfit(prices,idx+1,false,k),(maxProfit(prices,idx+1,true,k)-prices[idx]));
    }

    //If stock is bought
    else if (own==true){
        return max(maxProfit(prices,idx+1,false,k-1)+prices[idx],maxProfit(prices,idx+1,true,k));
    }
*/

/*
Top Down Approach
#include <cstring>
#include <string.h>
int dp[5001][2501][2];

int maxProfit(vector<int> &prices, int idx, int n, int buy, int k)
{

    // If 'k' transactions is completed.
    if (idx == n || k == 0)
    {
        return 0;
    }

    // If result is already computed.
    if (dp[idx][k][buy] != -1)
    {
        return dp[idx][k][buy];
    }

    // If stock is not bought.
    if (buy == 0)
    {
        return dp[idx][k][buy] = max(maxProfit(prices, idx + 1, n, 0, k), maxProfit(prices, idx + 1, n, 1, k) - prices[idx]);
    }

    // If stock is bought.
    else
    {
        return dp[idx][k][buy] = max(maxProfit(prices, idx + 1, n, 1, k), maxProfit(prices, idx + 1, n, 0, k - 1) + prices[idx]);
    }
}

int maximumProfit(vector<int> &prices, int n, int k)
{
    // Initialize 3-D array to store result of recursive calls.
    memset(dp,-1,sizeof(dp));

    // Recursive function to find profit.
    return maxProfit(prices, 0, n, 0, k);
}

// This code passes all test cases on CodeStudio

*/
