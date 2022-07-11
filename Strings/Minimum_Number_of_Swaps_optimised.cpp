#include <iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int ans=0;
    int open=0;
    int close=0;
    int fault=0;
    int n=s.length(); //The key point here is update the value of fault when we encounter a closing bracket
    for (int i=0;i<n;i++){
        if (s[i]==']'){
            close++;
            fault=close-open; //Here emphasis is on closed brackets
        }
        else{
            open++;
            if (fault>0){ //check for fault>0 in the section when we encounter an open bracker
                ans+=fault;
                fault--;
            }
        }
    }
    cout << ans <<endl;
    return 0;
}