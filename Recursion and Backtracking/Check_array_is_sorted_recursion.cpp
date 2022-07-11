#include <iostream>
using namespace std;
bool checkIsArraySorted(int *arr,int size){
    if (size==1){
        return true;
    }
    bool x=checkIsArraySorted(arr+1,size-1);
    if (arr[0]<arr[1] && x){
        return true;
    }
    return false
}
int main(){
    int arr[]={1,3,5,7,8};
    int arr1[]={3,2,6,9};
    cout << checkIsArraySorted(arr,5) << endl;
    cout << checkIsArraySorted(arr1,4) <<endl;
    return 0;
}