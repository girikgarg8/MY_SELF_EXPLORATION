#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
vector <int> gr[N];
int vis[N],disc[N],low[N],tme=1;
set<int> arti_points;
vector <pair<int,int>> bridges;
int child;
void dfs(int cur,int par){
    vis[cur]=1;
    disc[cur]=low[cur]=tme;
    tme++;
    for (auto x:gr[cur]){
        if (!vis[x]){
            dfs(x,cur);
            // we know low and disc of x, in DP on graphs, we first calculate data on child and then use parent data
            child++;
            low[cur]=min(low[cur],low[x]);
            //bridges
            if (low[x]>disc[cur]){
                bridges.push_back({cur,x});
            }
            if (par!=0 && low[x]>=disc[cur]){
               arti_points.insert(cur); 
            }
        }
        else if (x!=par){
            //backedge
            low[cur]=min(low[cur],low[x]);
        }
    }
    //Find if root is an articulation point or not
    if (par==0 && child>1){
        arti_points.insert(cur);
    }
    return ;
}
int main(){
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    dfs(1,0);
    for (auto x:arti_points){
        cout << x << "\n";
    }
    for (auto x:bridges){
        cout << x.first << " "<< x.second << "\n";
    }
    return 0;
}