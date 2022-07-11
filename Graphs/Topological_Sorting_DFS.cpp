#include <iostream>
#include <map>
#include <list>
using namespace std;
class Graph
{
    map<string, list<string>> m1;
    list<string> answer;

public:
    Graph()
    {
    }
    void addEdge(string a, string b, bool isBidirectional = false)
    {
        m1[a].push_back(b);
        if (isBidirectional == true)
        {
            m1[b].push_back(a);
        }
    }
    void DFSHelper(string a, map<string, bool> &visited)
    {
        visited[a] = true;
        list<string>::iterator i;
        for (i = m1[a].begin(); i != m1[a].end(); i++)
        {
            if (visited[*i] == false)
            {
                visited[*i] = true;
                DFSHelper(*i, visited);
            }
        }
        answer.push_front(a); //This is the extra step, we need to make a linked list and push it to the front
        // or we can also use a stack
    }
    void TopologicalSorting() //No parameters
    {
        map<string, bool> visited;
        //I need to call helper function over all nodes
        map<string, list<string>>::iterator it;
        for (it = m1.begin(); it != m1.end(); it++)
        {
            if (visited[it->first] == false)
            {
                DFSHelper(it->first, visited);
            }
        }
        list<string>::iterator i;
        for (i = answer.begin(); i != answer.end(); i++)
        {
            cout << *i << endl;
        }
    }
};
int main()
{
    Graph g1;
    g1.addEdge("English", "Programming Logic");
    g1.addEdge("English", "HTML");
    g1.addEdge("Python", "Web Development");
    g1.addEdge("Programming Logic", "JS");
    g1.addEdge("Programming Logic", "Java");
    g1.addEdge("Maths", "Programming Logic");
    g1.addEdge("HTML", "CSS");
    g1.addEdge("CSS", "JS");
    g1.addEdge("JS", "Web Development");
    g1.addEdge("Java", "Web Development");
    g1.addEdge("Programming Logic", "Python");
    g1.addEdge("Programming Logic", "HTML");
    g1.TopologicalSorting();
    return 0;
}
