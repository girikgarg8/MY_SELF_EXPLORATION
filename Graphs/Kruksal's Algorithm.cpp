#include <iostream>
//Kruskal's algorithm uses the Disjoint set Union(DSU) data structure
#include <algorithm>
#include <vector>
using namespace std;
class DSU
{
    int V;
    int *parent;
    int *rank;

public:
    DSU(int V)
    {
        this->V = V;
        parent = new int[V];
        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
        }
        rank = new int[V];
        for (int i = 0; i < V; i++)
        {
            rank[i] = 1;
        }
    }
    int findParent(int a)
    {
        if (parent[a] == (a))
        {
            return a;
        }
        return parent[a] = findParent(parent[a]); //Path compression step
    }
    void union_sort(int a, int b)
    {
        int s1 = findParent(a);
        int s2 = findParent(b);
        if (s1 != s2)
        {
            if (rank[s1] > rank[s2])
            {
                parent[s2] = s1;
                rank[s1] += rank[s2]; //Union by rank
            }
            else
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
        }
    }
};
class Graph
{
    int V;
    vector<vector<int>> edgesList; // vector of vectors eg. 1 2 3 would mean edge between 1 and 2 with weight 3
public:
    Graph(int V)
    {
        this->V = V;
    }
    void addEdge(int vertex1, int vertex2, int weight)
    {
        edgesList.push_back({weight, vertex1, vertex2});
    } //We are pushing weight as the first element in the vector so that sorting can take place on the basis of weight
    //Otherwise we would have to use a comparator function
    int kruksal_mst()
    { //This would return the minimum cost in MST
        DSU d1(V);
        sort(edgesList.begin(), edgesList.end());
        int ans = 0; //Initiliasing answer as 0
        //Iterating over list of edges
        for (auto j : edgesList)
        {
            int weight = j[0];
            int firstNode = j[1];
            int secondNode = j[2];
            cout << "Weight is " << j[0] << endl;
            cout << "First Node is " << j[1] << endl;
            cout << "Second Node is " << j[2] << endl;
            cout << "Parent of first node is " << d1.findParent(firstNode) << endl;
            cout << "Parent of second node is " << d1.findParent(secondNode) << endl;
            cout << "Answer is " << ans << endl;
            //Take the edge and make a parent relation if their superParents are not equal
            if (d1.findParent(firstNode) != d1.findParent(secondNode))
            {
                cout << "Here" << endl;
                d1.union_sort(firstNode, secondNode);
                // d1.union_sort(s1,s2); //In Union_Sort function, super-parent will be found, so I can pass the nodes here
                ans += weight; //As the two nodes are not in same set, we can connect them and thus ans will be incremented by edge weight
            }
        }
        return ans;
    }
};
int main()
{
    Graph g1(5);
    g1.addEdge(1, 2, 1);
    g1.addEdge(1, 3, 2);
    g1.addEdge(3, 4, 3);
    g1.addEdge(2, 3, 2);
    g1.addEdge(1, 4, 2);
    cout << g1.kruksal_mst() << endl;
    return 0;
}