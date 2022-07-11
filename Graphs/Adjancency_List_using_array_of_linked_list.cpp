#include <bits/stdc++.h>
using namespace std;
class Graph{
    int V;
    list <int> *arr;
    public:
    Graph(int a){
        V=a;
        arr=new list <int> [V];
    }
    void addEdge(int a,int b, bool isBidirectional=true){
        arr[a].push_back(b);
        if (isBidirectional){
            arr[b].push_back(a);
        }
    }
    void findNeighbours(int src){
        for (auto v:arr[src]){
            cout << v<< " ";
    }
  }
};
int main(){
    Graph g1(5);
    g1.addEdge(0,1);
    g1.addEdge(1,2);
    g1.addEdge(2,3);
    g1.addEdge(3,4);
    g1.addEdge(4,1);
    g1.findNeighbours(4);
    return 0;
}

