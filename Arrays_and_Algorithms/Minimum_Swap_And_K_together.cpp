#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int arr[] = {2, 1, 5, 6, 3};
    int n = sizeof(arr) / sizeof(int);
    int k = 3; //given number
    int i = 0;
    int j = 0;
    int count = 0;
    for (int u = 0; u < n; u++)
    {
        if (arr[u] <= k)
        {
            count++;
        }
    }
    int count1 = 0;
    int finalCount = INT_MAX;
    //count represenst number of elements less than or equal to k
    while (j < n)
    {
        if (arr[j] > k)
        {
            count1++;
        }
        if ((j - i + 1) < count)
        {
            j++;
        }
        else if ((j - i + 1) == count)
        {
            finalCount = min(finalCount, count1);
            j++;
            if (arr[i] > k)
            {
                count1--;
            }
            if (arr[j] > k)
            {
                count1++;
            }
            i++;
        }
    }
    cout << "Minimum number of swaps required are " << finalCount << endl;
    return 0;
}