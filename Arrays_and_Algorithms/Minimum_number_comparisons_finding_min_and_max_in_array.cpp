#include <bits/stdc++.h> //Compare in pairs approach
using namespace std;
int main(){
    int arr[]={1000,11,445,1,330,3000};
    int n=sizeof(arr)/sizeof(int);
    int minElement=INT_MAX;
    int maxElement=INT_MIN;
    if (n%2==1){
        minElement=arr[0];
        maxElement=arr[0];
        for (int i=1;i<n;i+=2){
            minElement=min(minElement,min(arr[i],arr[i+1]));
            maxElement=max(maxElement,max(arr[i],arr[i+1]));
        }
    }
    if (n%2==0){
        minElement=min(arr[0],arr[1]);
        maxElement=max(arr[0],arr[1]);
        for (int i=2;i<n;i+=2){
            minElement=min(minElement,min(arr[i],arr[i+1]));
            maxElement=max(maxElement,max(arr[i],arr[i+1]));
        }
    }
    cout << "Minimum element is " << minElement <<endl;
    cout << "Maximum element is " << maxElement <<endl;
    return 0;
}
//Number of comparisons: for odd number of elements: 3*(n-1)/2
//Number of comparisons: for even number of elements: 1+3*(n-2)/2