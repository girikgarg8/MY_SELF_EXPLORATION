#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    int arr[] = {4, 5, 6, 8};
    int n1 = sizeof(arr) / sizeof(int);
    int arr1[] = {5, 8, 2, 3, 1};
    int n2 = sizeof(arr1) / sizeof(int);
    unordered_map <int, int> m1;
    for (int i = 0; i < n1; i++)
    {
        m1[arr[i]] += 1;
    }
    for (int i = 0; i < n2; i++)
    {
        m1[arr1[i]] += 1;
    }
    cout << "Number of elements in the union is " << m1.size() << endl;
    return 0;
}