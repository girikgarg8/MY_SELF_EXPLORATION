#include <bits/stdc++.h>
using namespace std;
struct Dinic{
    struct edge{
        int x,y,w; //from x to y with residual capacity w
    };
    vector <vector<int> > gr; //here in the adjacency list, I am pushing edge count, I can get the edge count from this array and find it from vector<edge>edges this is because I have to make changes in edge when doing augment
    vector <edge> edges;
    vector <int> edgesize;
    vector <int> level;
    vector <int> edge_sz;
    int n,source,sink,ec=0;
    Dinic(int n,int source,int sink){
        this->n=n;
        this->source=source;
        this->sink=sink;
        gr.resize(n);
        edgesize.resize(n);
    }
    void add_edge(int x,int y,int w){
        edges.push_back({x,y,w}); //forward edge
        gr[x].push_back(ec++);       
        edges.push_back({y,x,0}); //backward edge, one thing to note here that forward edge and backward edge will have successive indices
        gr[y].push_back(ec++);
    }
    bool level_graph(){
        level.clear(); //when multiple times level vector is getting created, this needs to be done
        level.resize(n,-1);
        queue <int> Q; //this is simple BFS
        Q.push(source);
        level[source]=-1;
        while (!Q.empty()){
            int cur=Q.front();
            Q.pop();
            for (auto xx:gr[cur]){
                int to=edges[xx].y; //retrieve the values from edge array
                int w=edges[xx].w;
                if (w&&level[to]==-1){
                    level[to]=level[cur]+1;
                    Q.push(to);
                }
            }
        }
        return level[sink]!=-1;
    }
    int augment(int cur,int flow){ //DFS  
        if (cur==sink){
            return flow;
        }
        for (int &i=edge_sz[cur];i>=0;i--){
            int edge_index=gr[cur][i];
            int w=edges[edge_index].w;
            int y=edges[edge_index].y;
            if (w && level[y]==level[cur]+1){
                int bottleneckflow=augment(y,min(w,flow));
                if (bottleneckflow){
                    edges[edge_index].w-=bottleneckflow;
                    edges[edge_index^1].w+=bottleneckflow;
                    return bottleneckflow;
                }
            }
        }
        return 0;
    }
    int max_flow(){
        int total_flow=0;
        while (level_graph()){ //augment different paths
            for (int i=0;i<n;i++){
                edge_sz[i]=gr[i].size();
            }
            while (int flow=augment(0,1e9)){
                total_flow+=flow;
            }
        }
        return total_flow;
    }
};
int main(){
    Dinic G(4,0,3); //n,source,sink
    G.add_edge(0,1,5);
    G.add_edge(1,2,2);
    G.add_edge(2,3,3);
}