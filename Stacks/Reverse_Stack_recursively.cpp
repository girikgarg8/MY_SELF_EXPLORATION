#include <iostream>
#include <stack>
using namespace std;
void insertAtBottom(stack<int> &s1, int element)
{
    if (s1.empty())
    {
        s1.push(element);
        return;
    }
    int top = s1.top();
    s1.pop();
    insertAtBottom(s1, element);
    s1.push(top);
}
void ReverseStack(stack<int> &s1)
{
    //Base Case
    if (s1.size() <= 1)
    {
        return;
    }
    int a = s1.top();
    s1.pop();
    ReverseStack(s1);
    insertAtBottom(s1, a);
}
int main()
{
    stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(10);
    stack<int> s2;
    ReverseStack(s1);
    while (!s1.empty())
    {
        int a = s1.top();
        cout << a << " ";
        s1.pop();
    }
    return 0;
}