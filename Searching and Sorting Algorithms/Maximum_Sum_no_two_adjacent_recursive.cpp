#include <iostream>
using namespace std;
int maxSum(int arr[], int n, int i)
{
    if (i == (n))
    {
        return 0;
    }
    if (i == (n - 1))
    {
        return arr[n - 1];
    }
    if (i == (n - 2))
    {
        return max(arr[n - 1], arr[n - 2]);
    }
    // two choices for every element: either choose that element or leave that element
    int Sum = 0;
    int a = maxSum(arr, n, i + 1);
    int b = arr[i] + maxSum(arr, n, i + 2);
    Sum = max(Sum, max(a, b));
    return Sum;
}
int main()
{
    int a[] = {1, 2, 9, 4, 5, 0, 4, 11, 6}; //Correct answer is 26
    int n = sizeof(a) / sizeof(int);
    cout << maxSum(a, n, 0);
    return 0;
}