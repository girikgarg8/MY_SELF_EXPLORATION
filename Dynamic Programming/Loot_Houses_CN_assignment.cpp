#include <iostream>
#include <climits>
using namespace std;
int maxLoot(int values[], int n, int i, int *dp)
{
    if (dp[i] != -1)
    {
        return dp[i];
    }
    if (i >= n)
    {
        return 0;
    }
    int a = values[i] + maxLoot(values, n, i + 2, dp);
    int b = maxLoot(values, n, i + 1, dp);
    int ans = max(a, b);
    return dp[i] = ans;
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
    int *dp = new int[n + 2];
    for (int i = 0; i <= (n + 1); i++)
    {
        dp[i] = (-1);
    }
    cout << maxLoot(arr, n, 0, dp);
    return 0;
}