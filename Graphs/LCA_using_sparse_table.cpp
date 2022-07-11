#include <bits/stdc++.h>
using namespace std;
const int N = 1e5,M=20; //M has been chosen keeping in mind 
vector<int> gr[N];
int dep[N];
int parent[N][M]; //this is the sparse table
//For storing the depths and parents
void dfs(int cur, int par)
{
    parent[cur][0] = par;
    dep[cur] = dep[par] + 1;
    for (int j=1;j<M;j++){
        parent[cur][j]=parent[parent[cur][j-1]][j-1]; //parent[cur][j-1] would have been already filled up because in DFS, we calculate ancestors of previous node first than child node
    }
    for (auto x : gr[cur])
    {
        if (x != par)
        {
            dfs(x, cur);
        }
    }
}
int LengthFromUtoV(int u,int v){
    int lca=LCA(u,v);
    return dep[u]+dep[v]-2*dep[lca];
}
int LCA(int u, int v)
{
    if (u == v)
    {
        return u;
    }
    if (dep[u] < dep[v])
        swap(u, v);
    int diff = dep[u] - dep[v];
    for (int j=M-1;j>=0;j--){
        if ((diff>>j)&1){ //checking if jth bit of number is set
        u=parent[u][j]; //calculating 2^j th parent of ueg. 19=2^4+2^1+2^0 then I am finding 1st parent of 19, then 2nd parent of 18, then 16th parent of 16
        }
    }
    //Now u and v would be at same level
    for (int j=M-1;j>=0;j--){
        if (parent[u][j]!=parent[v][j]){
            u=parent[u][j];
            v=parent[v][j];
        }
    }
    //at this point, I would be just 1 point down the LCA
    return parent[u][0];
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    dfs(1, 0); //any root node can be taken for doing the DFS
    for (int i = 1; i <= n; i++)
    {
        cout << i << " " << dep[i] << "\n";
    }
    for (int i=1;i<=12;i++){
        for (int j=0;j<4;j++){
            cout << i << "->";
            cout << parent[i][j] << " ";
        }
        cout <<endl;
    }
    cout << LCA(9, 12) << endl;
    cout << LCA(10, 8) << endl;
}