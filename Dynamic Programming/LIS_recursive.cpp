#include <iostream>
#include <climits>
using namespace std;
int LIS(int arr[],int n,int i,int prev){
    if (i==n){
        return 0;
    }
    int exclude=LIS(arr,n,i+1,prev);
    int include=1;
    if (arr[i]>prev){
    include=1+LIS(arr,n,i+1,arr[i]);
    }
    return max(include,exclude);
}
int main(){
    int arr[] = { 3, 2, 6, 4, 5, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Length of the longest increasing subsequence is " 
	<< LIS(arr,n,0, INT_MIN);

	return 0;
}
