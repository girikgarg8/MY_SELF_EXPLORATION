#include <iostream>
#include <climits>
#include <cmath>
using namespace std;
int MinStepsDP(int n)
{
    int dp[100] = {0};
    int x = INT_MAX, y = INT_MAX, z = INT_MAX;
    if (n == 1)
    {
        dp[n] = 0;
    }
    for (int i = 2; i <= n; i++)
    {
        if (n % 2 == 0)
        {
            x = dp[i / 2];
        }
        if (n % 3 == 0)
        {
            y = dp[i / 3];
        }
        z = dp[i - 1];
        dp[i] = min(x, min(y, z)) + 1;
    }
    return dp[n];
}
int main()
{
    int n;
    cout << "Enter the number" << endl;
    cin >> n;
    int x = MinStepsDP(n);
    cout << x << endl;
    return 0;
}
