#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <queue>
using namespace std;
class Graph
{
    int V;
    map<int, list<pair<int, int> > >m1; //Adjacency list implementation
    map<int, bool> visited;

public:
    Graph(int V)
    {
        this->V = V;
    }
    void addEdge(int a, int b, int weight, bool isBidirectional = true)
    {
        m1[a].push_back({b, weight});
        if (isBidirectional == true)
        {
            m1[b].push_back({a, weight});
        }
    }
    int PrimsAlgorithm()
    {   int ans=0;
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
        //Min heap or min priority queue to see the edge with least weight
        q.push(make_pair(0, 0)); //first one is distance (first parameter is kept as distance as sorting takes place on the basis of it), second one denotes to value
        //0,0 is a hypothetical pair 
        //In prim's algorithm, we will need to pass such a hypothetical point
        while (!q.empty())
        {
            pair<int,int> p1=q.top();
            int distance=p1.first;
            int node_data=p1.second;
            q.pop();
            //Now there can be two cases: either the element is already visited or not visited
            if (visited[node_data]==false){
                ans+=distance;
                visited[node_data]=true;
            }
            //Pushing more elements into the queue: the neighbouring elements of the chosen node
            for (auto j: m1[node_data]){
                if (visited[j.first]==false){
                    /* q.push(j); Wrong because in the queue the distance comes first, while in the  map the value comes first
                    */
                    int node_data=j.first;
                    int weight=j.second;
                    q.push(make_pair(weight,node_data));
                }
            }
        }
        return ans;
    }
};
int main(){
    Graph g1(4);
    g1.addEdge(0,2,2);
    g1.addEdge(0,3,2);
    g1.addEdge(1,2,2);
    g1.addEdge(2,3,3);
    g1.addEdge(3,1,2);
    g1.addEdge(1,0,1);
    cout << "Minimum cost of the MST is " << g1.PrimsAlgorithm();
    return 0;
}