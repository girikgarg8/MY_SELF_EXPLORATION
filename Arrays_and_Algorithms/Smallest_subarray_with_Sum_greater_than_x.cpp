#include <iostream>
#include <climits>
using namespace std;
int smallestSubArray(int arr[], int n, int x)
{
    int i = 0;
    int j = 0;
    int sum = 0;
    int minLength = INT_MAX;
    while (j < n)
    {
        sum += arr[j];
        if (sum <= x)
        {
            j++;
        }
        else if (sum > x)
        {
            minLength = min(minLength, j - i + 1);
            while (sum > x)
            {
                sum -= arr[i];
                i++;
                if (sum > x)
                {
                    minLength = min(minLength, j - i + 1);
                }
            }
            j++;
        }
    }
    if (minLength != (INT_MAX))
    {
        return minLength;
    }
    return -1;
}
int main()
{
    int arr[] = {1, 4, 45, 6, 0, 19};
    int arr1[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250};
    int x = 51;
    int x1 = 280;
    cout << "Required length is" << smallestSubArray(arr, 6, x) << endl;
    cout << "Required length is" << smallestSubArray(arr1, 10, x1) << endl;
    return 0;
}