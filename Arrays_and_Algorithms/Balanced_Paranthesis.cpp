#include <iostream>
#include <stack>
using namespace std;
bool checkForBalancedParantheses(string s){
    stack <char> s1;
    int l=s.size();
    for (int i=0;i<l;i++){
        if (s[i]=='(' || s[i]=='{' || s[i]== '['){
        s1.push(s[i]);
    }
    if (s1.empty()){ //This is because there can be case like )}]
        return false;
    }
    //Switch for encountering those cases if s1[i] is other than these
    switch (s[i]){
        case '}':{
            char g=s1.top();
            s1.pop();
            if (g=='(' || g=='['){
                return false;
            }
            break;
        }
        case ')':{
            char g = s1.top();
            s1.pop();
            if (g == '{' || g == '[')
            {
                return false;
            }
            break;
        }
        case ']':{
            char g = s1.top();
            s1.pop();
            if (g == '(' || g == '{')
            {
                return false;
            }
            break;
        }
    }
}
return s1.empty(); //This is because there can be case like {[( 
}
int main(){
    string s1="{([])}";
    string s2="([]";
    cout << checkForBalancedParantheses(s1) <<endl;
    cout << checkForBalancedParantheses(s2) <<endl;
    return 0;
}