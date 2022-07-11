#include <iostream>
#include <list>
using namespace std;
class Graph
{          //Edge list implementation
    int V; //number of vertices
    list<pair<int, int>> edges;
    int *parent;

public:
    Graph(int V) //As we know number of vertices, we can makean array. In case we don't know number of vertices, we would make map.
    {
        this->V = V;
        parent = new int[V];
        for (int i = 0; i < V; i++)
        {
            parent[i] = (-1);
        }
    }
    void addEdge(int a, int b)
    { //Graph is undirected
        edges.push_back(make_pair(a, b));
    }
    int find(int x)
    {
        if (parent[x] == (-1))
        {
            return x;
        }
        return find(parent[x]);
    }
    void union_set(int a, int b)
    {
        int s1 = find(a);
        int s2 = find(b);
        // if (s1==s2){
        //     cout << "Cycle is detected in the given undirected graph" ;
        // } This is wrong. because if user eneters 4,4 it would return true
        if (s1 != s2)
        {
            parent[s1] = s2;
        }
    }
    bool contains_cycle()
    { //No parameters to this function
        //We will actually make a tree in case parents of any two edges in the graph are not same

        //Traversing over all edges in the graph
        for (auto i : edges)
        {
            int a = i.first;
            int b = i.second;
            int s1 = find(a);
            int s2 = find(b);
            if (s1 != s2)
            { //Means parents are not equal, connect an edge in the tree, call the union set function
                union_set(a, b);
            }
            else
            {
                cout << "Same parents " << s1 << " and " << s2 << " are present";
                return true;
            }
        }
        return false;
    }
};
int main()
{
    Graph g1(4);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);
    g1.addEdge(4, 2);
    cout << g1.contains_cycle();
    return 0;
}