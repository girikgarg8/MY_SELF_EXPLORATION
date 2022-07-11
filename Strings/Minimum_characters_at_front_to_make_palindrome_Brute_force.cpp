#include <bits/stdc++.h>
using namespace std;
//Function for checking string is palindrome or not
bool isPalindrome(string s){
    int l=s.length();
    int j=l-1;
    for (int i=0;i<=j;i++,j--){
        if (s[i]!=s[j]){
            return false;
        }
    }
    return true;
}
int main(){
    string s="BABABAA";
    int cnt=0;
    int flag=0;
    while (s.length()>0){
        //if string becomes palindrome, then break
        if (isPalindrome(s)){
            flag=1;
            break;
        }
        else{
            cnt++;
            s.erase(s.begin()+s.length()-1);
        }
    }
    if (flag){
        cout << cnt;
    }
}