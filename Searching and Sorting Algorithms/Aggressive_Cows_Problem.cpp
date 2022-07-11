#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[]={8,9,12,16,1,2,4};
    int n=sizeof(a)/sizeof(int);
    int c=4;
    sort(a,a+n);
    int low=0;
    int high=a[n-1];
    int mid;
    int best=0;
    while (low<=high){
        mid= (low+high+1)/2 ; //in case of an even sized array 1 2 3 4 mid would point at 3 instaed of 2
        int cnt=1; //denoting number of cows
        int left=0; //tries to place the cows at the given value of gap
        for (int i=1;i<n && cnt<c;i++){
            if (a[i]-a[left]>=mid){
                left=i; //Start placing the next cow from the index i
                cnt++;
            }
            if (cnt>=c){
                best=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    cout << best <<endl;
    return 0;
}