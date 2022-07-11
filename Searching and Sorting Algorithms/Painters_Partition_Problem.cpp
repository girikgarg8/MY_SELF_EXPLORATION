#include <bits/stdc++.h>
using namespace std;
bool isValid(int boards[],int n,int k,int numToValidate){
    int sum_till_now=0;
    int numOfPainters=1;
    for (int i=0;i<n;i++){
        if (sum_till_now+boards[i]>numToValidate){
            numOfPainters++;
            sum_till_now=boards[i];
            if (numOfPainters>k){
                return false;
            }
        }
        else{
            sum_till_now+=boards[i];
        }
    }
    return true;
}
int BinarySearchOnPainters(int boards[],int n,int k){
    int low=boards[0];
    int sum=0;
    for (int i=0;i<n;i++){
        sum+=boards[i];
    }
    int high=sum;
    int ans;
    while (low<=high){
        int mid=(low)+(high-low)/2;
        if (isValid(boards,n,k,mid)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int main(){
    int k=2;
    int boards[]={10,20,30,40}; //make sure they are in sorted order
    int n=sizeof(boards)/sizeof(int);
    int a=BinarySearchOnPainters(boards,n,k);
    cout << a <<endl;
    return 0;
}