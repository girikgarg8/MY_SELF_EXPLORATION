#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
int MinCost(int **arr, int rows, int columns)
{   
    int **output = new int *[columns];
    for (int i = 0; i < rows; i++)
    {
        output[i] = new int[rows];
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            output[i][j] = (-1);
        }
    }
    output[rows-1][columns-1]=arr[rows-1][columns-1];
    for (int j=columns-2;j>=0;j--){
        output[rows-1][j]=output[rows-1][j+1]+arr[rows-1][j];
    }
    for (int j=rows-2;j>=0;j--){
        output[j][columns-1]=output[j+1][columns-1]+arr[j][columns-1];
    }
    for (int i=rows-2;i>=0;i--){
        for (int j=columns-2;j>=0;j--){
            output[i][j]=arr[i][j]+min(output[i+1][j],min(output[i][j+1],output[i+1][j+1]));
        }
    }
    return output[0][0];
}
int main()
{
    int rows, columns;
    cout << "Enter number of rows of matrix" << endl;
    cin >> rows;
    cout << "Enter number of columns of matrix" << endl;
    cin >> columns;
    int **arr = new int *[columns];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[rows];
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << MinCost(arr, rows, columns);
    return 0;
}