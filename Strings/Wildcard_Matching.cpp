#include <bits/stdc++.h>
using namespace std;
bool wm(string str,string pat,int i,int j){
    //wm for wildcard matching
    if (i==str.size() && j==pat.size()){
        return true;
    }
    if (i!=str.size() && j==pat.size()){
        return false;
    }
    if (i==str.size() && j!=pat.size()){
        for (int index=j;index<pat.size();index++){
            if (pat[index]!='*') return false;
        }
        return true;
    }
    //Base cases are over
    bool ans=false;
    if (pat[j]=='?'){
        if (wm(str,pat,i+1,j+1)){
            ans=true;
        }
    }
    if (pat[j]=='*'){
        if (wm(str,pat,i+1,j+1)){
            ans=true;
        }
        if (wm(str,pat,i,j+1)){
            ans=true;
        }
        if (wm(str,pat,i+1,j)){
            ans=true;
        }
    }
    else{
        if (str[i]==pat[j] && wm(str,pat,i+1,j+1)){
            ans=true;
        }
    }
    return ans;
}
int main(){
    string s="geeks";
    string t="g*ks";
    string a="gee";
    string b="g*k";
    string c="geeksforgeeks";
    string d="ge?ks*";
    cout << wm(s,t,0,0)<<endl;
    cout << wm(a,b,0,0) <<endl;
    cout << wm(c,d,0,0) <<endl;
    return 0;
}