#include <bits/stdc++.h>
using namespace std;
int searchInSortedRotatedArray(int arr[],int low,int high,int key){
    while (low<high){
        int mid=low+(high-low)/2;
        if (arr[mid]==key){
            return mid;
        }
        if (arr[low]<=arr[mid]){ //It means that the mid lies on the left line
            if (arr[low]<=key && arr[mid]>=key){ //Call binary search on the sorted part
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{//It means that mid lies on the right line
            if (arr[mid]<=key && key<=arr[high]) //Call binary search on the sorted part
            low=mid+1;
        else{
            high=mid-1;
        }
    }
}
return -1;
}
int main(){
    int arr[]={6,7,1,2,3,4};
    int n=sizeof(arr)/sizeof(int);
    cout << searchInSortedRotatedArray(arr,0,n-1,3);
    cout << searchInSortedRotatedArray(arr,0,n-1,6);
    cout << searchInSortedRotatedArray(arr,0,n-1,9);
    return 0;
}