#include <iostream>
using namespace std;
int MinimumCost(int nums[],int n,int k){
    if (n==1){
        return 0;
    }
    int min_cost=0;
    // if ((nums[0] + nums[1] + 1)<= k){
    //     min_cost += min(((k-nums[0]-nums[1]-1) * (k-nums[0]-nums[1]-1)),((k-nums[0])*(k-nums[0])));
    // }
    // else if ((nums[0] + nums[1] + 1)>k){
    //     min_cost += (k - nums[0]) * (k - nums[0]);
    // }
    // for (int i=1;i<n;i++){
    //     if 
    // }
    
    int x = MinimumCost(nums + 1, n - 1, k);
    min_cost+=x;
    return min_cost;
}
int main(){
    int nums[]={3,2,2,5};
    int k=6;
    cout << MinimumCost(nums,4,k) ;
    return 0;
}