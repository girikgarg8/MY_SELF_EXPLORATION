#include <iostream>
#include <map>
using namespace std;
int LongestSubstring(string s)
{
    map<char, int> m1; // to store the frequency of each character in the wndow
    int i = 0;
    int j = 0;
    int maximum = 0;
    int size = s.size();
    while (j < size)
    {
        m1[s[j]] += 1;
        if (m1.size() < (j - i + 1))
        { //  Start removing the duplicate characters
            while (m1.size() < (j - i + 1))
            {
                m1[s[i]] -= 1;
                if (m1[s[i]] == 0)
                {
                    m1.erase(s[i]);
                }
                i++;
            }
            j++;
        }
        if (m1.size() == (j - i + 1))
        {
            maximum = max(maximum, j - i + 1);
            j++;
        }
    }
    return maximum;
}
int main()
{
    string s1 = "pwwkew";
    cout << "Maximum length of such a possible substring is" << LongestSubstring(s1) << endl;
    string s2 = "aaabbccdcdefghi";
    cout << "Maximum length of such a possible substring is" << LongestSubstring(s2) << endl;
    return 0;
}