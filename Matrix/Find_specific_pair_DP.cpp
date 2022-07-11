#include <bits/stdc++.h>
#define N 5
using namespace std;
int findMaxValue (int mat[][N]){
    int dp[N][N];
    int maxValue=INT_MIN;
    dp[0][0]=mat[0][0];
    for (int i=1;i<N;i++){
        dp[i][0]=min(dp[i-1][0],mat[i][0]);
    }
    for (int j=1;j<N;j++){
        dp[0][j]=min(dp[0][j-1],mat[0][j]);
    }
    for (int i=1;i<N;i++){
        for (int j=1;j<N;j++){
            dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],mat[i][j]));
            maxValue=max(maxValue,mat[i][j]-dp[i-1][j-1]);
        }
    }
    return maxValue;
}
int main()
{
int mat[N][N] = {
                { 1, 2, -1, -4, -20 },
                { -8, -3, 4, 2, 1 },
                { 3, 8, 6, 1, 3 },
                { -4, -1, 1, 7, -6 },
                { 0, -4, 10, -5, 1 }
            };
    cout << "Maximum Value is "
        << findMaxValue(mat);
 
    return 0;
}