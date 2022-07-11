#include <iostream>
using namespace std;
int Knapsack(int values[],int weights[],int w,int n){
    int **dp=new int *[n+1];
    for (int i=0;i<=n;i++){
        dp[i]=new int[w+1];
    }
    for (int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for (int i=0;i<=w;i++){
        dp[n][i]=0;
    }
    for (int i=n-1;i>=0;i--){
        for (int j=1;j<=w;j++){
            if (weights[i]>j){
                dp[i][j]=dp[i+1][j];
            }
            else{
            int a=dp[i+1][j];
            int b=dp[i+1][j-weights[i]]+values[i];
            dp[i][j]=max(a,b);
            }
            }
    }
    return dp[0][w];
}
int main(){
    int n,w;
    cout << "Enter the value of n" <<endl;
    cin >> n ;
    int *weights=new int[n];
    int *values=new int[n];
    for (int i=0;i<n;i++){
        cin>>weights[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }
    cout << "Enter maximum weight" <<endl;
    cin >> w ;
    cout << "Maximum value is " << Knapsack(values,weights,w,n) <<endl;
    return 0;
}