#include <iostream>
#include <stack>
using namespace std;
class Queue{
    //by making the enqueue operation costlier
    stack <int> s1;
    stack <int> s2;
    public:
    int dequeue(){
        if (s1.empty()){
            cout << "Stack is empty" <<endl;
            return -1;
        }
        else{
            int a=s1.top();
            s1.pop();
        }
        return a;
    }
    void enqueue(int x){
     while (!s1.empty()){
         s2.push(s1.top());
         s1.pop();
     }
     s1.push(x);
    while (!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }   
    }
};
int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
 
    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';
 
    return 0;
}
/*
//making dequeue operation costlier
#include <iostream>
#include <stack>
using namespace std;
class Queue{
    stack <int> s1;
    stack <int> s2;
    public:
    void enqueue(int x){
        s1.push(x);
    }
    int dequeue(){
        if (s1.empty() && s2.empty()){
            cout << "Queue is empty";
            return -1;
        }
        else{
           while (!s1.empty()){
               s2.push(s1.top());
               s1.pop();
           } 
        }
        int b=s2.top();
        s2.pop();
        return b;
    }
};
int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';
 
    return 0;
}


*/