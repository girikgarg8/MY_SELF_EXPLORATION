#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int a[N][N], vis[N][N];
int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
void flood_fill(int x, int y)
{
    a[x][y] = 0;
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx >= 0 && xx < n && yy >= 0 && yy < m && a[xx][yy] == 1)
        {
            flood_fill(xx, yy);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int total_count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        { //start from the top left cell
            /* if (a[i][j]==1 && vis[i][j]==0) We can achieve this step even without using a visited matrix. The need of visited matrix is because if I have 1 1,then if I begin from left 1 and explore it's neighbours, I don't want to start Flood fill algo from right 1. hence, time complety would remain O(m*n)
            //Whenever I visit a cell which is 1 (land),  will mark it as 0 */
            if (a[i][j] == 1)
            {
                total_count++;
                cout << "DFS called for i=" << i << "and j= " << j << endl;
                flood_fill(i, j);
            }
        }
    }
    cout << "Total number of connected componenents are " << total_count << endl;
    return 0;
}