#include <iostream>
#include <map>
#include <list>
using namespace std;
class Graph{
    map <int, list <int> > m1;
    public:
    Graph(){

    }
    void addEdge(int u, int v, bool IsBiDirectional=true){
        m1[u].push_back(v);
        if (IsBiDirectional==true){
            m1[v].push_back(u);
        }
    }
    void DFSHelper(int node,map<int,bool> & visited){
        //Small calculation part
        cout << node << "," ;
        visited[node]=true;
        list <int> ::iterator i;
        //Recursive call
        for (i=m1[node].begin();i!=m1[node].end();i++){
            if (visited[*i]==false){
                DFSHelper(*i,visited);
        }
    }
    }
    void DFS(int src){
        map<int,bool> visited;
        DFSHelper(src,visited);
    }
};
int main(){
    Graph g1;
    g1.addEdge(0,1);
    g1.addEdge(1,2);
    g1.addEdge(2,4);
    g1.addEdge(2,3);
    g1.addEdge(3,4);
    g1.addEdge(3,5);
    g1.addEdge(0,4);
    g1.DFS(0);
    return 0;
}