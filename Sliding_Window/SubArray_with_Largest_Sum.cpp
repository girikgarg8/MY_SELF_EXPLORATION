#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int arr[] = {2, 5, 1, 8, 2, 9, 1};
    int size = sizeof(arr) / sizeof(int);
    int sizeOfSubArray = 3; //this would be given in input
    int i = 0;
    int j = sizeOfSubArray - 1;
    int sum = 0;
    int finalAnswer = INT_MIN;
    for (int u = i; u <= j; u++)
    {
        sum += arr[u];
    }
    for (int x = 0; j < size; x++)
    {
        if (sum > finalAnswer)
        {
            finalAnswer = sum;
        }
        cout << "Value of sum is " << sum << endl;
        sum -= arr[i];
        i++;
        j++;
        sum += arr[j];
    }
    cout << "The maximum sum is " << finalAnswer << endl;
    return 0;
}