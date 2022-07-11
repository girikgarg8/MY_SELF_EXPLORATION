#include <iostream>
using namespace std;
int MaxProfit(int prices[],int n){
    int Min_So_Far=prices[0];
    int profit=0;
    for (int i=0;i<n;i++){
        Min_So_Far=min(prices[i],Min_So_Far);
        profit=max(profit,(prices[i]-Min_So_Far));
    }
    return profit;
}
int main(){
    int prices[]={7,1,5,3,6,4};
    int n=sizeof(prices)/sizeof(int);
    cout << "Maximum profit that can be earned is" << MaxProfit(prices,n); 
    return 0;
}