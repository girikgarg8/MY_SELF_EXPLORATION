#include <iostream>
#include <stack>
using namespace std;
int BracketReversal(string s){
    if (s.length()%2==1){
        return -1;
    }
    int n=s.length();
    stack <char> s1;
    for (int i=0;i<n;i++){
        if (s[i]=='{'){
            s1.push(s[i]);
        }
        else if (s1.empty() || s1.top()=='}'){
            s1.push(s[i]);
        }
        else s1.pop();
    }
    int d=s1.size();
    if (d%2==1){
        return -1;
    }
    int open=0; //count for open brackets
    while (!s1.empty()){
        if (s1.top()=='{'){
            open++;
        }
        s1.pop();
    }
    //Case of odd+odd
    if (open%2==1){
        return d/2+1;
    }
    else {
        return d/2;
    }
}
int main(){
    string a="}{{}}{{{";
    cout << BracketReversal(a) <<endl;
    return 0;
}