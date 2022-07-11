#include <iostream>
using namespace std;
int main()
{
    string s1 = "abacd";
    string temp = s1 + s1;
    string s2 = "cdaba";
    if ((temp.find(s2)) != string::npos)
    {
        cout << " Given string is rotation of first string";
    }
    else
    {
        cout << "Given string is not a rotation of first string";
    }
    return 0;
}