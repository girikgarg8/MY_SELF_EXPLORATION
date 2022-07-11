
#include <iostream>
#include <map>
#include <list>
#include <queue>
using namespace std;
template <class T>
class Graph
{
    map<T, list<T>> m1;
    map<T, int> visited;

public:
    Graph()
    {
    }
    void addEdge(T u, T v, bool isBidirectional = true)
    {
        m1[u].push_back(v);
        if (isBidirectional == true)
        {
            m1[v].push_back(u);
        }
    }
    bool CycleDetection(T src)
    { // Cycle Detection does not depend on source
        queue<T> q;
        map<T, T> parent;
        typename map<T, list<T>>::iterator i;
        typename list<T>::iterator it;
        for (i = m1.begin(); i != m1.end(); i++)
        {
            for (it = m1[i->first].begin(); it != m1[i->first].end(); it++)
            {
                visited[*it] == 0;
            }
        }
        q.push(src);
        visited[src] = 1;
        while (!q.empty())
        {
            T s = q.front();
            q.pop();
            visited[s] = 1;
            for (it = m1[s].begin(); it != m1[s].end(); it++)
            {
                if (*it != parent[s])
                {
                    q.push(*it);
                    parent[*it] = s;
                    visited[*it] = visited[*it] + 1;
                }
                if (visited[*it] > 1)
                {
                    return true;
                }
            }
        }
        return false;
    }
    void print()
    {
        cout << visited[2] << endl;
    }
};
int main()
{
    Graph<int> g1;
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.addEdge(3, 0);
    cout << g1.CycleDetection(0) << endl;
    return 0;
}