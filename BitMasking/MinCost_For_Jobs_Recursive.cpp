#include <iostream>
#include <climits>
using namespace std;
int MinCostForJobs(int arr[4][4],int totalPersons,int pIndex,int mask){
    int cost=INT_MAX;
    int ans;
    // Base case
    if (pIndex>=totalPersons){
        return 0;
    }
    //Recursive call
    for (int j=0;j<totalPersons;j++){
        if (mask&(1<<j)==0){
            ans=arr[pIndex][j]+MinCostForJobs(arr,totalPersons,pIndex+1,mask|(1<<j));
        }
        if (ans<cost){
            cost=ans;
        }
    }
    return cost;
}
int main(){
    int arr[4][4]={{10,2,6,5},{1,15,12,8},{7,8,9,3},{15,13,4,10}};
    cout << MinCostForJobs(arr,4,0,0);
    return 0;
}