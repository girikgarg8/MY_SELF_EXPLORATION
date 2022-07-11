#include <iostream>
#include <stack>
using namespace std;
#define N 8
bool MATRIX[N][N]={{0,0,1,0}}, {0,0,1,0},{0,0,0,0},{0,0,1,0}};
bool knows(int a,int b){
    return MATRIX[a][b];
}
int findPotentialCelebrity(int n){
    stack <int> s;
    //handle trivial case or edge case of n=2, in this case no celebrity is possible
    int C;
    for (int i=0;i<n;i++){
        s.push(i);
    }
    while (s.size()>1){
        int a=s.top();
        s.pop();
        int b=s.top();
        s.pop();
        if (knows(a,b)){ //means a knows b, then a can't be a celebrity
            s.push(b);
        }
        else{ // if a doesn't know b, then b can't be a celebrity
            s.push(a);
        }
    }
    if (s.empty()){
        return -1;
    }
    int c=s.top();
    s.pop();
    // Check if C is actually a celebrity or not
    for (int i=0;i<n;i++){
        if ((i!=c) && knows(c,i) || !knows(i,c)){
            return -1;
        }
    }
    return c;
}
int main(){
    int n=4;
    int id=findPotentialCelebrity(n);
    id==-1?cout << "No celebrity" : cout << "Celebrity ID" <<id;
    return 0;
}

//Space optimised approach
/*
int findCelebrity(int M[][],int n){
    int i=0;
    int j=n-1;
    while (i<j){
        if (M[j][i]==1) //means j knows i{
            j--;
        }
        else i++;  //means i know j
    }
    int candidate=i;
    for (i=0;i<n;i++){
        if (i!=candidate){
            if (M[i][candidate]==0 || M[candidate][i]==1){
                return -1;
            }
        }
    }
    return candidate;
}
*/