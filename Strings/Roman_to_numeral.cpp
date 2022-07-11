#include <iostream>
using namespace std;
int value(char r){ //for returning digit corresponding to characters
    if (r=='I'){
        return 1;
    }
    else if (r=='V'){
        return 5;
    }
    else if (r=='X'){
        return 10;
    }
    else if (r=='L'){
        return 50;
    }
    else if (r=='C'){
        return 100;
    }
    else if (r=='D'){
        return 500;
    }
    else if (r=='M'){
        return 1000;
    }
    return -1;
}
int romanToDecimal(string &str){
    int res=0;
    for (int i=0;i<str.length();i++){
        int s1=value(str[i]);
        if (i+1<str.length()){
            int s2=value(str[i+1]);
            if (s1>=s2){
                res=res+s1;
            }
            else{
                res=res+s2-s1;
                i++;
            }
        }
        else //This is for the last digit, the i+1 th digit wouldn't be available in this case
        {
            res = res + s1;
        }
    }
    return res;
}
int main(){
    string str="MCMIV";
    cout << romanToDecimal(str);
    return 0;
}