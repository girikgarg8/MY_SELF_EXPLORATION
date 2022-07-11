#include <iostream>
using namespace std;
void Merge(int *arr1,int i, int j)
{   int m=(i+j)/2;
    int sizeOfNewArray = j - i + 1; //Last-First+1
    int sizeOfFirstArray = m - i + 1;
    int sizeOfSecondArray = j - m;
    int *finalArray = new int[sizeOfNewArray];
    int *k = &finalArray[i];
    int *ptr1 = &arr1[i];
    int *ptr2 = &arr1[i+1];
    while (i < sizeOfFirstArray && j < sizeOfSecondArray)
    {
        if (*ptr1 >= *ptr2)
        {
            *k = *ptr1;
            i++;
            k++;
        }
        else if (*ptr1 < *ptr2)
        {
            *k = *ptr2;
            j++;
            k++;
        }
    }
    while (i < mid)
    {
        *k = *ptr1;
        i++;
        k++;
    }
    while (j <=j)
    {
        *k = *ptr2;
        j++;
        k++;
    }
    for (int u=0;u<sizeOfNewArray;u++){
        arr1[u]=finalArray[u];
    }
    delete[]finalArray;
}
void MergeSort(int *arr1, int i, int j)
{
    if (i != j)
    { //i represnts first index of array, j represents last index of array
        int m = (i + j) / 2;
        MergeSort(arr1, i, m);
        //MergeSort (arr1,0,3)
        //MergeSort(arr1,0,1)
        //MergeSort(arr1,0,0)
        MergeSort(arr1, m + 1, j);
        Merge(arr1, i, j);
    }
    if (i == j)
    {
        return;
    }
}
int main()
{
    int arr[] = {8, 6, 7, 1, 2, 4, 3, 5};
    MergeSort(arr, 0, 7);
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}