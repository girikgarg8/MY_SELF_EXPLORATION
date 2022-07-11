#include <iostream>
using namespace std;
int LargestSubarray(int *arr, int size)
{
    int i = 0;
    int j = 0;
    int sum = 0;
    int k = 5;
    int maximum = 0;
    while (j < size)
    {
        sum += arr[j];
        if (sum < k)
        {
            j++;
        }
        if (sum == k)
        {
            cout << "One of the possible size of subarray is " << j - i + 1 << endl;
            maximum = max(maximum, j - i + 1);
            j++;
        }
        if (sum > k)
        {
            while (sum > k)
            {
                sum -= arr[i];
                i++;
            }
            if (sum == k)
            { //This is because after deleting the elements from the window, it may be possible that sum becomes equal to required sum eg. 2+3
                cout << "One of the possible size of subarray is " << j - i + 1 << endl;
                maximum = max(maximum, j - i + 1);
            }
            j++;
        }
    }
    return maximum;
}
int main()
{
    int arr[] = {4, 1, 1, 1, 2, 3, 5};
    int size = sizeof(arr) / sizeof(int);
    cout << "Size of largest subarray is " << LargestSubarray(arr, size) << endl;
}