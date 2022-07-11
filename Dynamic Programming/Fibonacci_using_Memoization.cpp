#include <iostream>
using namespace std;
int helper(int *arr,int n){
    for (int i=0;i<=n;i++){
        arr[i]=-1;
    }
    if (n==0 || n==1){
        return n;
    }
    if (arr[n]!=(-1)){
        return arr[n];
    }
    int a=helper(arr,n-1);
    int b=helper(arr,n-2);
    arr[n]=a+b;
    return arr[n];
}
int fibonacci(int n){
    int *arr=new int[n+1];
    return helper(arr,n);
}
int main(){
    cout << fibonacci(6) <<endl;
    return 0; 
}