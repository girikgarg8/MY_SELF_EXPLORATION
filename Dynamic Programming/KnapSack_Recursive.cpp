#include <iostream>
#include <cmath>
using namespace std;
int KnapSack(int n,int weights[],int values[],int w){
    int z;
    //Base Case
    if (n==0 || w==0){
        return 0;
    }
    //Recursive Call
    if (weights[0]>w){
        return KnapSack(n-1, weights+1, values + 1, w);
    }
    int x=KnapSack(n-1,weights+1,values+1,w-weights[0])+values[0];
    int y=KnapSack(n-1,weights+1,values+1,w);
    //Small calculation part
    int a=max(x,y);
    return a;
}
int main(){
    int n,w;
    cout << "Enter the value of n" <<endl;
    cin >> n ;
    int *weights=new int[n];
    int *values=new int[n];
    for (int i=0;i<n;i++){
        cin>>weights[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }
    cout << "Enter maximum weight" <<endl;
    cin >> w ;
    cout << "Maximum value is " << KnapSack(n,weights,values,w) <<endl;
    return 0;
}