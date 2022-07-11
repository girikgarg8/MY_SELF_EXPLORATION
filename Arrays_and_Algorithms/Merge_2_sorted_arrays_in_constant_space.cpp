#include <iostream>
using namespace std;
void MergeArrays(int x[], int y[], int m, int n)
{
    int i = 0;
    int u;
    for (int i = 0; i < m; i++)
    {
        if (x[i] > y[0])
        {
            swap(x[i], y[0]);
            int first = y[0]; //I will now have to sort the second array
            for (u = 1; u < n && y[u] < first; u++)
            {
                y[u - 1] = y[u];
            }
            y[u - 1] = first;
        }
        //Keep in mind that the array y from 1 to n-1 is already sorted
        //I will now try to figure out the correct position of first in the array y
    }
}
int main()
{
    int arr1[] = {1, 4, 7, 8, 10};
    int arr2[] = {2, 3, 9};
    int m = sizeof(arr1) / sizeof(int);
    int n = sizeof(arr2) / sizeof(int);
    MergeArrays(arr1, arr2, m, n);
    for (int i = 0; i < m; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    for (int t = 0; t < n; t++)
    {
        cout << arr2[t] << " ";
    }
    return 0;
}