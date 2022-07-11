// #include <iostream>
// using namespace std;
// int WaysForCoinChange(int values[],int n,int V){
//     if (V==0){ //Base case
//         return 1;
//     }
//     if (V<0){ //Base case
//         return 0;
//     }
//     if (n==0){ //Edge case
//         return 0;
//     }
//     int ans=0;
//     for (int j=0;j<n;j++){
//     ans+=WaysForCoinChange(values,n,V-values[j]);
//     }
//     return ans;
// }
// int main(){
//     int values[]={1,2,5};
//     int V=13;
//     int n=sizeof(values)/sizeof(int);
//     cout << WaysForCoinChange(values,n,V) <<endl;
//     return 0;
// }
//This code will give 634 as the answer, which will include the permutations as well
//So I need to pass the startCoin also as an argument to the function so that permutations are not generated

//Code using simple recursion

// #include <iostream>
// using namespace std;
// int WaysForCoinChange(int values[],int n,int V,int startCoin){
//     if (V==0){ //Base case if required sum is 0, then there is one way i.e. don't take any coin
//         return 1;
//     }
//     if (V<0){ //Base case if required sum is less than 0, then there is no way
//         return 0;
//     }
//     if (n==0){ //Edge case
//         return 0;
//     }
//     int ans=0;
//     for (int j=startCoin;j<n;j++){
//     ans+=WaysForCoinChange(values,n,V-values[j],j);
//     }
//     return ans;
// }
// int main(){
//     int values[]={1,2,5};
//     int V=13;
//     int n=sizeof(values)/sizeof(int);
//     cout << WaysForCoinChange(values,n,V,0) <<endl;
//     return 0;
// } //This will give the correct answer i.e. 14 which is the answer without permutation

//Using memoization
#include <iostream>
using namespace std;
int WaysForCoinChange(int values[], int n, int V, int startCoin, int dp[][3])
{
    if (V == 0)
    { //Base case
        return 1;
    }
    if (V < 0)
    { //Base case
        return 0;
    }
    if (n == 0)
    { //Edge case
        return 0;
    }
    if (dp[V][startCoin] != -1)
    {
        return dp[V][startCoin];
    }
    int ans = 0;
    for (int j = startCoin; j < n; j++)
    {
        ans += WaysForCoinChange(values, n, V - values[j], j, dp);
    }
    return dp[V][startCoin] = ans;
}
int main()
{
    int values[] = {1, 2, 5};
    int V = 13;
    int n = sizeof(values) / sizeof(int);
    int dp[V + 1][3];
    for (int i = 0; i <= V; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            dp[i][j] = (-1);
        }
    }
    cout << WaysForCoinChange(values, n, V, 0, dp) << endl;
    return 0;
}

//Bottom Up solution
#include <iostream>
using namespace std;
int CoinChange(int coins[],int n,int x){
    int **ways=new int *[n];
    for (int i=0;i<n;i++){
        ways[i]=new int[x+1];
        ways[i][0]=1;
    }
    for (int i=n-1;i>=0;i--){
        for (int j=1;j<=x;j++){
            int count1=0;
            if (j-coins[i]>=0){
            count1=ways[i][j-coins[i]];
            } //including the ith coin
            int count2=0;
            if ((i+1)<=n-1){
            count2=ways[i+1][j]; //by excluding the ith coin
        }
        ways[i][j]=count1+count2;
    }
}
return ways[0][x];
}
int main(){
    int n,x;
    cin>>n>>x;
    int *coins=new int[n];
    for (int i=0;i<n;i++){
        cin>>coins[i];
    }
    cout << CoinChange(coins,n,x) <<endl;
    return 0;
}