#include <bits/stdc++.h>
using namespace std;
vector<int> computeLPSArray(string str)
{ //This function returns the LPS vector for given str
    int m = str.length();
    vector<int> lps(m); //Making the size of this array as m
    lps[0] = 0;
    int i = 0;
    int j = 1;
    while (j < m)
    {
        if (str[i] == str[j])
        {
            lps[j] = i + 1;
            i++;
            j++;
        }
        else
        {
            if (i == 0)
            {
                lps[j] = 0;
                j++;
            }
            else
            {
                i = lps[i - 1];
            }
        }
    }
    return lps;
}
int getMinChar(string str)
{
    string revStr = str;
    reverse(revStr.begin(), revStr.end());
    string concat = str + "$" + revStr;
    vector<int> lps = computeLPSArray(concat);
    return (str.length() - lps.back());
}
int main()
{
    string str = "AACECAAAA";
    cout << getMinChar(str);
    return 0;
}