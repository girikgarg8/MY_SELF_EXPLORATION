#include <bits/stdc++.h> //DFS tree for undirected graph
using namespace std;
const int N = 1e5;
vector<int> gr[N]; //Adjacency list of the graph eg. gr[1] will have the neighboruign nodes of
int vis[N],parent[N];
bool cycle = false;
void dfs(int cur, int par)
{
    cout << cur << endl;
    vis[cur] = 1;
    parent[cur]=par;
    for (auto x : gr[cur])
    {
        if (vis[x] == 0)
        {
            dfs(x, cur);
        }
        else if (x != par && vis[x] == 1)
        {
            // backedge
            int u=cur;
            int v=x;
            while (u!=v){
                cout << u << " ";
                u=parent[u];
            }
            cout << u << " ";
            exit(0); //it will end all the call stacks and terminate
        }
    }
    vis[cur] = 2;
}
int main()
{
    int n, m;
    cin >> n >> m; //n represents nodes and m represents edged
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, 0); //0 is an imaginaty parent
        }
    }
}
/*
7
8
1 2
2 3
1 3
2 4
4 5
5 6
6 7
4 7
3 1
*/