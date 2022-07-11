#include <iostream>
#include <string>
using namespace std;
int BinarySearch(int *arr, int s, int e, int key)
{
    int mid = (s + e) / 2;
    if (s > e)
    {
        return -1;
    }
    if (arr[mid] == key)
    {
        return mid;
    }
    if (arr[mid] > key)
    {
        return BinarySearch(arr, s, mid - 1, key);
    }
    if (arr[mid] < key)
    {
        return BinarySearch(arr, mid + 1, e, key);
    }
}
int main()
{
    int arr[] = {1, 5, 6, 7, 9};
    cout << BinarySearch(arr, 0, 4, 9) << endl;
    cout << BinarySearch(arr, 0, 4, 11) << endl;
    cout << BinarySearch(arr, 0, 4, 1) << endl;
    return 0;
}
