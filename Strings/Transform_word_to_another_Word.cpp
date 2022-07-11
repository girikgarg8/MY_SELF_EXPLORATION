#include <bits/stdc++.h>
using namespace std;
int minOperations(string a,string b){
    int n=a.length();
    int m=b.length();
    if (n!=m){
        return -1;
    }
    int count[256]; //this array is taken because ASCII values can range from 0 to 255
    memset(count,0,sizeof(count));
    for (int i=0;i<n;i++){
        count[b[i]]++;
    } 
    for (int i=0;i<m;i++){
        count[a[i]]--;
    }
    for (int i=0;i<256;i++){
        if (count[i])
        return -1;
    }
    //Now we are going to calculate the minimum number of operations
    int res=0;
    for (int i=n-1,j=n-1;i>=0 && j>=0;){
        //If there is a mismatch, move i backwards till the character is found in string a
        while (i>=0 && a[i]!=b[j]){
            i--;
            res++;
        }
        //in case the characters in the string match
        if (i>=0 && j>=0){
            i--;
            j--;
        }    
    }
    return res;
}
int main(){
    string a="EACBD";
    string b="EABCD";
    cout << "Minimum number of operations required is " << minOperations(a,b);
    return 0; 
}
