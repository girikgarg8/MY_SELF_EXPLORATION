#include <iostream>
#include <cmath>
using namespace std;
int MinimumNumberOfSquares(int n){
    //Base Case
    if (sqrt(n)==(int)(sqrt(n))){
        return 1;
    }
    int ans = n; //Each number can be expressed as sum of n 1's
    //Recursive function call
    int x,i;
    for (i=1;i<=sqrt(n);i++){
        ans=min(ans,1+MinimumNumberOfSquares(n-i*i));
    }
    // Small calculation part
    return ans;
}
int main(){
    int num;
    cout << "Enter the number" <<endl;
    cin>>num;
    int y=MinimumNumberOfSquares(num);
    cout << y <<endl;
    return 0;
}