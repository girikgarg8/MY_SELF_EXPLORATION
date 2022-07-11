#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void randomise(int arr[], int s, int e)
{
    int j; //represents random index number to be swapped with
    srand(time(NULL));
    for (int i = e; i >= s; i--)
    {
        int j = rand() % (i + 1);
        swap(&arr[i], &arr[j]);
    }
}
int Partition(int arr[], int s, int e)
{
    int pivot = arr[e];
    int i = s - 1;
    int j;
    for (j = s; j <e; j++)
    {
        if (arr[j] <= pivot)
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
    int b[] = {1, 2, 3, 4, 5};
    randomise(b, 0, 4);
    cout << "Elements of randomised array are:";
    for (int i = 0; i <= 4; i++)
    {
        cout << b[i] << endl;
    }
    QuickSort(b, 0, 4);
    cout << "Elements after quick sort are:";
    for (int i = 0; i <= 4; i++)
    {
        cout << b[i] << endl;
    }
    return 0;
}