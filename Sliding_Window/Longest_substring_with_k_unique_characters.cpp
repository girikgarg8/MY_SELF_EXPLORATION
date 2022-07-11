#include <iostream>
#include <map>
using namespace std;
int LongestSubstring(string s, int k)
{
    int i = 0;
    int j = 0;
    int maximum = 0;
    int size = s.size();
    map<char, int> m1; //for storing the count of times each alphabet occurs in a sliding window
    while (j < size)
    {
        m1[s[j]] += 1;
        if (m1.size() < k)
        {
            j++;
        }
        if (m1.size() == k)
        {
            maximum = max(maximum, j - i + 1);
            j++;
        }
        if (m1.size() > k)
        {
            while (m1.size() > k)
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
    }
    return maximum;
}
int main()
{
    string s1 = "aabacbebebe";
    cout << "The maximum lenght of such a substring is" << LongestSubstring(s1, 3) << endl;
    return 0;
}