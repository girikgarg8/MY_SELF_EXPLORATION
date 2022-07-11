#include <iostream>
#include <map>
#include <queue>
#include <list>
using namespace std;
template <typename T>
class Graph{
    map <T,list<T> > m1;
    map<T, list<T>> m2;
    map <T,bool> visited;
    map <T,int> indegree;
    public:
    Graph(){

    }
    private:
    void addEdge2(T u, T v, bool isBidirectional = false)
    {
        m2[v].push_back(u);
        if (isBidirectional == true)
        {
            m2[u].push_back(v);
        }
    }
    public:
    void addEdge(T u, T v, bool isBidirectional=false){
        m1[u].push_back(v);
        if (isBidirectional==true){
            m1[v].push_back(u);
        }
        addEdge2(u,v,isBidirectional);
    }
    private:
    void calculateIndegree(){
        typename map <T, list<T> > ::iterator it;
        typename list <T> ::iterator it1;
        for (it=m2.begin();it!=m2.end();it++){
            int count=0;
            for (it1=m2[it->first].begin();it1!=m2[it->first].end();it1++){
                count++;
            }
            indegree[it->first]=count;
        }
    }
    public:
    void Topological_Sorting(){
        calculateIndegree();
        queue<T> q1;
        typename map<T, list<T> > ::iterator it1;
        for (it1=m1.begin();it1!=m1.end();it1++){
            if (indegree[it1->first]==0){
                q1.push(it1->first);
            }
        }
        while (!q1.empty()){
            T node=q1.front();
            cout << q1.front();
            q1.pop();
            typename list<T> :: iterator it;
            for (it=m1[node].begin();it!=m1[node].end();it++){
                indegree[*it]=indegree[*it]-1;
                if (indegree[*it]==0){
                    q1.push(*it);
                }
            }
        }
    }
};
int main(){
    Graph <int> g1;
    g1.addEdge(0,2);
    g1.addEdge(1,2);
    g1.addEdge(1,4);
    g1.addEdge(4,5);
    g1.addEdge(3,5);
    g1.addEdge(2,3);
    g1.Topological_Sorting();
    return 0;
}