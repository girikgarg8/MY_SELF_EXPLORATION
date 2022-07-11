#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
vector<int> removeDuplicates(int arr[], int n)
{
    vector<int> answerArray;
    unordered_map<int, bool> seen;
    for (int i = 0; i < n; i++)
    {
        if (seen.count(arr[i]) == 0)
        {
            seen[arr[i]] = true;
            answerArray.push_back(arr[i]);
        }
    }
    return answerArray;
}
int main()
{
    cout << "Enter the size of array" << endl;
    int num;
    cin >> num;
    cout << "Enter the elements of the array" << endl;
    int *arr = new int[num];
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    int x = sizeof(arr) / sizeof(int);
    vector<int> v1 = removeDuplicates(arr, num);
    cout << "Elements obtained are " << endl;
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << endl;
    }
    delete[] arr;
    return 0;
