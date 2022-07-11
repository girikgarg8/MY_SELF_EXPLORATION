#include <iostream>
#include <vector>
using namespace std;
int main(){
    string s;
    cin>>s;
    vector <int> v;
    int n=s.length();
    int idx=0;
    int ans=0;
    int count=0;
    for (int i=0;i<n;i++){
        if (s[i]=='['){
            v.push_back(i);
        }
    }
    for (int i=0;i<n;i++){
        if (s[i]=='['){
            count++;
            idx++;
        }
        else{
            count--;
            if (count<0){
                ans+=v[idx]-i;
                swap(s[i],s[v[idx]]);
                count=1; //restart the counter
                idx++;
            }
        }
    }
    cout << ans <<endl;
    return 0;
}