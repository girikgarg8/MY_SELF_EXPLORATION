//Push operation is costly
#include <iostream>
#include <queue>
using namespace std;
class Stack{
    queue<int> q1,q2;
    int curr_size;
    public:
    Stack(){
        curr_size=0;
    }
    void push(int x){
        curr_size++;
        q2.push(x);
        while (!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        //swap the names of two queues
        queue <int> q=q1;
        q1=q2;
        q2=q;
    }
    void pop(){
        if (q1.empty()){
            return ;
        }
        q1.pop();
        curr_size--;
    }
    int top(){
        if (q1.empty()){
            return -1;
        }
        return q1.front();
    }
    int size(){
        return curr_size;
    }
};
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "current size: " << s.size()<< endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << "current size: " << s.size()<< endl;
    return 0;
}
//Pop operation is costly
/*
class Stack{
    queue <int> q1,q2;
    int curr_size;
    public:
    Stack(){
        curr_size=0;
    }
    void pop(){
        if (q1.empty()){
            return ;
        }
        while (q1.size()!=1){
            q1.push(q1.front());
            q1.pop();
        }
        q1.pop();
        curr_size--;
        queue <int> q=q1;
        q1=q2;
        q2=q;
    }
    void push(int x){
        q1.push(x);
        curr_size++;
    }
    int top(){
        if (q1.empty()){
            return -1;
        }
        while (q1.size()!=1){
        q2.push(q1.front());
        q1.pop();
        }
        int temp=q1.front();
        q1.pop();
        q2.push(temp);
        queue <int> q;
        q1=q2;
        q2=q;
        return temp;
    }
    int size(){
        return curr_size;
    }
}

//Implemenetation using single queue
class Stack{
    queue<int>q;
    public:
    void push(int val){
        int s=q.size();
        q.push(val);
        for (int i=0;i<s;i++){
            q.push(q.front());
            q.pop();
        }
    }
    void pop(){
        if (q.empty()){
            cout << "Empty queue" <<endl;
        }
        else q.pop();
    }
    int top(){
        return q.empty()?-1:q.front();
    }
    bool empty(){
        return q.empty();
    }
    };
*/