#include <iostream>
using namespace std;
int i=0;
int MinSteps(int n){
    //Brute Force Approach
    //Base Case
    if (n==1){
        return i;
    }
    //Small Calculation step
    if (n%3==0){
        n/=3;
        i++;
    }
    else if (n%2==0){
        n/=2;
        i++;
    }
    else{
        n=n-1;
        i++;
    }
    //Recursive call
    return MinSteps(n);
}
int main(){
    cout << MinSteps(9) <<endl;
    return 0;
}