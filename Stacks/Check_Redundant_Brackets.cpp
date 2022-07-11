#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool checkRedundantBrackets(string s1)
{
    stack<char> s;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] != ')')
        {
            s.push(s1[i]);
        }
        else if (s1[i] == ')')
        {
            bool flag = true;
            while (s.top() != '(')
            {
                if (s.top() == '+' || s.top() == '-' || s.top() == '*' || s.top() == '/')
                {
                    flag = false;
                }
                s.pop();
            }
            s.pop();
            if (flag == true)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    string input;
    cin >> input;
    cout << checkRedundantBrackets(input);
    return 0;
}