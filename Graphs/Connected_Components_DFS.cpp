#include <iostream>
#include <map>
#include <list>
using namespace std;
class Graph
{
    map<int, list<int>> m1;

public:
    Graph()
    {
    }
    void addEdge(int u, int v, bool IsBiDirectional = true)
    {
        m1[u].push_back(v);
        if (IsBiDirectional == true)
        {
            m1[v].push_back(u);
        }
    }
    void DFSHelper(int node, map<int, bool> &visited)
    {       
        //Small calculation part
        cout << node << ",";
        visited[node] = true;
        list<int>::iterator i;
        //Recursive call
        for (i = m1[node].begin(); i != m1[node].end(); i++)
        {
            if (visited[*i] == false)
            {
                DFSHelper(*i, visited);
            }
        }
    }
    void DFS(int src)
    {   int numOfComponents=1;
        map<int, bool> visited;
        DFSHelper(src, visited);
        map<int, list<int> > :: iterator i;
        map <int,bool> :: iterator it;
        for (i=m1.begin();i!=m1.end();i++){
            if (visited[i->first]==false){
                cout <<endl;
                DFSHelper(i->first,visited);
                numOfComponents++;
            }
        }
        cout << endl<< "Number of connected components in the graph are " << numOfComponents <<endl;
    }
};
int main()
{
    Graph g1;
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.addEdge(0, 3);
    g1.addEdge(4,5);
    g1.addEdge(6,7);
    g1.DFS(0);
    return 0;
}