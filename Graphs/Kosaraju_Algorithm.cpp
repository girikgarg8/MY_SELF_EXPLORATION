#include <bits/stdc++.h> 
using namespace std;
const int N = 1e5;
vector <int> gr[N],grReverse[N];
int vis[N],col[N];
vector <int> topologicalOrder;
void dfs(int cur){
    vis[cur]=1;
    for (auto x:gr[cur]){
        if (!vis[x]){
            dfs(x);
        }
    }
    topologicalOrder.push_back(cur);
}
void dfsOnReverse(int cur,int comp){
    vis[cur]=1;
    col[cur]=comp;
    for (auto x:grr[cur]){
        if (!vis[x]) dfs2(x,comp);
    }
}
int main(){
    int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		grr[y].push_back(x);
	}
    reverse(order.begin(),order.reverse());
    memset(vis,0,sizeof(vis));
    int comp=1;
    for (auto x:order){
        if (!vis[x]) dfs2(x,comp);
        comp++;
    }
    for (int i=1;i<=n;i++){
        cout << i << " " <<col[i] <<endl;
    }
    return 0;
}