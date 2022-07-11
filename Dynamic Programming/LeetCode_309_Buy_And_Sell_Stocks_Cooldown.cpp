#include <bits/stdc++.h>
#include <string.h>
#include <cstring>
using namespace std;
int dp[50001][2];
int solve(vector <int> &prices,int i,bool own){
    if (i>=prices.size()){
        return 0;
    }
    if (dp[i][own]!=-1){
        return dp[i][own];
    }
    if (own==1){
        int op1=prices[i]+solve(prices,i+2,0);
        int op2=solve(prices,i+1,1);
        return dp[i][own]=max(op1,op2);
    }
    else if (own==0){
        int op1=-prices[i]+solve(prices,i+1,1);
        int op2=solve(prices,i+1,0);
        return dp[i][own]=max(op1,op2);
    }
}
int maxProfit(vector <int> &prices){
    return solve(prices,0,0);
}
int main(){
    int n;
    cin>>n;
    vector <int> arr;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    memset(dp,-1,sizeof(dp));
    cout << maxProfit(arr);
    return 0;
}