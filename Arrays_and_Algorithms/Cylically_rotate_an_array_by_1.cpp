#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 5, 7, 8, 4, 2};
    int n = sizeof(arr) / sizeof(int);
    int last = arr[n - 1];
    int temp;
    for (int i = n - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1]; //Reverse traversal of array
    }
    arr[0] = last;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}