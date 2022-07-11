#include <iostream>
#include <vector>
using namespace std;
class NStack{
    int n,s;
    vector <int> data;
    vector <int> top;
    vector <int> next;
    int freeStart;
    public:
    NStack(int n,int s){
        this->s=s;
        this->n=n;
        data=vector <int> (n);
        top=vector <int> (s);
        next=vector <int> (n);
        for (int i=0;i<n-1;i++){
            next[i]=i+1;
        }
        next[n-1]=-1;
        for (int i=0;i<s;i++){
            top[i]=-1;
        }
        freeStart=0;
    }
    bool push(int x,int m){
        if (freeStart==-1){
            return false;
        }
        int index=freeStart;
        freeStart=next[freeStart];
        data[index]=x;
        next[x]=top[m-1];
        top[m-1]=index;
        return true;
    }
    int pop(int m){
        if (top[m-1]==-1){
            return -1;
        }
        int topIndex=top[m-1];
        int nxt=next[topIndex];
        top[m-1]=nxt;
        next[topIndex]=freeStart;
        freeStart=topIndex;
        return data[topIndex];
    }
};
int main(){
    NStack n1(3,6);
    n1.push(10,1);
    n1.push(20, 1);
    n1.push(30,2);
    n1.pop(1);
    n1.pop(2);
    return 0;
}