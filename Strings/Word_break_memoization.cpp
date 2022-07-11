
#include <iostream>
#include <unordered_map> //storing the dictionary words in an unordered map
using namespace std;
bool checkPartition(string s, int pos, unordered_map<string, bool> &s1, int *dp)
{
    if (pos == s.size())
    {
        return true;
    }
    if (dp[pos] != (-1))
    {
        return dp[pos];
    }
    for (int i = pos; i <= s.size(); i++)
    {
        if ((s1.find(s.substr(pos, i - pos + 1)) != s1.end()) && checkPartition(s.substr(i + 1), i + 1, s1, dp))
        {
            dp[pos] = 1;
            return true;
        }
    }
    return dp[pos] = false;
}
int main()
{
    unordered_map<string, bool> dict;
    dict["i"] = 1;
    dict["like"] = 1;
    dict["sam"] = 1;
    dict["sung"] = 1;
    dict["samsung"] = 1;
    dict["mobile"] = 1;
    dict["ice"] = 1;
    dict["cream"] = 1;
    dict["icecream"] = 1;
    dict["man"] = 1;
    dict["go"] = 1;
    dict["mango"] = 1;
    string a = "ilikie";
    int *dp = new int[a.size() + 1];
    for (int i = 0; i <= a.size(); i++)
    {
        dp[i] = -1;
    }
    cout << checkPartition(a, 0, dict, dp);
    return 0;
}