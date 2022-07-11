#include <iostream>
using namespace std;
bool columnOkay(int sudoku[][4], int column, int num)
{
    for (int i = 0; i < 4; i++)
    {
        if (sudoku[i][column] == num)
        {
            return false;
        }
    }
    return true;
}
bool rowOkay(int sudoku[][4], int row, int num)
{
    for (int i = 0; i < 4; i++)
    {
        if (sudoku[row][i] == num)
        {
            return false;
        }
    }
    return true;
}
bool boxOkay(int sudoku[][4], int row, int column, int num)
{
    int rowStart = row - row % 2; //this can be proved by taking two cases:one for even, one for odd
    int columnStart = column - column % 2;
    for (int i = rowStart; i < rowStart + 2; i++)
    {
        for (int j = columnStart; j < columnStart + 2; j++)
        {
            if (sudoku[i][j] == num)
            {
                return false;
            }
        }
    }
    return true;
}
bool isPermissible(int sudoku[][4], int row, int column, int num)
{
    if (!columnOkay(sudoku, column, num))
    {
        return false;
    }
    if (!rowOkay(sudoku, row, num))
    {
        return false;
    }
    if (!boxOkay(sudoku, row, column, num))
    {
        return false;
    }
    return true;
}
bool Sudoku_Solver(int sudoku[][4])
{ //Just like in the case of maze problem, if we have a single solution we can use a boolean return type
    int rowOfEmptyCell = -1;
    int columnOfEmptyCell = -1;
    bool isEmpty = false;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (sudoku[i][j] == 0)
            {
                rowOfEmptyCell = i;
                columnOfEmptyCell = j;
                isEmpty = true;
                break; //breaks the inner for loop
            }
        }
        if (isEmpty)
        {
            break; //We need to break the for loop at the first empty cell that we find in the sudoku
        }
    }
    if (!isEmpty)
    {
        return true;
    }
    for (int num = 1; num <= 4; num++)
    {
        if (isPermissible(sudoku, rowOfEmptyCell, columnOfEmptyCell, num))
        {
            sudoku[rowOfEmptyCell][columnOfEmptyCell] = num;
        if (Sudoku_Solver(sudoku))
        { //To check whether current board configuration is the final solution or not
            return true;
        }
        sudoku[rowOfEmptyCell][columnOfEmptyCell] = 0;
    }
    //In case we are not able to insert any of the elements at the given cell, we need to set its value to 0
}
    return false;
}
int main()
{
    int sudoku[4][4] = {{1, 3, 0, 4}, {
                                          2,
                                          0,
                                          3,
                                          1,
                                      },
                        {0, 1, 0, 2},
                        {4, 0, 1, 0}};
    cout << Sudoku_Solver(sudoku) << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}