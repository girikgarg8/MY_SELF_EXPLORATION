#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={4,2,1,2};
    int sum=0;
    int sumOfSquares=0;
    int n=sizeof(arr)/sizeof(int);
    int expectedSum=n*(n+1)/2;
    int expectedSumOfSqaures=(n*(n+1)*(2*n+1))/6;
    for (int i=0;i<n;i++){
        sum+=arr[i];
        sumOfSquares+=arr[i]*arr[i];
    }
    int u=sum-expectedSum;
    int v=sumOfSquares-expectedSumOfSqaures;
    int t=v/u;
    cout << "Repeating number is " << (t+u)/2 <<endl;
    cout << "Missing number is " << (t-u)/2 <<endl;
    return 0;
}