#include <iostream>
#include <stack>
using namespace std;
void reverseStack(stack <int> &s1, stack<int> &s2){
    //Base Case
    if (s1.size()<=1){
        return ;
    }
    int lastElement=s1.top();
    s1.pop();
    reverseStack(s1,s2);
    while (!s1.empty()){
        int a=s1.top();
        s1.pop();
        s2.push(a);
    }
    s2.push(lastElement);
    while(!s2.empty()){
        int a=s2.top();
        s2.pop();
        s1.push(a);
    }
}
int main(){
    stack <int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(10);
    stack <int> s2;
    reverseStack(s1,s2);
    while (!s1.empty()){
        int a=s1.top();
        cout << a << " ";
        s1.pop();
    }
    return 0;
}