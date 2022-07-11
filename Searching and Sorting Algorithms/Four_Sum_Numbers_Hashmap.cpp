#include <bits/stdc++.h>
using namespace std;
void findFourElements(int arr[], int n, int X)
{
    // sums of all pairs in a hash table
    unordered_map<int, pair<int, int>> mp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            mp[arr[i] + arr[j]] = {i, j};
        }
    }
    //Traverse through all pairs and search for X-currentPairSum
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = arr[i] + arr[j];
            if (mp.find(X - sum) != mp.end())
            {
                //Now we need to check whether all the four elements are distinct array elements and an element is not considered more than once
                pair<int, int> p = mp[X - sum];
                if (p.first != i && p.first != j && p.second != i && p.second != j)
                {
                    cout << arr[i] << "," << arr[j] << "," << arr[p.first] << "," << arr[p.second];
                    return;
                }
            }
        }
    }
}
int main()
{
    int arr[] = {10, 20, 30, 40, 1, 2};
    int n = sizeof(arr) / sizeof(int);
    int X = 91;
    findFourElements(arr, n, X);
    return 0;
}