#include <bits/stdc++.h>
#include <string.h>
#include <cstring>
using namespace std;
int dp[50001][2];
int solve(vector <int> &prices,int i,int fee,bool own){
    if (i==prices.size()){
        return 0;
    }
    if (dp[i][own]!=-1){
        return dp[i][own];
    }
    if (own==1){
        int op1=prices[i]+solve(prices,i+1,fee,0);
        int op2=solve(prices,i+1,fee,1);
        return dp[i][own]=max(op1,op2);
    }
    else if (own==0){
        int op1=-(fee+prices[i])+solve(prices,i+1,fee,1);
        int op2=solve(prices,i+1,fee,0);
        return dp[i][own]=max(op1,op2);
    }
}
int maxProfit(vector <int> &prices,int fee){
    return solve(prices,0,fee,0);
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
    int fee;
    cout << "Enter the fees\n";
    cin>>fee;
    memset(dp,-1,sizeof(dp));
    cout << maxProfit(arr,fee);
    return 0;
}