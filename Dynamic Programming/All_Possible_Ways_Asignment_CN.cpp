// #include <iostream>
// #include <cmath>
// using namespace std;
// int AllPossibleWays(int n,int b,int prev){
//     if (n<=0){
//         return 0;
//     }
//     if (n==1){
//         return 1;
//     }
//     int a=(int) pow(n,1/b);
//     int ans=0;
//     for (int i=1;i<=a && i!=prev;i++){
//         prev=i;
//         ans+=AllPossibleWays(pow(i,b),b,prev)*AllPossibleWays(n-pow(i,b),b,prev);
//     }
//     return ans;
//     }
#include <iostream>
#include <cmath>
using namespace std;
int AllPossibleWays(int num,int b,int start_index,int  curr_sum){
    int ans=0;
    int p=pow(start_index,b);
    while (curr_sum+p<num){
    ans+=AllPossibleWays(num,b,start_index+1,curr_sum+p);
    start_index+=1;
    p=pow(start_index,b);
    }
    if (curr_sum+p==num){
        ans++;
    }
    return ans;
}
int main(){
    cout << AllPossibleWays(100,2,1,0);
    return 0;
}

