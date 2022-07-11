#include <iostream>
#include <list>
#include <queue>
#include <climits>
#include <map>
using namespace std;
class Graph
{
    map<int, list<pair<int, int>>> m1;
    map<int, int> distance;
    map<int, int> parent;
    map<int, int> allElements;

public:
    void addEdge(int x, int y, int w, bool isBidirectional = true)
    {
        m1[x].push_back(make_pair(y, w));
        allElements[x] = x;
        allElements[y] = y;
        if (isBidirectional == true)
        {
            m1[y].push_back(make_pair(x, w));
        }
    }

private:
    int CountNumberOfVertices()
    {
        int count = 0;
        map<int, int>::iterator i;
        for (i = allElements.begin(); i != allElements.end(); i++)
        {
            count++;
        }
        return count;
    }
    void print(int src)
    {
        // map<int, list<pair<int, int>>>::iterator i;
        map<int, int>::iterator i;
        for (i = allElements.begin(); i != allElements.end(); i++)
        {
            cout << "Distance of " << src << "from" << i->first << " is " << distance[i->first] << endl;
        }
    }

public:
    void printAllElements()
    {
        map<int, int>::iterator i;
        for (i = allElements.begin(); i != allElements.end(); i++)
        {
            cout << allElements[i->first] << endl;
        }
    }

public:
    void BellManFord_Algorithm(int src)
    {
        queue<int> q1;
        int count = CountNumberOfVertices();
        list<pair<int, int>>::iterator it1;
        map<int, int>::iterator it;
        for (it = allElements.begin(); it != allElements.end(); it++)
        {
            distance[it->first] = INT_MAX;
        }
        for (int i = 0; i < count - 1; i++)
        {
            distance[src] = 0;
            q1.push(src);
            while (!q1.empty())
            {
                int SourceNode = q1.front();
                q1.pop();
                int DistFromSourceNode = distance[SourceNode];
                for (it1 = m1[SourceNode].begin(); it1 != m1[SourceNode].end() && (*it1).first != parent[SourceNode]; it1++)
                {
                    pair<int, int> p1 = *it1;
                    int EdgeLength = p1.second;
                    int currentNode = p1.first;
                    q1.push(currentNode);
                    parent[currentNode] = SourceNode;
                    if (DistFromSourceNode + EdgeLength < distance[currentNode])
                    { //Relaxation step
                        distance[currentNode] = DistFromSourceNode + EdgeLength;
                    }
                }
            }
        }
        print(src);
    }
};
int main()
{
    Graph g1;
    g1.addEdge(1, 2, 6, false);
    g1.addEdge(1, 3, 4, false);
    g1.addEdge(1, 4, 5, false);
    g1.addEdge(4, 3, -2, false);
    g1.addEdge(3, 2, -2, false);
    g1.addEdge(2, 5, -1, false);
    g1.addEdge(3, 5, 3, false);
    g1.addEdge(4, 6, -1, false);
    g1.addEdge(5, 6, 3, false);
    g1.BellManFord_Algorithm(1);
    return 0;
}