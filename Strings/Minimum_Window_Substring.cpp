#include <bits/stdc++.h>
using namespace std;
string minWindow(string s, string t)
{
    int i = 0;
    int j = 0;
    int mn = INT_MAX;
    unordered_map<char, int> m;
    string ans = "";
    int u = t.size();
    for (int i = 0; i < u; i++)
    {
        m[t[i]]++;
    }
    int count = m.size(); //count denotes number of characters which have not been found even once in the string
    int size = s.size();
    while (j < size)
    {
        if (m.find(s[j]) != m.end())
        {
            m[s[j]]--;
            if (m[s[j]] == 0)
            {
                count--;
            }
        }
        if (count == 0)
        {
            while (count == 0)
            {
                if (m.find(s[i]) == m.end())
                {
                    i++;
                }
                else
                {
                    m[s[i]]++;
                    if (m[s[i]] > 0)
                    {
                        count++;
                    }
                    if (count > 0)
                    {
                        if ((j - i + 1) < mn)
                        {
                            mn = j - i + 1;
                            ans = s.substr(i, mn);
                        }
                    }
                    i++;
                }
            }
        }
        j++;
    }
    return ans;
}
int main()
{
    string s = "ABHDAXCVBAGTXATYCB";
    string t = "ABC";
    cout << minWindow(s, t) << endl;
    return 0;
}