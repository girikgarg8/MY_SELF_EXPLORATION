#include <iostream>
using namespace std;
int EditDistance(string s, string t)
{
    //Base Case
    if (t.size() == 0)
    {
        return s.size();
    }
    if (s.size() == 0)
    {
        return t.size();
    }
    int x, y, z, min_num;
    //Recursive Case
    if (s[0] == t[0])
    {
        return EditDistance(s.substr(1), t.substr(1));
    }
    else
    {
        x = 1 + EditDistance(s.substr(1), t);
        y = 1 + EditDistance(s, t.substr(1));
        z = 1 + EditDistance(s.substr(1), t.substr(1));
    }
    min_num = min(x, min(y, z));
    return min_num;
}
int main()
{
    string s1, s2;
    cout << "Enter the two strings" << endl;
    cin >> s1 >> s2;
    cout << EditDistance(s1, s2) << endl;
    return 0;
}