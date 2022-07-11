#include <iostream>
#include <list>
using namespace std;
int main()
{
    int arr[] = {12, -1, -7, 8, -16, 30, 16, 28};
    int size = sizeof(arr) / sizeof(int);
    list<int> nNumber; //negative numbers linked list
    int k = 3;         //this would be given in the question, size of subarray
    int i = 0;
    int j = 0;
    while (j < size)
    {
        if ((j - i + 1) < k)
        {
            j++;
            if (j >= size)
            {
                break;
            }
            else if (arr[j] < 0)
            {
                nNumber.push_back(arr[j]);
            }
        }
        if ((j - i + 1) == k)
        {
            if (!nNumber.empty())
            {
                cout << nNumber.front() << " ";
            }
            else if (nNumber.empty())
            {
                cout << "0 ";
            }
            if (arr[i] == nNumber.front())
            {
                nNumber.pop_front();
            }
            i++;
        }
    }
    return 0;
}