#include <bits/stdc++.h>
using namespace std;
int maxAreaUnderHistogram(int arr[], int n)
{
    int maxArea = 0;
    stack<int> s1;
    for (int i = 0; i < n; i++)
    {
        if (s1.empty() || (arr[i] > arr[s1.top()]))
        {
            s1.push(i);
        }
        // else
        // {
        //     while ((arr[s1.top()] > arr[i]))
        //     {
        //         int value = arr[s1.top()];
        //         s1.pop(); //I need to pop first, don't pop after making the function call
        //         bool b = s1.empty();
        //         if (!b)
        //         {
        //             int l = s1.top();
        //             int area = value * (i - l - 1);
        //             maxArea = max(area, maxArea);
        //         }
        //         else
        //         {
        //             int area = value * i;
        //             maxArea = max(area, maxArea);
        //         }
        //         if (s1.empty())
        //             break;
        //     }
        //     s1.push(i);
        // }
    }
    return maxArea;
}
int main()
{
    int arr[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(arr) / sizeof(int);
    cout << maxAreaUnderHistogram(arr, n);
    return 0;
}