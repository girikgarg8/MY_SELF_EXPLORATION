#include <iostream>
using namespace std;
void rightRotate(int arr[], int from, int to)
{
    int temp = arr[to];
    for (int i = to; i > from; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[from] = temp;
}
void rearrange(int arr[], int n)
{
    int WrongIndex = (-1);
    for (int i = 0; i < n; i++)
    {
        if (WrongIndex != (-1))
        { //WrongIndex has been found
            if ((arr[WrongIndex] > 0 && arr[i] < 0) || (arr[WrongIndex] < 0 && arr[i] > 0)) //looking for opposite sign element
            {
                rightRotate(arr, WrongIndex, i);
                if ((i - WrongIndex >= 2))
                {
                    WrongIndex += 2; //Updating the value of WrongIndex
                }
                else
                {
                    WrongIndex = (-1);
                }
            }
            //Now I need to search for the next element with alternate sign
        }
        else
        {
            if ((arr[i] > 0 && i % 2 == 0) || (arr[i] < 0 && i % 2 != 0)) //Finding the wrongIndex
            {
                WrongIndex = i;
            }
        }
    }
}
int main()
{
    int arr[] = {2, 3, -4, -1, 6, 9};
    int n = sizeof(arr) / sizeof(int);
    rearrange(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}