#include <iostream>
#include <list>
#include <map>
#include <queue>
using namespace std;
template <typename T>
class Graph
{
    map<T, list<T>> m1;

public:
    Graph()
    {
    }
    void addEdge(T x, T y, bool isBiDirectional = true)
    {
        m1[x].push_back(y);
        if (isBiDirectional == true)
        {
            m1[y].push_back(x);
        }
    }
    void BFS(T src)
    {
        queue<T> q1;
        map<T, bool> visited; //By default, all values are 0(i.e. false)
        q1.push(src);
        visited[src] = true;
        while (!q1.empty())
        {
            src = q1.front();
            cout << q1.front() << " ";
            q1.pop();
            //For neighbours of this node, we will check in the linked list
            typename list<T>::iterator i;
            for (i = m1[src].begin(); i != m1[src].end(); i++)
            {
                if (visited[*i] == false)
                {
                    q1.push(*i);
                    visited[*i] = true;
                }
            }
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
    g1.addEdge(4, 0);
    g1.addEdge(3, 5);
    g1.BFS(0);
    cout << endl;
    g1.BFS(3);
    return 0;
}