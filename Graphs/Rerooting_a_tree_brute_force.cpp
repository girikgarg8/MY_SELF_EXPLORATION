//This is sir's solution, I have written my code as well
#include <bits/stdc++.h> 
using namespace std;
const int N = 1e5;
vector <int> gr[N];
int sub[N];
int dfs(int cur,int par){ //calculates size of subtree of nodes in the given root
    sub[cur]=1; //size of current root would be 1
    int sum=0;
    for (auto x:gr[cur]){
        if (x!=par){
            sum+=dfs(x,cur);
            sub[cur]+=sub[x]; //to the current node's subtree sum, add size of its children nodes
        }
    }
    sum+=sub[cur];
    return sum;
}
int main(){
    int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
    cout << "Sum of subtrees is " << dfs(1,0);
    int maxSum=0;
    for (int i=1;i<=n;i++){
        maxSum=max(maxSum,dfs(i,0)); //Time complexity is O(n) for one dfs call and O(n)*n for n dfs calls
    }
    cout << "Maximum possible sum is" << maxSum <<endl;
    return 0;
}
//A more understadanble code in terms of recursion is given below
/*
#include <bits/stdc++.h> 
using namespace std;
const int N = 1e5;
vector <int> gr[N];
int sub[N];
int dfs(int cur,int par,int n){ //calculates size of subtree of nodes in the given root
    sub[cur]=1; //size of current root would be 1
    for (auto x:gr[cur]){
        if (x!=par){
            dfs(x,cur,n);
            sub[cur]+=sub[x]; //to the current node's subtree sum, add size of its children nodes
        }
    }
    int sum=0;
    for (int i=1;i<=n;i++){
        sum+=sub[i];
    }
    return sum;
}
int main(){
    int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
    cout << "Sum of subtrees is " << dfs(1,0,n);
    return 0;
}

*/