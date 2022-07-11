#include <iostream>
#include <climits>
using namespace std;
int maxLoot(int values[], int n)
{
    int *dp = new int[n + 2];
    dp[n + 1] = 0;
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        dp[i] = max(dp[i + 1], values[i] + dp[i + 2]);
    }
    return dp[0];
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << maxLoot(arr, n);
    return 0;
}