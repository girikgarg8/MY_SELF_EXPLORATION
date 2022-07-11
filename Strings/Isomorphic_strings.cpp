#include <bits/stdc++.h>
using namespace std;
bool areIsomorphic(string a,string b){
    int l=a.size();
    int m=b.size();
    if (l!=m){
        return false;
    }
    unordered_map <char,char> m1;
    for (int i=0;i<l;i++){
        if (m1.find(a[i])==m1.end()){
            m1[a[i]]=b[i];
        }
        else{
            if (m1[a[i]]!=b[i]) return false;
        }
    }
    return true;
}
int main(){
    string s1="abaab";
    string s2="xyxxy";
    string t= "xyxyy";
    cout << areIsomorphic(s1,s2) <<endl;
    cout << areIsomorphic(s1,t);
    return 0;
}