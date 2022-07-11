#include <iostream>
#include <list>
using namespace std;
class Graph{
    int V;
    list <pair<int,int> > edges;
    int *parent;
    int *rank;
    public:
    Graph(int V){
        this->V=V;
        parent= new int[V];
        for (int i=0;i<V;i++){
            parent[V]=-1;
        }
        for (int i=0;i<V;i++){
            rank[i]=1;
        }
    }
    void addEdge(int u,int v){
        edges.push_back(make_pair(u,v));
    }
    int findParent(int a){
        if (parent[a]==(-1)){
            return a;
        }
        return parent[a]=findParent(parent[a]); //Path compression step
    }
    void union_set(int a,int b){
        int s1=findParent(a);
        int s2=findParent(b);
        if (s1!=s2){
            if (rank[s1]>rank[s2]){
                parent[s2]=s1;
                rank[s1]+=rank[s2];
            }
            else{
                parent[s1]=s2;
                rank[s2]+=rank[s1];
            }
        }
    }
    bool isCyclic(){
        for (auto j:edges){
            int a=j.first;
            int b=j.second;
            int s1=findParent(a);
            int s2=findParent(b);
            if (s1!=s2){
                union_set(s1,s2);
            }
            else {
                cout << "Cyclicity is present in the graph" <<endl;
                return true;
            }
        }
        return false;
    }
    int NoPath(){
        int ans=0;
        for (auto j:edges){
            int a=j.first;
            int b=j.second;
            int s1=findParent(a);
            int s2=findParent(b);
            union_set(s1,s2);
        }
        for (int i=0;i<V;i++){
            ans+=V-rank[parent[i]];
        }
        return ans/2;
    }
};
int main(){
    
}