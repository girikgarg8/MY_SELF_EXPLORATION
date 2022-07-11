#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={7,1,5,3,6,4};
    int n=sizeof(arr)/sizeof(int);
    int maxProfit=0;
    int minSelling_Price_till_Now=arr[0];
    for (int i=0;i<n;i++){
        minSelling_Price_till_Now=min(minSelling_Price_till_Now,arr[i]);
        maxProfit=max(maxProfit,arr[i]-minSelling_Price_till_Now);
    }
    cout << "Maximum possible profit is " << maxProfit <<endl;
    return 0;
}