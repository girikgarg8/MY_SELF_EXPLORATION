#include <iostream>
#include <list>
#include <map>
#include <queue>
using namespace std;
template <typename T>
class Graph
{
    map<T, list<T>> m1;
    map<T, bool> visited;
    map<T, int> distance;
    queue<T> q1;

public:
    Graph()
    {
    }
    void addEdge(T x, T u, bool isBidirectional = true)
    {
        m1[x].push_back(u);
        if (isBidirectional)
        {
            m1[u].push_back(x);
        }
    }
    void BFS_SSSP(T src)
    {
        distance[src] = 0;
        q1.push(src);
        visited[src] = true;
        while (!q1.empty())
        {
            T r = q1.front();
            q1.pop();
            typename list<int>::iterator i;
            for (i = m1[r].begin(); i != m1[r].end(); i++)
            {
                if (visited[*i] == false)
                {
                    q1.push(*i);
                    visited[*i] = true;
                    distance[*i] = distance[r] + 1;
                }
            }
        }
        typename map<T, int>::iterator it;
        for (it = distance.begin(); it != distance.end(); it++)
        {
            cout << "Distance of " << src << "from " << it->first << " is " << it->second << endl;
        }
    }
};
int main()
{
    Graph<int> g1;
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 4);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);
    g1.addEdge(4, 0);
    g1.addEdge(3, 5);
    g1.BFS_SSSP(0);
    return 0;
}
