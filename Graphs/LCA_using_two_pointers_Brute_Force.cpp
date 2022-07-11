#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
vector <int> gr[N];
int dep[N];
int parent[N];
//For storing the depths and parents
void dfs(int cur,int par){
    parent[cur]=par;
    dep[cur]=dep[par]+1;
    for (auto x:gr[cur]){
        if (x!=par){
            dfs(x,cur);
        }
    }
}
int LCA(int u,int v){
    if (u==v){
        return u;
    }
    if (dep[u]<dep[v]) swap(u,v);
    int diff=dep[u]-dep[v];
    while (diff--){
        u=parent[u];
    }
    while (u!=v){
        u=parent[u];
        v=parent[v];
    }
    return u;
}
int main(){
    int n;
    cin>>n;
    for (int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    dfs(1,0); //any root node can be taken for doing the DFS
    for (int i=1;i<=n;i++){
        cout << i << " " <<dep[i] << "\n";
    }
    cout << LCA(9,12) <<endl;
    cout << LCA(10,8) <<endl;
}