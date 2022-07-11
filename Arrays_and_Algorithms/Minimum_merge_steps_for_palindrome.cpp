#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 5, 5, 10, 1};
    int i = 0;
    int n = sizeof(arr) / sizeof(int);
    int j = n - 1;
    int ans = 0;
    while (i <= j)
    {
        if (arr[i] == arr[j])
        {
            i++;
            j--;
        }
        else if (arr[i] > arr[j])
        {
            j--;
            arr[j] = arr[j] + arr[j + 1];
            ans++;
        }
        else if (arr[i] < arr[j])
        {
            i++;
            arr[i] = arr[i] + arr[i - 1];
            ans++;
        }
    }
    cout << "Minmum merge operations required are " << ans;
    return 0;
}