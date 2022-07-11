#include <iostream>
using namespace std;
int Max_Square_of_Size_zero(int **arr,int n,int m){
    int **dp=new int *[n];
    for (int i=0;i<m;i++){
        dp[i]=new int[m];
    }
    int ans=0;
    for (int i=0;i<n;i++){
        if (arr[i][0]==1){
            dp[i][0]=0;
        }
        else {
            dp[i][0]=1;
            ans=max(ans,dp[i][0]);
        }
    }
    for (int i=0;i<m;i++){
        if (arr[0][i]==1){
            dp[0][i]=0;
        }
        else {dp[0][i]=1;
            ans=max(ans,dp[0][i]);
        }
    }
    for (int i=1;i<n;i++){
        for (int j=1;j<m;j++){
            if (arr[i][j]==1){
                dp[i][j]=0;
            }
            else{
            int a=dp[i-1][j-1];
            int b=dp[i-1][j];
            int c=dp[i][j-1];
            dp[i][j]=1+min(a,min(b,c));
            ans=max(ans,dp[i][j]);
            }
        }
    }
    return ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    int **arr=new int *[n];
    for (int i=0;i<m;i++){
        arr[i]= new int[m];
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cout << Max_Square_of_Size_zero(arr,n,m) <<endl;
    return 0;    
}
