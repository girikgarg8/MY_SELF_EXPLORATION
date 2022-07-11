#include <iostream>
#include <climits>
#include <cmath>
#include <string>
using namespace std;
int LCS_memoization(int **arr,string s1,string s2){
    int a=s1.size();
    int b=s2.size();
    //Base case
    if (s1.length() == 0 || s2.length() == 0)
    {
        return 0;
    }
    if (arr[a][b]!=(-1)){
        return arr[a][b];
    }
    //Recursive call
    if (s1[0] == s2[0])
    {
        int ans = LCS_memoization(arr,s1.substr(1), s2.substr(1))+1;
        arr[a][b]=ans;
        return ans;
    }
    int m = LCS_memoization(arr,s1.substr(1), s2);
    int n = LCS_memoization(arr,s1, s2.substr(1));
    int u = LCS_memoization(arr,s1.substr(1), s2.substr(1));
    int ans = max(m, max(n, u));
    arr[a][b]=ans;
    return ans;
}
int LCS_memoization(string s,string t){
    int a=s.size(); //acts like rows
    int b=t.size(); //acts like columns
    int **arr=new int * [b+1];
    for (int i=0;i<=b;i++){
        arr[i]=new int[a+1];
    }
    for (int i=0;i<=a;i++){
        for (int j=0;j<=b;j++){
            arr[i][j]=-1;
        }
    }
    return LCS_memoization(arr,s,t);
}
int main()
{
    string s, t;
    cin >> s;
    cin >> t;
    cout << LCS_memoization(s,t) << endl;
    return 0;
}