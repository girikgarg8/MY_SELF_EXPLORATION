#include <iostream>
using namespace std;
void CountSort(int arr[], int n)
{
    int *frequencyarray = new int[n];
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == i)
            {
                count++;
            }
        }
        frequencyarray[i] = count;
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<frequencyarray[i];j++){
            arr[i]=i;
        }
    }
}
int main()
{
    int arr[] = {3, 5, 2, 1, 6, 4, 3};
    int n = sizeof(arr) / sizeof(int);
    CountSort(arr, n);
    
}