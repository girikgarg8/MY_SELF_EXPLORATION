//Recursive solution
#include <iostream>
#define MAX 10000
using namespace std;
int ShortestUncommonSubsequence(string s,string t,int a,int b){
    if (a==0) //string s is empty
    return MAX;
    if (b<=0){
        return 1;
    }
}