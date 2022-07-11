#include <iostream>
#include <cmath>
using namespace std;
int KnapSack(int n, int weights[], int values[], int w,int **arr)
{
    int z;
    //Base Case
    if (n == 0 || w == 0)
    {
        return 0;
    }
    if (arr[n][w]!=(-1)){
        return arr[n][w];
    }
    //Recursive Call
    if (weights[0] > w)
    {
        return KnapSack(n - 1, weights + 1, values + 1, w,arr);
    }
    int x = KnapSack(n - 1, weights + 1, values + 1, w - weights[0],arr) + values[0];
    int y = KnapSack(n - 1, weights + 1, values + 1, w,arr);
    //Small calculation part
    int a = max(x, y);
    arr[n][w]=a;
    return a;
}
int KnapSack(int n, int weights[], int values[], int w){
    int a=n+1; //rows
    int b=w+1; // columns
    int **arr= new int *[b];
    for (int i=0;i<b;i++){
        arr[i]=new int [a];
    }
    for (int i=0;i<a;i++){
        for (int j=0;j<b;j++){
            arr[i][j]=(-1);
        }
    }
    return KnapSack(n,weights,values,w,arr);
} 
int main()
{
    int n, w;
    cout << "Enter the value of n" << endl;
    cin >> n;
    int *weights = new int[n];
    int *values = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }
    cout << "Enter maximum weight" << endl;
    cin >> w;
    cout << "Maximum value is " << KnapSack(n, weights, values, w) << endl;
    return 0;
}