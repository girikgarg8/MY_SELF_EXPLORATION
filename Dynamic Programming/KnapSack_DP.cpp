#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
int KnapSack(int n,int weights[],int values[],int w,int **arr,int rows,int columns){
    for (int i=0;i<columns;i++){
        arr[0][i]=0;
    }
    for (int j= 0; j <rows; j++)
    {
        arr[j][0] = 0;
    }
    for (int i=1;i<rows;i++){
        int a=INT_MIN;
        for (int j=1;j<columns;j++){
            if (weights[n-i]>j){
                arr[i][j]=arr[i-1][j]; 
            }
            else{
                if (j-weights[n-i]>=0){
                a=arr[i-1][j-weights[n-i]]+values[n-i];
                }
                int b=arr[i-1][j]; 
                arr[i][j]=max(a,b);
            } //The space complexity here is n*MaxWeight. We can reduce it to 2*MaxWeight
        }
    }
    return arr[rows-1][columns-1];
}
int KnapSack(int n, int weights[], int values[], int w)
{
    int a = n + 1; //rows
    int b = w + 1; // columns
    int **arr = new int *[b];
    for (int i = 0; i < b; i++)
    {
        arr[i] = new int[a];
    }
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            arr[i][j] = (-1);
        }
    }
    return KnapSack(n, weights, values, w, arr,a,b);
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