#include <iostream>
using namespace std;
int CoinTower(int coin[],int n,int x,int y){
    int *dp=new int[n+1];
    dp[0]=false;
    dp[1]=true;
    for (int i=2;i<=n;i++){
        if (dp[i-1]==false){
            dp[i]=true;
        }
        else if ((i-x)>=0 && dp[i-x]==false){
            dp[i]=true;
        }
        else if ((i-y)<=0 && dp[i-y]==false){
            dp[i]=true;
        }
        else dp[i]=false;
    }
    if (dp[n]==true){
        cout << "PLayer who started the game wins" <<endl;
    }
    else{
        cout << "Other player wins the game" <<endl;
    }
}