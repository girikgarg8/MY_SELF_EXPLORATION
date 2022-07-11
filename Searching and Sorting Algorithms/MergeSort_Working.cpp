#include <iostream>
using namespace std;
void Merge(int arr[], int i, int j)
{
    int mid = (i + j) / 2;
    int *newArray = new int[j - i + 1]; //newArray is a temporary array
    int u = i;                          //u and z are variables which represent the position of elements in array
    int z = mid + 1;
    int k = i; //k represents index of new combined array
    while (u <= mid && z <= j)
    {
        if (arr[u] <= arr[z])
        {
            newArray[k] = arr[u];
            u++;
            k++;
        }
        if (arr[u] > arr[z])
        {
            newArray[k] = arr[z];
            z++;
            k++;
        }
    }
    while (u <= mid)
    {
        newArray[k] = arr[u];
        u++;
        k++;
    }
    while (z <= j)
    {
        newArray[k] = arr[z];
        z++;
        k++;
    }
    for (int g = i; g <= j; g++)
    {
        arr[g] = newArray[g];
    }
    delete[] newArray;
}
void MergeSort(int arr[], int i, int j)
{
    if (i < j)
    {
        int m = (i + j) / 2;
        MergeSort(arr, i, m);
        MergeSort(arr, m + 1, j);
        Merge(arr, i, j);
    }
    if (i >= j)
    {
        return;
    }
}
int main()
{
    int b[] = {3, 4, 5, 2};
    MergeSort(b, 0, 3);
    for (int i = 0; i <= 3; i++)
    {
        cout << b[i] << endl;
    }
    return 0;
}