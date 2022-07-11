#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int PalindromeSubstring(string s)
{
    int n = s.length();
    int start = 0; //starting index of the longest palindromic string
    bool dp[n][n];
    int count = 0;
    memset(dp, 0, sizeof(dp));
    int maxLength = 1; //for single size plaindrome eg 'a'
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = true;
        count++;
    }
    queue<int> q1;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            dp[i][i + 1] = true;
            count++;
        }
    }
    for (int k = 3; k <= n; ++k)
    { //k denotes length of the substring
        for (int i = 0; i < (n - k + 1); ++i)
        {                      //not i<n,number of words of length k will be n-k, try dry running this on k=4 and n=5
            int j = i + k - 1; //end index, this can be obtained
            if (s[i] == s[j] && dp[i + 1][j - 1] == true)
            {
                count++;
            }
        }
    }
    return count;
}
int main()
{
    string s = "aab";
    cout << PalindromeSubstring(s);
    return 0;
}