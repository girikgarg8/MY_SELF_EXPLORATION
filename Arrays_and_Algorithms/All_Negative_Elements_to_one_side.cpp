#include <iostream>
using namespace std;
int main()
{
    int arr[] = {3, -2, 5, -4, 1, 6};
    int n = sizeof(arr) / sizeof(int);
    int i = -1;
    int j = 0;
    int pivot = 0;
    for (int u = 0; u < n; u++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
        else if (arr[j] > pivot)
        {
            j++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}