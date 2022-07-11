#include <iostream>
#include <queue>
#include <list>
#include <map>
#include <climits>
using namespace std;
class Graph
{
    map<int, list<int>> m1;
    map<int, int> level;
    map<int, int> parent; //to store the parent and itsn neighboring nodes
public:
    Graph()
    {
    }
    void addEdge(int u, int v, bool isBidirectional = false)
    {
        m1[u].push_back(v);
        if (isBidirectional == true)
        {
            m1[v].push_back(u);
        }
    }
    void minNumberOfMoves(int src, int destination)
    {
        queue<int> q1;
        q1.push(src);
        map<int, list<int>>::iterator it;
        for (it = m1.begin(); it != m1.end(); it++)
        {
            level[it->first] = INT_MAX;
        }
        level[src] = 0;
        while (!q1.empty())
        {
            int s = q1.front();
            cout << endl;
            cout << "Neighbouring nodes of " << s << "in the queue"
                 << "are: ";
            if (s == destination)
            {
                cout << endl;
                cout << "Minimum number of moves required are " << level[destination] << endl;
                cout << "Path followed is" << endl;
                int temp = destination;
                while (temp != src)
                {
                    cout << temp << "<< ";
                    temp = parent[temp];
                }
                cout << src;
                break;
            }
            q1.pop();
            list<int>::iterator i;
            for (i = m1[s].begin(); i != m1[s].end(); i++)
            {
                if (level[*i] == INT_MAX)
                {
                    cout << *i << ",";
                    q1.push(*i);
                    parent[*i] = s;
                    level[*i] = level[s] + 1;
                }
            }
        }
    }
    void print()
    {
        list<int>::iterator i;
        map<int, list<int>>::iterator it;
        for (it = m1.begin(); it != m1.end(); it++)
        {
            cout << endl;
            cout << "Neighbouring nodes of" << it->first << " are:";
            for (i = m1[it->first].begin(); i != m1[it->first].end(); i++)
            {
                cout << *i << ",";
            }
        }
    }
};
int main()
{
    Graph g1;
    int SnakesAndLadders[50] = {0};
    SnakesAndLadders[2] = 13;
    SnakesAndLadders[5] = 2;
    SnakesAndLadders[9] = 18;
    SnakesAndLadders[18] = 11;
    SnakesAndLadders[25] = 10;
    SnakesAndLadders[17] = -13;
    SnakesAndLadders[24] = -8;
    SnakesAndLadders[20] = -14;
    SnakesAndLadders[32] = -2;
    SnakesAndLadders[34] = -22;
    int i;
    for (int i = 0; i <= 36; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            g1.addEdge(i, i + j + SnakesAndLadders[i + j]);
        }
    }
    g1.minNumberOfMoves(0, 36);
    return 0;
}
