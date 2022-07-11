#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 1, 2, 0, 0, 1, 2, 2, 1, 0};
    int n = sizeof(arr) / sizeof(int);
    int low = 0;
    int high = n - 1;
    int mid = 0;
    while (low <= mid && mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else if (arr[mid] == 2)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}