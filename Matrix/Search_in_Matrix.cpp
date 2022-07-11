#include <bits/stdc++.h>
using namespace std;
bool binarySearch1DArray(int arr[],int size,int key){
    int low=0;
    int high=size-1;
    while (low<=high){
        int mid=low+(high-low)/2;
        if (arr[mid]==key){
            return true;
        }
        if (arr[mid]>key){
            high=mid-1;
        }
        else low=mid+1;
    }
    return false;
}
bool binarySearch2DArray(int matrix[][4],int r,int c,int key){
    int low=0;
    int high=r-1;
    while (low<=high){
        int mid=low+(high-low)/2;
        //We will see if the given element lies in this row or not, if it lies, we wil call 1d binary search on this row
        if (key>=matrix[mid][0] && key<=matrix[mid][c-1]){
            return binarySearch1DArray(matrix[mid],c,key);
        }
        else if (key<matrix[mid][0]){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return false;
}
int main(){
    int matrix[3][4]={{1,3,5,7},{10,11,16,20},{23,30,34,50}};
    int key=3;
    int key1=34;
    int key2=60;
    cout << binarySearch2DArray(matrix,3,4,key) <<endl;
    cout << binarySearch2DArray(matrix,3,4,key1) <<endl;
    cout << binarySearch2DArray(matrix,3,4,key2) <<endl;
    return 0;
}