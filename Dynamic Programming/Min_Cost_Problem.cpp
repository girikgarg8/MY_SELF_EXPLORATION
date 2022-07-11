#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
int MinCost(int **arr,int rows,int columns, int i,int j){
    //Here i and j represent current index, we can't use 00 instead of arr[i][j] because current indexes i and j are given
    //Base case
    int x=INT_MAX,y=INT_MAX,z=INT_MAX;
    if (i==rows-1 && j==columns-1){
        return arr[i][j];
    }
    //Recursive calls
    if (i+1<rows && j<columns){
    x=MinCost(arr,rows,columns,i+1,j);
    }
    if (i< rows && j+1 <columns)
    {
        y = MinCost(arr, rows, columns, i, j + 1);
    }
    if (i+1<rows && j+1<columns){
        z = MinCost(arr, rows, columns, i + 1, j + 1);
    }
    int ans=min(x,min(y,z))+arr[i][j];
    return ans;
    }
int MinCost(int **arr,int rows,int columns){
    //This function will internally call another function
    return MinCost(arr,rows,columns,0,0);
    //Recursive Calls
    // int x=MinCost(arr[][columns],rows-1,columns);
    // int y=MinCost(arr[][columns-1],rows,columns-1);
    // int z=MinCost(arr[][columns-1],rows-1,columns-1);
    // int u=min(x,min(y,z))+arr[0][0];
    //Wrong we have defined rows and columns according to original matrix, but we are making our own matrix 
}
int main(){
    int rows,columns;
    cout << "Enter number of rows of matrix" <<endl;
    cin>>rows;
    cout << "Enter number of rows of matrix" <<endl;
    cin >> columns;
    int **arr=new int *[columns];
    for (int i=0;i<rows;i++){
        arr[i]=new int[rows];
    }
    for (int i=0;i<rows;i++){
        for (int j=0;j<columns;j++){
            cin>>arr[i][j];
        }
    }
    cout << MinCost(arr,rows,columns);
    return 0;               
}