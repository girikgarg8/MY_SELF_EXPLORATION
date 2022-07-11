#include <iostream>
#include <climits>
using namespace std;
class stack{
    int *data;
    int nextIndex;
    int capacity;
    public:
    stack(int totalsize){
        data=new int[totalsize];
        nextIndex=0;
        capacity=totalsize;
    }
    int size(){
        return nextIndex;
    }
    bool isEmpty(){
        return nextIndex==0;
    }
    void push(int element){
        if (nextIndex==capacity){
            cout << "Stack full" <<endl;
            return ;
        }       
        data[nextIndex]=element;
        nextIndex++;
    }
    int pop(){
        if (nextIndex==0){
            cout << "Stack is empty" <<endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }
    int top(){
        if (isEmpty()){
            cout << "Stack is empty" <<endl;
            return ;
        }
        return data[nextIndex-1];
    }
};
int main(){
    stack s1(100);
    s1.push(10);
    s1.push(20);
    s1.pop();
    return 0;
}
