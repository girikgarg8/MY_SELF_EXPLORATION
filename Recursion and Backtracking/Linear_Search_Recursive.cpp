#include <iostream> //1 5 6 7 search for 5 and 6
#include <string>
using namespace std;
int LinearSearch(int *arr, int size, int key, int index)
{
    if (arr[0] == key)
    {
        return index;
    }
    if (size == 0)
    {
        return -1;
    }
    int x = LinearSearch(arr + 1, size - 1, key, index + 1);
}
int main()
{
    int arr[] = {1, 5, 6, 7, 9};
    cout << LinearSearch(arr, 5, 7, 0) << endl;
    cout << LinearSearch(arr, 5, 11, 0) << endl;
    return 0;
}
