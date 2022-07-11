#include <iostream>
using namespace std;
int FastPower(int a,int b){
    if (b==0){
        return 1;
    }
    if (b%2==0){
        return FastPower(a,b/2) * FastPower(a,b/2);
    }
    if (b%2 != 0)
    {
        return a*FastPower(a,b/2)*FastPower(a,b/2);
    }
}
int main(){
    cout << FastPower(2,9) <<endl;
    cout << FastPower(2,8) <<endl;
    return 0;
}