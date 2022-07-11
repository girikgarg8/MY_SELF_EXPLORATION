#include <iostream>
using namespace std;
int main()
{
    int arr[] = {3, 1, 2, 4, 0, 1, 3, 2};
    int n = sizeof(arr) / sizeof(int);
    int *left = new int[n];
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], arr[i]); //Self value is also allowed
    }
    int *right = new int[n];
    int ans = 0;
    right[n - 1] = arr[n - 1];
    for (int j = n - 2; j >= 0; j--)
    {
        right[j] = max(arr[j], right[j + 1]);
    }
    for (int i = 0; i < n; i++)
    {
        ans += min(left[i], right[i]) - arr[i];
    }
    cout << "Number of blocks are " << ans << endl;
    delete[] left;
    delete[] right;
    return 0;
}