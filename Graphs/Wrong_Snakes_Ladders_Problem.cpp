#include <iostream>
#include <cmath>
#include <map>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;
int MinNumberOfSteps(int n,int index){
    // Base Case
    if (index==n){
        return 0;
    }
    if (index==2){
        return MinNumberOfSteps(n,15);
    }
    if (index==5)
    {
        return MinNumberOfSteps(n,7);
    }
    if (index == 9)
    {
        return MinNumberOfSteps(n, 27);
    }
    if (index == 18)
    {
        return MinNumberOfSteps(n, 29);
    }
    if (index == 25)
    {
        return MinNumberOfSteps(n, 35);
    }
    if (index==34){
        return MinNumberOfSteps(n,12);
    }
    if (index==24)
    {
        return MinNumberOfSteps(n, 16);
    }
    if (index==32){
        return MinNumberOfSteps(n,30);
    }
    if (index==20){
        return MinNumberOfSteps(n,6);
    }
    if (index==17)
    {
        return MinNumberOfSteps(n,4);
    }
    //Recursive call
    int x= 1+MinNumberOfSteps(n,1);
    int y = 1+MinNumberOfSteps(n, 2);
    int z = 1+MinNumberOfSteps(n, 3);
    int a = 1+MinNumberOfSteps(n, 4);
    int b = 1+MinNumberOfSteps(n, 5);
    int c = 1+MinNumberOfSteps(n, 6);
    vector <int> arr;
    arr.push_back(x);
    arr.push_back(y);
    arr.push_back(z);
    arr.push_back(a);
    arr.push_back(b);
    arr.push_back(c);
    sort(arr.begin(),arr.end());
    return arr[0];
}
int main(){
    cout << MinNumberOfSteps(36,0) <<endl;
    return 0;
}