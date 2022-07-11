#include <iostream>
using namespace std;
string CountAndSay(int n){
    if (n==1){
        return "1";
    }
    if (n==2){
        return "11";
    }
    string s="11";
    for (int i=3;i<=n;i++){
        string t="";
        s=s+'&';
        int c=1; //count
        for (int j=1;j<s.length();j++){
            if (s[j]!=s[j-1]){
                t=t+to_string(c);
                t=t+s[j-1];
                c=1;
            }
            else c++;
        }
        s=t;
    }
    return s;
}
int main(){
    cout <<  CountAndSay(3) <<endl;
    cout << CountAndSay(4) <<endl;
    cout << CountAndSay(5) <<endl;
    return 0;
}