#include <iostream>
#include <stack>
using namespace std;
class newStack{
    stack <int> s1;
    int minEle;
    public:
    void getMin(){
        if (s1.empty()){
            cout << "Stack is empty\n";
        }
        else{
            cout << "Minimum element in the stack is" << minEle << "\n";
        }
    }
    void peek(){
        if (s1.empty()){
            cout << "Stack is empty";
            return ;
        }
        int t=s1.top();
        cout << "Top most element is:";
        //if t<minEle means minEle stores value of t
        (t<minEle)?cout << minEle :cout << t;
    }
    void pop(){
        if (s1.empty()){
            cout << "Stack is empty\n";
            return ;
        }
        cout << "Top most element removed:";
        int t=s1.top();
        s1.pop();
        if (t<minEle){
        cout << minEle << "\n";
        minEle=2*minEle-t;
        }
        else cout << t << "\n";
    }
    void push(int x){
        if (s1.empty()){
            minEle=x;
            s1.push(x);
            cout << "Number insrted:" << x << "\n";
            return ;
        }
        if (x<minEle){
            s1.push(2*x-minEle);
            minEle=x;
        }
        else s1.push(x);
        cout << "Number Inserted:" << x <<endl;
    }
};
int main()
{
    newStack s;
    s.push(3);
    s.push(5);
    s.getMin();
    s.push(2);
    s.push(1);
    s.getMin();
    s.pop();
    s.getMin();
    s.pop();
    s.peek();
    return 0;
}