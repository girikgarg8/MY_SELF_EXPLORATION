#include <iostream>
using namespace std;
int MaxProductSubArray(int arr[], int size)
{
    int max_till_index_i = 1;
    int min_till_index_i = 1;
    int flag = 0;  //for testing presence of positive and negative elements
    int flag1 = 0; //for testing presence of zero
    int finalMax = 1;
    int temp;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            max_till_index_i = 1;
            min_till_index_i = 1;
            continue;
        }
        temp = max_till_index_i;
        max_till_index_i = max(arr[i], max(min_till_index_i * arr[i], max_till_index_i * arr[i]));
        min_till_index_i = min(arr[i], max(temp * arr[i], min_till_index_i * arr[i]));
        if (max_till_index_i > finalMax)
        {
            finalMax = max_till_index_i;
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        return finalMax;
    }
    int x;
    if (flag == 0)
    {
        for (int x = 0; x < size; x++)
        {
            if (arr[x] < 0)
            {
                flag = (-1);
                break;
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            flag1 = 1;
        }
    }
    if (flag == (-1) && flag1 == 1)
    {
        return 0; //Case of both negatives and zeroes
    }
    else if (flag == 0 && flag1 == 1)
    {
        return 0; //Case of only zeroes
    }
    else if (flag == (-1) && flag1 == 0)
    { //Case of only negative number
        return arr[x];
    }
    return -999;
}
int main()
{
    int arr[] = {-3, 2, -4, 6, 0, -8, 5};
    int n = sizeof(arr) / sizeof(int);
    int arr1[] = {0, 0, -20, 0, 0};
    int n1 = sizeof(arr1) / sizeof(int);
    int arr2[] = {-20};
    int n2 = sizeof(arr2) / sizeof(int);
    int arr3[] = {0, 0, 0, 0};
    int n3 = sizeof(arr3) / sizeof(int);
    cout << "The maximum product is " << MaxProductSubArray(arr, n) << endl;
    cout << "The maximum product is " << MaxProductSubArray(arr1, n1) << endl;
    cout << "The maximum product is " << MaxProductSubArray(arr2, n2) << endl;
    cout << "The maximum product is " << MaxProductSubArray(arr3, n3) << endl;
    return 0;
    //Comment out first two function calls for seeing third and fourth call result
}