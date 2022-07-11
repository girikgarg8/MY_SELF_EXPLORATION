#include <iostream>
using namespace std;
int Merge(int arr[], int low, int mid, int high)
{
    int inv_1 = 0;
    int n1 = mid - low + 1;
    int n2 = high - (mid + 1) + 1;
    int *a1 = new int[n1];
    int *b1 = new int[n2];
    for (int i = 0; i < n1; i++)
    {
        a1[i] = arr[low + i]; //not arr[i]
    }
    for (int j = 0; j < n2; j++)
    {
        b1[j] = arr[j + mid + 1];
    }
    int x = 0, y = 0;
    int z = low;
    while (x < n1 && y < n2)
    {
        if (a1[x] <= b1[y])
        {
            arr[z] = a1[x];
            z++;
            x++;
        }
        else if (a1[x] > b1[y])
        {
            arr[z] = b1[y];
            z++;
            y++;
            inv_1 += (n1 - x); //This step is important, if element in b is bigger than index x of first array, then it is surely bigger than x+1, x+2 etc of first array also
        }
    }
    while (x < n1)
    {
        arr[z] = a1[x];
        x++;
        z++;
    }
    while (y < n2)
    {
        arr[z] = b1[y];
        y++;
        z++;
    }
    return inv_1;
}
int MergeSort(int a[], int low, int high)
{
    int inv = 0;
    if (low < high)
    {
        int mid = (low + high) / 2;
        inv += MergeSort(a, low, mid);
        inv += MergeSort(a, mid + 1, high);
        inv += Merge(a, low, mid, high);
    }
    return inv;
}
int main()
{
    int arr[] = {2, 4, 1, 3, 5};
    cout << "Number of inversions are " << MergeSort(arr, 0, 4);
    return 0;
}
