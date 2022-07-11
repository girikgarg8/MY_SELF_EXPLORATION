#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int arr[] = {5, -4, -2, 6, -1};
    int n = sizeof(arr) / sizeof(int);
    int curSum = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        curSum += arr[i];
        if (curSum > maxSum)
        {
            maxSum = curSum;
        }
        if (curSum < 0)
        {
            curSum = 0;
        }
    }
    cout << "Maximum sum is " << maxSum << endl;
    return 0;
}