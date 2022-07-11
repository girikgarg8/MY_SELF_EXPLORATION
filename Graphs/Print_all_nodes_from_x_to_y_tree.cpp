#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
vector <int> gr[N];
int par[N];
void dfs(int cur,int parent){
    par[cur]=parent;
    for (auto x:gr[cur]){
        if (x!=parent){
        par[x]=cur;
        dfs(x,cur);
        }
    }
}
void printAllAncestors(int u){
    while (u!=0){
        cout << u << " ";
        u=par[u];
    }
}
int main(){
    int n;
    cin>>n;
    for (int i=0;i<(n-1);i++){
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    int x,y;
    cin>>x>>y;
    dfs(y,0);
    printAllAncestors(x);
    return 0;
}