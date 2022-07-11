#include <iostream>
#include <climits>
using namespace std;
float MergeArrays(int arr[], int n, int arr1[], int m)
{
    int low = 0; //For better optimisation, we can apply binary concept on the array having less number of elements, here doing it on first one for simplicity
    int high = n;
    while (low <= high)
    {
        int cut1 = (low + high) / 2;   //in the first array
        int cut2 = (n + m) / 2 - cut1; //in the second array, we are not using binary search on this
        int l1, l2, r1, r2;
        if (cut1 == 0)
        {
            l1 = INT_MIN; //INT_MIN because it is smaller than a value eg,5  so it can go upto -infinity
        }
        else
        {
            l1 = arr[cut1 - 1];
        }
        if (cut1 == n)
        {
            r1 = INT_MAX;
        }
        else
        {
            r1 = arr[cut1];
        }
        if (cut2 == 0)
        {
            l2 = INT_MIN;
        }
        else
        {
            l2 = arr1[cut2 - 1];
        }
        if (cut2 == n)
        {
            r2 = INT_MAX;
        }
        else
        {
            r2 = arr1[cut2];
        }
        if (l1 > r2)
        {
            high = cut1 - 1;
        }
        if (l2 > r1)
        {
            low = cut1 + 1;
        }
        else if ((n + m) % 2 == 0)
        {
            return (max(l1, l2) + min(r1, r2)) / 2.0;
        }
        else
        {
            return min(r1, r2); //Because there would be one extra element in the right side
        }
    }
    return -1;
}
int main()
{
    int a[] = {1, 3, 4, 7, 10, 12};
    int b[] = {2, 3, 6, 5};
    int n = sizeof(a) / sizeof(int);
    int m = sizeof(b) / sizeof(int);
    int x = MergeArrays(a, n, b, m);
    cout << x << endl;
    return 0;
}