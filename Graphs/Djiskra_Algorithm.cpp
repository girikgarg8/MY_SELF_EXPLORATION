#include <iostream>
#include <map>
#include <set>
#include <list>
#include <climits>
using namespace std;
template <typename T>
class Graph
{
    map<T, list<pair<T, int>>> m1;
    map<T, bool> visited;
    map<T, int> distance; //represents minimum distance from source vertex

public:
    void addEdge(T u, T v, int dist, bool isBidirectional = true)
    {
        m1[u].push_back(make_pair(v, dist));
        if (isBidirectional == true)
        {
            m1[v].push_back(make_pair(u, dist));
        }
    }
    void print()
    {
        typename map<T, list<pair<T, int>>>::iterator it;
        typename list<pair<T, int>>::iterator i;
        for (it = m1.begin(); it != m1.end(); it++)
        {
            for (i = m1[it->first].begin(); i != m1[it->first].end(); i++)
            {
                cout << it->first << " : Node" << (*i).first << ",Edge Distance:" << (*i).second << endl;
            }
        }
    }

private:
    void print(T src)
    {
        typename map<T, int>::iterator g;
        for (g = distance.begin(); g != distance.end(); g++)
        {
            cout << "Shortest path from " << src << " to" << g->first << " is" << g->second << endl;
        }
    }

public:
    void Djiskra_Algorithm(T src)
    {
        set<pair<int, T>> s; //ordinary declaration is like set<int> or set <float> //First one is distance and second one is the data at the node
        typename map<T, list<pair<T, int>>>::iterator w;
        for (w = m1.begin(); w != m1.end(); w++)
        {
            distance[w->first] = INT_MAX;
        }
        distance[src] = 0;
        s.insert(make_pair(0, src));
        while (!s.empty())
        {
            pair<int, T> s1 = *(s.begin());
            pair<int, T> temp1 = s1;
            int DistofCurrNodefromSrc = s1.first;
            T value_1 = s1.second;
            s.erase(s.begin());
            typename list<pair<T, int>>::iterator u;
            for (u = m1[value_1].begin(); u != m1[value_1].end(); u++)
            {
                pair<T, int> temp = *u;
                int EdgeLengthOfTemp = temp.second;
                T value = temp.first;
                if (DistofCurrNodefromSrc + EdgeLengthOfTemp < distance[temp.first])
                {
                    typename set<pair<int, T>>::iterator it;
                    it = s.find(make_pair(distance[value_1], value_1));
                    if (it != s.end())
                    {
                        s.erase(it);
                    }
                    distance[temp.first] = DistofCurrNodefromSrc + EdgeLengthOfTemp;
                    s.insert(make_pair(distance[temp.first], temp.first));
                    //As direct delete not there in set
                    // we have to remove the pair and insert a new pair
                }
            }
        }
        print(src);
    }
};
int main()
{
    Graph<int> g1;
    g1.addEdge(1, 2, 1);
    g1.addEdge(2, 3, 1);
    g1.addEdge(3, 4, 2);
    g1.addEdge(1, 4, 7);
    g1.addEdge(1, 3, 4);
    g1.print();
    g1.Djiskra_Algorithm(1);
    return 0;
}