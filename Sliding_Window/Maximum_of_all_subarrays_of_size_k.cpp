#include <iostream>
#include <vector>
#include <list>
using namespace std;
vector <int> maximumSum (vector <int> &arr){
    vector <int> maxSum;
    list<int> l1;
    int i=0;
    int j=0;
    int k=3; // size of subarray/sliding window
    while (j<arr.size()){
        while (!l1.empty() && l1.back() <arr[j]){ //Remove the elements in the list which are smaller than the element being added
        l1.pop_back();
        }
        l1.push_back(arr[j]);
        //Calculation step
        if ((j-i+1)<k){
            j++;
        }
        if ((j-i+1)==k){
            int maximum=l1.front();
            maxSum.push_back(maximum);
            if (maximum==arr[i]){
                l1.pop_front();
            }
            i++;
            j++;
        }
    }
    return maxSum;
}
int main(){
    vector <int> arr={1,3,-1,-3,5,3,6,7};
    vector <int> answer=maximumSum(arr);
    for (auto i:answer){
        cout << i <<endl;
    }
    return 0;
}