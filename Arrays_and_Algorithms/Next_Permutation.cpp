#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> NextPermutation(vector<int> &arr)
{
    int i;
    int j;
    int k;
    int size = arr.size();
    for (i = size - 2; i >= 0; i--)
    {
        if (arr[i + 1] > arr[i])
        {
            break;
        }
    }
    if (i == (-1))
    {
        reverse(arr.begin(), arr.end());
        return arr;
    }
    else
    {
        for (int k = size - 1; k >= 0; k--)
        {
            if (arr[k] > arr[i])
            {
                swap(arr[k], arr[i]);
                break;
            }
        }
        reverse(arr.begin() + i + 1, arr.end());
    }
    return arr;
}
int main()
{
    vector<int> arr = {1, 3, 5, 4, 2};
    vector<int> ans = NextPermutation(arr);
    for (auto u : ans)
    {
        cout << u << " ";
    }
    cout << endl;
    vector<int> arr1 = {5, 4, 3, 2, 1};
    vector<int> ans1 = NextPermutation(arr1);
    for (auto u : ans1)
    {
        cout << u << " ";
    }
    return 0;
}