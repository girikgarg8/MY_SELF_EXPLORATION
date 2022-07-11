#include <iostream>
using namespace std;
class Queue{
    int *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;
    public:
    Queue(int s){
        data=new int[s];
        nextIndex=0;
        firstIndex=-1;
        size=0;
        capacity=s;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }
    void push(int element){
        if (size==capacity){
            cout << "Queue full " <<endl;
            return ;
        }
        data[nextIndex]=element;
        nextIndex=(nextIndex+1)%capacity;
        if (firstIndex==-1){
            firstIndex=0;
        }
        size++;
    }
    int front(){
        if (isEmpty()){
            cout << "Queue is empty!" <<endl;
            return 0;
        }
        return data[firstIndex];
    }
    int pop(){
        if (isEmpty()){
            cout << "Queue is empty" <<endl;
            return 0;
        }
        int ans=data[firstIndex];
        firstIndex=(firstIndex+1)%capacity;
        size--;
        //optional step
        if (size==0){
            firstIndex=-1;
            nextIndex=0;
        }
    }
};