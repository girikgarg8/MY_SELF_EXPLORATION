#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
int MinCount(int dp[], int n)
{
    int ans = n;
    if (sqrt(n) == (float)(sqrt(n)))
    {
        dp[n] = 1;
    }
    for (int i = 1; i <= sqrt(n); i++)
    {
        dp[i] = MinCount(dp, n - i * i) + 1;
        ans = min(n, dp[i]);
    }
    return ans;
}
int main()
{
    int dp[100] = {-1};
    int num;
    cout << "Enter the number" << endl;
    cin >> num;
    cout << MinCount(dp, num);
    return 0;
}