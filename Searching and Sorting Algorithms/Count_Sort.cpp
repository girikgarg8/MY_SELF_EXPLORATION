#include <iostream>
using namespace std;
void CountSort(int arr[], int n)
{
    int *frequencyarray = new int[n];
    for (int i = 0; i < n; i++)
    {
        frequencyarray[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        frequencyarray[arr[i]] += 1;
    }
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= frequencyarray[i]; j++)
        {
            arr[k] = i;
            k++;
        }
    }
}
int main()
{
    int arr[] = {3, 5, 2, 1, 6, 4, 3};
    int n = sizeof(arr) / sizeof(int);
    CountSort(arr, n);
    for (int u = 0; u < n; u++)
    {
        cout << arr[u] << endl;
    }
    return 0;
}