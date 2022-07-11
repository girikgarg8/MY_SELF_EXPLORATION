#include <iostream>
using namespace std;
int FirstOccurence(int arr[], int s, int e, int search)
{
    int ans;
    while (s <= (e - 1))
    {
        int mid = (s + e) / 2;
        if (arr[mid] < search)
        {
            s = mid + 1;
        }
        if (arr[mid] > search)
        {
            e = mid - 1;
        }
        if (arr[mid] == search)
        {
            ans = mid;
            e = mid - 1;
        }
    }
    return ans;
}
int main()
{
    int arr[] = {1, 2, 2, 2, 2, 4, 4, 6, 6};
    int n = sizeof(arr) / sizeof(int);
    int search;
    cout << "Enter element to search" << endl;
    cin >> search;
    int x = FirstOccurence(arr, 0, n, search);
    if (x == -1)
    {
        cout << "Element not found" << endl;
    }
    else
        cout << "Element " << search << "found at index " << x << endl;
    return 0;
}