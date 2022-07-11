#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    int arr[] = {4, 5, 6, 8};
    int n1 = sizeof(arr) / sizeof(int);
    int arr1[] = {5, 8, 2, 3, 1};
    int n2 = sizeof(arr1) / sizeof(int);
    int count = 0;
    unordered_map<int, int> m1;
    for (int i = 0; i < n1; i++)
    {
        m1[arr[i]] += 1;
    }
    for (int i = 0; i < n2; i++)
    {
        m1[arr1[i]] += 1;
    }
    for (auto it : m1)
    {
        if (it.second > 1)
        {
            count++;
        }
    }
    cout << "Intersection of two arrays has count " << count << endl;
    return 0;
}