#include <bits/stdc++.h>
using namespace std;
vector <vector <string> > anagrams (vector <string> &a){
    map <string,vector<string> > m;
    for (int i=0;i<a.size();i++){
        string s=a[i];
        sort(s.begin(),s.end());
        m[s].push_back(a[i]);
    }
    /* After these steps, my map will look like this
    Value:act Key: Vector having elements as act,cat, tac
    Value: dgo Key: vector having elements as dog,god
    */
    vector <vector <string> > ans (m.size());
    int idx=0;
    for (auto i:m){
        auto v=i.second;
        for (int u=0;u<v.size();u++){
            ans[idx].push_back(v[u]);
        }
        idx++;
    }
    return ans;
}
int main(){
    vector <string> a={"act","god","cat","dog","tac"};
    vector <vector <string> > b=anagrams(a);
    for (auto i:b){
        for (auto j:i){
            cout << j << " ";
        }
    }
    return 0;
}