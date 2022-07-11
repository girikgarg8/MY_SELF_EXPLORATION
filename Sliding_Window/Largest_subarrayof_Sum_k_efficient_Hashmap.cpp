#include <iostream>
#include <map>
using namespace std;
int MaximumSubArraySize(int arr[],int size, int k)
{
    map<int, int> m1; //First one is prefix sum, second is index
    map<int,int> :: iterator it;
    int sum=0;
    int maxSubArrayLength=0;
    m1.insert(make_pair(0, 0));
    for (int i=0;i<size;i++){
        sum+=arr[i];
        m1.insert(make_pair(sum,i+1));
        it=m1.find(sum-k);
        if (it!=m1.end()){
            int index=it->second;
            maxSubArrayLength=max(maxSubArrayLength,i+1-index);
        }
    }
    return maxSubArrayLength;
}
int main()
{
    int arr[] = {3, 4, 7, 2, -3, 1, 4, 2};
    int size=sizeof(arr)/sizeof(int);
    int k = 7;
    cout << "Size of maximum subarray is " << MaximumSubArraySize(arr, size, k);
    return 0;
}