#include <iostream>
#include <climits>
using namespace std;
int MinJumps(int *arr, int n, int i,int *dp)
{
    if (i >= (n))
    {
        return 0;
    }
    if (dp[i]!=-2){
        return dp[i];
    }
    int answer = INT_MAX;
    //suppose arr[i]=3,and i=2 then I need to make recursive calls on 1 step, 2 and 3 steps. For this,I will use a for loop
    int x = arr[i];
    for (int z = 1; z <= x; z++)
    {
        answer = min(answer, 1 + MinJumps(arr, n, i + z,dp));
    }
    if (answer != INT_MAX)
    {
        dp[i]=answer;
        return answer;
    }
    return -1;
}
int main()
{
    int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n=sizeof(arr)/sizeof(int);
    int *dp=new int[n];
    for (int x=0;x<n;x++){
        dp[x]=-2;
    }
    cout << "Minimum number of steps are " << MinJumps(arr, 11, 0,dp);
    return 0;
}