#include<bits/stdc++.h>
using namespace std;
 
bool canRepresentBST(int pre[], int n){
    stack<int> s;
    int root=INT_MIN;
    for (int i=0;i<n;i++){
        if (pre[i]<root){ //// If we find a node who is on right side
        // and smaller than root, return false
            return false;
        }
        while (!s.empty() && s.top()<pre[i]){
            root=s.top();
            s.pop();
        } //The last popped element would become thetop of stack
        s.push(pre[i]);
    }
    return true; 
}
int main(){
    int pre1[]={40, 30, 35, 80, 100};
    int n = sizeof(pre1)/sizeof(pre1[0]);
    canRepresentBST(pre1, n)? cout << "true\n":
                              cout << "false\n";
 
    int pre2[] = {40, 30, 35, 20, 80, 100};
    n = sizeof(pre2)/sizeof(pre2[0]);
    canRepresentBST(pre2, n)? cout << "true\n":
                              cout << "false\n";
 
    return 0;
}