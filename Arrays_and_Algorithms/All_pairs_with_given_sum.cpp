#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    int arr[] = {1, 5, 7, 1};
    unordered_map<int, int> m1;
    int k = 6;
    int countOfPairs = 0;
    int n = sizeof(arr) / sizeof(int);
    for (int i = 0; i < n; i++)
    {
        if (m1[k - arr[i]] == 0)
        {
            m1[arr[i]] += 1; //I cannot use prefix sum approach here for two reasons: pair need not be a subarray, such a subarray may have more than two elements
        }
        else
        {
            countOfPairs += m1[k - arr[i]];
            m1[arr[i]] += 1;
        }
    }
    cout << "Required number of pairs are " << countOfPairs;
    return 0;
}