#include <iostream>
#include <queue>
using namespace std;
int main(){
    priority_queue <int,vector<int> , greater<int> > p1;
    p1.push(6);
    p1.push(7);
    p1.push(2);
    p1.push(1);
    cout << "Size of priority queue is " << p1.size() << endl;
    cout << "Top element in the priority queue is " << p1.top() << endl;
    while (!p1.empty())
    {
        cout << p1.top() << endl;
        p1.pop();
    }
    return 0;
}