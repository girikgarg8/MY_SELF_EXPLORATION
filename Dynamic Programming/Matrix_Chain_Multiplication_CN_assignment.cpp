#include <iostream>
#include <climits>
using namespace std;
int MCMCost(int arr[],int s,int e,int **dp){
    if (dp[s][e]!=-1){
        return dp[s][e];
    }
    if (s-e==0 || e-s==1){ //s-e==0 means isngle number and s-e==1 means single matrix
        return 0;
    } //we could also have used the base condition that s>=e
    int cost=INT_MAX;
    for (int k=s+1;k<=e-1;k++){
        int temp=MCMCost(arr,s,k,dp)+MCMCost(arr,k,e,dp)+arr[s]*arr[k]*arr[e];
        cost=min(cost,temp);
    }
    dp[s][e]=cost;
    return cost;
}
int main(){
    int n;
    cin>>n;
    int *arr=new int[n+1];
    for (int i=0;i<=n;i++){
        cin>>arr[i];
    }
    int **dp=new int *[n+1];
    for (int i=0;i<=n;i++){
        dp[i]=new int[n+1];
    }
    for (int i=0;i<=n;i++){
        for (int j=0;j<=n;j++){
            dp[i][j]=-1;
        }
    }
    cout << MCMCost(arr,0,n,dp);
    return 0;
}

