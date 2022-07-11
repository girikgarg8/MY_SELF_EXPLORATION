#include <bits/stdc++.h>
using namespace std;
// void print(vector <vector <string> > &v,int i,int j){
//     if (i>=v.size()){
//         return ;
//     }
//     if (j>v[i].size()){
//         print(v,i,j);
//     }
//     cout << v[i][j];
//     print (v,i+1,j);
// }
void printAllCOmbinations(vector <vector <string> > &v,int n,string result,int vector_num){
    //Here n is total number of elements in the vector
    // result is the output string 
    // vector_num is the current vector element we are traversing
    if (vector_num==n){
        cout << result.substr(1) <<endl; //this step is needed becuase when inserting first element, an extra space is inserted
        return ;
    }
    int m=v[vector_num].size();
    for (int u=0;u<m;u++){
        string out=result+" "+v[vector_num][u];
        printAllCOmbinations(v,n,out,vector_num+1);
    }
}
int main(){
    vector <vector<string> > v={{"you","we"},{"have","are"},{"sleep","eat","drink"}};
    printAllCOmbinations(v,3,"",0);
    return 0;
}