#include <iostream>
using namespace std;
int CountBalancedBinaryTree(int height){
    //Base Case
    if (height==1 || height==0){
        return 1;
    }
    //Recursive Call
    int x=CountBalancedBinaryTree(height-1);
    int y=CountBalancedBinaryTree(height-2);
    int answer=x*x+x*y+y*x;
    return answer;
}
int main(){
    cout << "Enter the height" <<endl;
    int height;
    cin>>height;
    cout << "Number of balanced binary trees is " << CountBalancedBinaryTree(height) <<endl;
    return 0;
}