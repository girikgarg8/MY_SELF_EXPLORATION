#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> printSubSequences(string s)
{
    vector<string> v2;
    if (s.size() == 0)
    {
        v2.push_back(" ");
        return v2;
    }
    v2 = printSubSequences(s.substr(1));
    int a = v2.size();
    for (int i = 0; i < a; i++)
    {
        v2.push_back(s[0] + v2[i]);
    }
    return v2;
}
int main()
{
    string s1 = "abcd";
    vector<string> v3 = printSubSequences(s1);
    for (int i = 0; i < v3.size(); i++)
    {
        cout << v3[i] << endl;
    }
    return 0;
}