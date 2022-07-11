#include <iostream>
#include <queue>
using namespace std;
void SortKSortedArray(int arr[], int n, int k)
{
    int i;     //for iterating
    int j = 0; //index where sorted element has to be put
    priority_queue<int, vector<int>, greater<int>> p1;
    for (i = 0; i < n; i++)
    {
        p1.push(arr[i]);
        if (p1.size() > k)
        {
            arr[j] = p1.top();
            p1.pop();
            j++;
        }
    }
    while (!p1.empty())
    {
        arr[j] = p1.top();
        p1.pop();
        j++;
    }
};
int main()
{
    int arr[] = {6, 5, 3, 2, 8, 10, 9};
    int k = 5;
    int n = sizeof(arr) / sizeof(int);
    SortKSortedArray(arr, n, k);
    for (int u = 0; u < n; u++)
    {
        cout << arr[u] << endl;
    }
    return 0;
}