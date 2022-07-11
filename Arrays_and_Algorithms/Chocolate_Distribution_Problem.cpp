#include <iostream>
#include <algorithm>
using namespace std;
int MinimumChocolates(int arr[], int n, int m)
{
    sort(arr, arr + n);
    int i = 0;
    int j = 0;
    int minimum = INT_MAX;
    while (j < n)
    {
        if ((j - i + 1) < m)
        {
            j++;
        }
        else if ((j - i + 1) == m)
        {
            minimum = min(minimum, arr[j] - arr[i]);
            i++;
            j++;
        }
    }
    return minimum;
}
int main()
{
    int arr[] = {3, 4, 1, 9, 56, 7, 9, 12};
    int n = sizeof(arr) / sizeof(int);
    int m = 5;
    cout << MinimumChocolates(arr, n, m);
    return 0;
}