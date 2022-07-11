#include <iostream>
#include <algorithm>
using namespace std;
bool checkValidShuffle(string s1,string s2,string s3){
    if (s3.size()!=(s1.size()+s2.size())){
        return false;
    }
    else{
    string s4=s1+s2;
    sort(s4.begin(),s4.end());
    sort(s3.begin(),s3.end());
    if (s3==s4){
        return true;
    }
    return false;
}
}
int main(){
    string s1="xy";
    string s2="12";
    string s3="x12y";
    string s4="67xy";
    cout << checkValidShuffle(s1,s2,s3) <<endl;
    cout << checkValidShuffle(s1, s2,s4) << endl;
    return 0;
}