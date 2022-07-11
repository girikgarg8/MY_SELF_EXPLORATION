#include <bits/stdc++.h>
using namespace std;
string removeAdjacentDuplicates(string str)
{
    string a = "";
    if (str.length() == 0)
    {
        return str;
    }
    int i = 0;
    int flag = 0;
    for (i = 0; i < str.size(); i++)
    {
        if (str[i] != str[i + 1] && str[i + 1] != 0)
        {
            a = a + str[i];
            flag = 1;
            a = a + removeAdjacentDuplicates(str.substr(i + 1));
            break;
        }
    }
    if (flag == 0)
    {
        a = a + str[i - 1];
    }
    return a;
}
int main()
{
    string s = "aabaa";
    string t = "aabbcdef";
    cout << removeAdjacentDuplicates(s) << endl;
    cout << removeAdjacentDuplicates(t) << endl;
    return 0;
}