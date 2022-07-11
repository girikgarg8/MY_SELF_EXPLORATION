#include <iostream>
using namespace std;
int main(){
    int arr[]={1,4,6,7,5};
    int i=0;
    int size=sizeof(arr)/sizeof(int);
    int j=size-1;
    while (i<=j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
    for (int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    return 0;
}