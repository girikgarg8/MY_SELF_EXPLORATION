#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
vector <vector <int>> findDist (vector <vector <int> > mat,int n,int m){
    queue<pair<int,int> > q;
    vector <vector <int>> dist(n,vector <int> (m,INT_MAX)); 
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (mat[i][j]==1){
                q.push({i,j});
                dist[i][j]=0;
            }
        }
    }
    int dx[]={-1,0,0,1};
    int dy[]={0,-1,1,0};;
    while (!q.empty()){
        pair <int,int> a=q.front();
        int i=a.first;
        int j=a.second;
        q.pop();
        for (int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if (x>=0 && x<n && y>=0 && y<m && dist[x][y]>dist[i][j]+1){
                dist[x][y]=dist[i][j]+1;
                q.push({x,y});
            }
        }
    }
    return dist;
}
int main(){
    vector <vector <int> > a;
    a={{0,0,0,1},{0,0,1,1},{0,1,1,0}};
    vector <vector <int> > ans=findDist(a,3,4);
    for (auto u:ans){
        for (auto v:u){
            cout << v << " ";
        }
        cout <<endl;
    }
}