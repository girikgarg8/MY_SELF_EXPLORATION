#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> gr[N];
int sub[N], dp[N];
int ans = 0;
void dfs(int cur, int par)
{                 //calculates size of subtree of nodes in the given root
    sub[cur] = 1; //size of current root would be 1
    dp[cur] = 0;
    for (auto x : gr[cur])
    {
        if (x != par)
        {
            dfs(x, cur);
            dp[cur] += dp[x];
            sub[cur] += sub[x]; //to the current node's subtree sum, add size of its children nodes
        }
    }
    dp[cur] += sub[cur];
}
void dfs1(int cur, int par)
{
    ans = max(ans, dp[cur]);
    for (auto x : gr[cur])
    {
        if (x != par)
        {
            //remove x from subtree
            dp[cur] -= dp[x];
            dp[cur] -= sub[x];
            sub[cur] -= sub[x];
            //now add cur as the subtree of x
            sub[x] += sub[cur];
            dp[x] += dp[cur];
            dp[x] += sub[cur];
            dfs1(x, cur);
            dp[x] -= sub[cur];
            dp[x] -= dp[cur];
            sub[x] -= sub[cur];
            sub[cur] += sub[x];
            dp[cur] += sub[x];
            dp[cur] += dp[x];
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}