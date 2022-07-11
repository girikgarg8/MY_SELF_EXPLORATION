#include <iostream>
using namespace std;
void ThreeWayPartition(int arr[], int n, int a, int b)
{
    int low = 0;      //like starting point of 1 in DNF
    int high = n - 1; //like starting point of 2 in DNF
    int mid = 0;
    while (mid <= high && low <= mid)
    {
        if (arr[mid] >= a && arr[mid] <= b)
        {
            mid++;
        }
        else if (arr[mid] < a)
        {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if (arr[mid] > b)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}
int main()
{
    int a[] = {5, 6, 3, 2, 4, 7, 0, 1, 9};
    int n = sizeof(a) / sizeof(int);
    ThreeWayPartition(a, n, 3, 5);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
