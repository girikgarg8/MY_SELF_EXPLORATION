#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
vector <int> gr[N];
int tme=0;
int timeIn[N],timeOut[N];
void euler2(int cur,int par){
    cout << cur << " ";
    for (auto x:gr[cur]){
        if (x!=par){
        euler2(x,cur);
    }
}
    cout << cur << " ";
}
void euler1(int cur,int par){
    cout << cur << " ";
    for (auto x:gr[cur]){
        if (x!=par){
            euler1(x,cur);
            cout <<  cur << " ";
        }
    }
}
void euler3(int cur,int par){
    ++tme;
    timeIn[cur]=tme;
    for (auto x:gr[cur]){
        if (x!=par){
            euler3(x,cur);
        }
    }
    timeOut[cur]=tme;
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
    // euler2(1,0);
    cout << endl;
    // euler1(1,0);
    euler3(1,0);
    for (int i=1;i<=n;i++){
        cout << i << " " <<timeIn[i] << " " << timeOut[i] <<endl;
    }
    return 0;
}