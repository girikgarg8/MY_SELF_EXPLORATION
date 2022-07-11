#include <iostream>
using namespace std;
void InplaceHeapSort(int pq[], int n)
{
    //Build the heap in the array itself
    for (int i = 1; i < n; i++)
    {
        int ChildIndex = i;
        while (ChildIndex > 0)
        {
            int ParentIndex = (ChildIndex - 1) / 2;
            if (pq[ChildIndex] < pq[ParentIndex])
            {
                swap(pq[ChildIndex], pq[ParentIndex]);
            }
            else
            {
                break;
            }
            ChildIndex = ParentIndex;
        }
    }
    int size = n;
    while (size > 1)
    {
        swap(pq[size - 1], pq[0]);
        size--;
        int MinIndex;
        int ParentIndex = 0;
        while ((2 * (ParentIndex) + 1) < size)
        {
            int LeftChildIndex = 2 * ParentIndex + 1;
            int RightChildIndex = 2 * ParentIndex + 2;
            if (LeftChildIndex < size && RightChildIndex < size)
            {
                if (pq[LeftChildIndex] < pq[RightChildIndex])
                {
                    MinIndex = LeftChildIndex;
                }
                else
                    MinIndex = RightChildIndex;
            }
            else if (LeftChildIndex < size)
            {
                MinIndex = LeftChildIndex;
            }
            if (pq[ParentIndex] > pq[MinIndex])
            {
                swap(pq[ParentIndex], pq[MinIndex]);
            }
            else if (pq[ParentIndex] < pq[MinIndex])
            {
                break;
            }
            ParentIndex = MinIndex;
        }
    }
}
int main()
{
    int arr[] = {9, 7, 11, 3, 2};
    InplaceHeapSort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}
