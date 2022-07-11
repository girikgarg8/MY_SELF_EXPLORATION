#include <bits/stdc++.h> //O(N*M) solution where N is number of strings and M is length of the longets string in the given array
using namespace std;
string findCommonPrefix(string str1, string str2)
{
    string result = "";
    int n1 = str1.length();
    int n2 = str2.length();
    for (int i = 0, j = 0; i <= n1 - 1 && j <= n2 - 1; i++, j++)
    {
        if (str1[i] != str2[j])
        {
            break;
        }
        result.push_back(str1[i]);
    }
    return result;
}
string longestCommonPrefix(vector<string> &arr, int n)
{
    string prefix = arr[0]; //first substring
    for (int i = 1; i <= n - 1; i++)
    {
        prefix = findCommonPrefix(prefix, arr[i]);
    }
    return prefix;
}
int main()
{
    vector<string> arr = {"geeksforgeeks", "geeks",
                          "geek", "geezer"};
    int n = arr.size();

    string ans = longestCommonPrefix(arr, n);

    if (ans.length())
        cout << ans << endl;
    else
        printf("There is no common prefix");

    return (0);
}