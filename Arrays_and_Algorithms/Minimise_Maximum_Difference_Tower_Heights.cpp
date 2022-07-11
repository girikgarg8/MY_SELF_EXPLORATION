#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int arr[]={3,9,6,12,20};
    int k=3;
    int n=sizeof(arr)/sizeof(int);
    sort(arr,arr+n);
    int ans=arr[n-1]-arr[0];
    int smallest=arr[0]+k;
    int largest=arr[n-1]-k;
    int mi,ma;
    for (int i=0;i<n-1;i++){
        mi=min(smallest,arr[i+1]-k); //minimum considering entire perspective
        ma=max(largest,arr[i]+k);
        if (mi<0){
            continue;
        }
        ans=min(ans,ma-mi);
    }
    cout << ans;
    return 0;
}