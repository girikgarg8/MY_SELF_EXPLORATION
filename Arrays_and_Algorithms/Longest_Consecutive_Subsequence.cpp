#include <iostream>
#include <unordered_set>
using namespace std;
int main()
{
    int arr[] = {102, 4, 100, 1, 101, 3, 2};
    int n = sizeof(arr) / sizeof(int);
    int maxLength = 0;
    unordered_set<int> s1;
    for (int i = 0; i < n; i++)
    {
        s1.insert(arr[i]);
    }
    int i = 0;
    while (i < n)
    {
        int j = 0;
        int length = 0;
        if (s1.find(arr[i] - 1) != s1.end())
        {
            i++; //Means element is found in the set, do nothing
        }
        else
        {
            while (s1.find(arr[i] + j) != s1.end())
            {
                length++;
                j++;
            }
            maxLength = max(maxLength, length);
            i++;
        }
    }
    cout << "The longest consecutive sequence is of length " << maxLength;
    return 0;
}