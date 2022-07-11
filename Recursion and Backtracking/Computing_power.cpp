#include <iostream>
using namespace std;
int answer (int a,int b){
    if (b==0){
        return 1;
    }
    int x=answer(a,b-1);
    return a*x;
}
int main(){
    cout << answer(3,2) <<endl;
    cout << answer (2,3) <<endl;
    return 0;
}