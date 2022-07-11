#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int Partition(int arr[], int s, int e)
{
    int pivot = arr[e];
    int i = s - 1; //rare pointer
    int j; //traversing pointer
    for (j = s; j < e; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[e]);
    return i + 1;
}
void QuickSort(int arr[], int s, int e)
{
    if (s >= e)
        return;
    int x = Partition(arr, s, e);
    QuickSort(arr, s, x - 1);
    QuickSort(arr, x + 1, e);
}
int main()
{
    int a[] = {2, 7, 8, 6, 1, 5, 4};
    QuickSort(a, 0, 6);
    for (int i = 0; i <= 6; i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}