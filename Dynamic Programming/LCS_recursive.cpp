#include <iostream>
#include <string>
#include <cmath>
#include <climits>
using namespace std;
int LCS(string s1,string s2){
    //Base case
    if (s1.length()==0 || s2.length()==0){
        return 0;
    }
    //Recursive call
    if (s1[0]==s2[0]){
        int x=LCS(s1.substr(1),s2.substr(1));
        return x+1;
    }
    int m=LCS(s1.substr(1),s2);
    int n=LCS(s1,s2.substr(1));
    int u=LCS(s1.substr(1),s2.substr(1)); 
    int ans=max(m,max(n,u));
    return ans;
}
int main(){
    string s,t;
    cin>>s;
    cin>>t;
    cout << LCS(s,t) <<endl;
    return 0;
}
