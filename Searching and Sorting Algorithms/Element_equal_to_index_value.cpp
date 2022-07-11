#include <bits/stdc++.h>
using namespace std;
int index(int arr[],int low,int high){
    while (low<=high){
        int mid=(low+high)/2;
        if (arr[mid]==mid){
            return mid;
        }
        if (arr[mid]>mid){
            high=mid-1;
        }
        else if (arr[mid]<mid){
            low=mid+1;
        }
    }
    return -1;
}
int main()
{
    int arr[10] = {-10, -1, 0, 3, 10, 11, 30, 50, 100};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Fixed Point is "<< index(arr, 0, n-1);
    return 0;
}