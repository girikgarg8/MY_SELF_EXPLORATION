#include <iostream>
#include <stack>
using namespace std;
void sortedInsert(stack <int> &s,int element){
    if (s.empty() || element>s.top()){
        s.push(element);
        return ;
    }
    int top=s.top();
    s.pop();
    sortedInsert(s,element);
    s.push(top);
}
void sortStack(stack<int> &s){
    if (s.empty()){
        return ;
    }
    int top=s.top();
    s.pop();
    //Recursion for remaining elements in the stack
    sortStack(s);
    //INsert the popped element back in the sorted stack
    sortedInsert(s,top);
}
int main(){
    stack <int> s1;
    s1.push(10);
    s1.push(19);
    s1.push(13);
    s1.push(18);
    sortStack(s1);
    while (!s1.empty()){
        cout << s1.top() << " ";
        s1.pop();
    }
    return 0;
}