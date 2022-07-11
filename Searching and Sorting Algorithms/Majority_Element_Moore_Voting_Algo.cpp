#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={3,3,4,2,4,4,2,4,4};
    int arr1[]={3,3,4,2,4,4,2,4};
    int n=sizeof(arr)/sizeof(int);
    int m=sizeof(arr1)/sizeof(int);
    int maxCandidate;
    int count=0;
    for (int i=0;i<n;i++){
        if (count!=0){
            if (arr[i]==maxCandidate){
                count++;
            }
            else count--;
        }
        if (count==0){
            maxCandidate=arr[i];
            count=1;
        }
    }
    int cnt1=0;
    //Now I need to check whether maxCandidate occurs more than floor (n/2) or not
    // floor (n/2) is actually n/2 of programming eg. if n=5, floor(5/2)=2 and 5/2=2,  if n=4 floor (4/2)=2 and 4/2=2
    for (int i=0;i<n;i++){
        if (arr[i]==maxCandidate){
            cnt1++;
        }
    }
    if (cnt1>(n/2)){
        cout << maxCandidate <<endl;
    }
    else {
        cout << "There is no majority element";
    }
    return 0;
}