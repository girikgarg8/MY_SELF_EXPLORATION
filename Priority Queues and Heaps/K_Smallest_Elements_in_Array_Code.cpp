#include <iostream>
#include <queue>
using namespace std;
void LargestKElements (int arr[],int n,int k){
    priority_queue <int> p1;
    int i;
    for (i=0;i<k;i++){
        p1.push(arr[i]);
    }
    while (i<n){
    p1.push(arr[i]);
    p1.pop();
    i++;
}
while (!p1.empty()){
    cout << p1.top() <<endl;
    p1.pop();
}
}
int main(){
    int arr[]={8,5,12,10,0,1,6,9};
    int n=sizeof(arr)/sizeof(int);
    LargestKElements(arr,n,4);
    return 0;
}

