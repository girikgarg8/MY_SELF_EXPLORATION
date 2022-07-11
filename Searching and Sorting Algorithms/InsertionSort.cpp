#include <iostream>
using namespace std;
void InsertionSort(int arr[], int s, int e)
{
    for (int i = 1; i <= e; i++)
    {
        int j = i - 1;
        int number = arr[i];
        while (j >= 0 && arr[j] > number)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = number;
    }
}
int main()
{
    int b[] = {4, 1, 2, 0, 3};
    InsertionSort(b, 0, 4);
    cout << "Elements are sorting are:" << endl;
    for (int u = 0; u <= 4; u++)
    {
        cout << b[u] << endl;
    }
    return 0;
}