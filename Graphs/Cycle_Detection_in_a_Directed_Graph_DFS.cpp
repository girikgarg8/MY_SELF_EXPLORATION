#include <iostream>
#include <list>
#include <map>
#include <stack>
using namespace std;
class Graph{
    map <int, list<int> > m1;
    map <int,int> parent;
    public:
        void addEdge(int u, int v, bool IsBiDirectional = false)
        {
            m1[u].push_back(v);
            if (IsBiDirectional == true)
            {
                m1[v].push_back(u);
            }
        }
        void DFSHelper(int s,map<int,int> &visited){
            visited[s]=1;
            list <int> :: iterator it;
            for (it=m1[s].begin();it!=m1[s].end();it++){
                cout << "Value of s is " << s << endl;
                cout << "Value of *it is" <<*it <<endl;
                cout << "Value of visited[*it] is" <<visited[*it] <<endl;
                if (visited[*it] == 1 && parent[*it]!=s)
                {
                    cout << "Cyclicity is present";
                    return ;
                }
                if (visited[*it] == (0))
                {
                    visited[*it] = 1;
                    parent[*it] = s;
                    DFSHelper(*it, visited);
                }
            }
            visited[s]=2;
        }
    void DFS(int src){
        map <int,int> visited;
        DFSHelper(src,visited);
    }
};
int main(){
    // Graph g1;
    // g1.addEdge(0,1);
    // g1.addEdge(1,2);
    // g1.addEdge(2,3);
    // g1.addEdge(3,4);
    // g1.addEdge(4,1);
    // g1.DFS(1); //Answer should be it is cyclic
    Graph g2;
    // g2.addEdge(0, 1);
    // g2.addEdge(1, 2);
    // g2.addEdge(2, 3);
    // g2.addEdge(3, 4); //flag of 2 means visited and out of stack, flag of 1 mens in stack and visited, flag of 0 means not visited
    // g2.addEdge(1,4); //Answer should be not cyclic
    Graph g3;
    g3.addEdge(0,2);
    g3.addEdge(2,3);
    g3.addEdge(2,4);
    g3.addEdge(4,5);
    g3.addEdge(0,1);
    g3.addEdge(1,5);
    g3.DFS(0);
    return 0;
}