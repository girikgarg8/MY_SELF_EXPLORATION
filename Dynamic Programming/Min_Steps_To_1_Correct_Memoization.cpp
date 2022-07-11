#include <iostream>
#include <climits>
#include <cmath>
using namespace std;
int Min_Steps_to_1_Memoization(int n, int dp[])
{
    int x = INT_MAX, y = INT_MAX;
    //Base Case
    if (n == 1)
    {
        return 0;
    }
    //Small Calculation part
    if (dp[n] != 0)
    {
        return dp[n];
    }
    //Recursive function calls
    int z = Min_Steps_to_1_Memoization(n - 1, dp);
    if (n % 3 == 0)
    {
        x = Min_Steps_to_1_Memoization(n / 3, dp);
    }
    if (n % 2 == 0)
    {
        y = Min_Steps_to_1_Memoization(n /2, dp);
    }
    dp[n] = min(x, min(y, z)) + 1;
    return dp[n];
}
int main()
{
    int dp[100] = {0};
    int n;
    cout << "Enter the number " << endl;
    cin >> n;
    int x = Min_Steps_to_1_Memoization(n, dp);
    cout << x << endl;
    return 0;
}