#include <iostream>
#include <deque>
using namespace std;
int sumOfMaxAndMin(int arr[], int n, int k)
{
    deque<int> minDQ;
    deque<int> maxDQ;
    int totalSum = 0;
    for (int i = 0; i < k; i++)
    {
        int curr = arr[i];
        while (!minDQ.empty() && arr[minDQ.back()] >= curr)
        {
            minDQ.pop_back();
        }
        while (!maxDQ.empty() && arr[maxDQ.back()] <= curr)
        {
            maxDQ.pop_back();
        }
        minDQ.push_back(i);
        maxDQ.push_back(i);
    }
    totalSum += arr[minDQ.front()] + arr[maxDQ.front()];
    for (int j = k; j < n; j++)
    {
        int curr = arr[j];
        while (!minDQ.empty() && minDQ.front() <= j - k)
        {
            minDQ.pop_front();
        }
        while (!maxDQ.empty() && maxDQ.front() <= j - k)
        {
            maxDQ.pop_front();
        }
        while (!minDQ.empty() && arr[minDQ.back()] >= curr)
        {
            minDQ.pop_back();
        }
        while (!maxDQ.empty() && arr[maxDQ.back()] <= curr)
        {
            maxDQ.pop_back();
        }
        minDQ.push_back(j);
        maxDQ.push_back(j);
        totalSum += arr[minDQ.front()] + arr[maxDQ.front()];
    }
    return totalSum;
}
int main()
{
    int n, k;
    cin >> n >> k;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << sumOfMaxAndMin(arr, n, k);
    return 0;
}

//Sliding window approach
/*
#include <set>
int sumOfMaxAndMin(vector<int> &nums, int n, int k) {
int totalSum=0;
multiset<int> st;
for (int i=0;i<k;i++){
    st.insert(arr[i]);
}
int minCurrent=*(st.begin());
int maxCurrent=*(st.rbegin());
totalSum+=(minCurrent+maxCurrent);
int startIndex=0;
for (int i=k;i<n;i++){
    st.erase(st.find(nums[startIndex]));
    st.insert(nums[i]);
    minCurrent=*(st.begin());
    maxCurrent=*(st.rbegin());
    totalSum+=minCurrent+maxCurrent;
    startIndex++;
}
return totalSum;

//

*/