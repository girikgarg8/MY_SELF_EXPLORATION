#include <iostream>
using namespace std;
int LIS(int arr[],int n){
    int *dp=new int[n];
    dp[0]=1; //every element is increasing sequence in itself
    for (int i=1;i<n;i++){
        dp[i]=1; //this is the min case
        for (int j=i-1;j>=0;j--){
            if (arr[j]<arr[i]){
                int possibleAns=dp[j]+1;
                if (possibleAns>dp[i]){
                    dp[i]=possibleAns;
                }
            }
        }
    }
    int max_in_dp_array=0;
    for (int i=0;i<n;i++){
        max_in_dp_array=max(max_in_dp_array,dp[i]);
    }
    //This approach takes O(n^2) time
    return max_in_dp_array;
}
int main(){
    int arr[]={1,5,2,3,4,9,6,10};
    int n=sizeof(arr)/sizeof(int);
    cout << LIS(arr,n) <<endl;
    return 0;
}