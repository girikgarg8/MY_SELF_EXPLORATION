#include <iostream> //1 represnts presence of queen in the board
using namespace std;
bool checkIsQueenSafe(int board[][10], int n, int i, int j)
{
    //where i represents the row number of current element I am checking, and j represents the column number of element I am checking
    if (i >= n || j >= n || i < 0 || j < 0)
    {
        return false;
    }
    for (int u = 0; u < n; u++)
    {
        if (board[i][u] == 1)
        {
            return false;
        } //Checking in the row
    }
    for (int u = 0; u < n; u++)
    {
        if (board[u][j] == 1)
        {
            return false;
        } //Checking in the columns
        int x = i;
        int y = j;
        while (x >= 0 && y >= 0 && x < n && y < n)
        {
            if (board[x][y] == 1)
            {
                return false; //Checking in left diagonal
            }
            x--;
            y--;
        }
        x = i;
        y = j;
        while (x > 0 && y > 0 && x < n && y < n)
        {
            if (board[x][y] == 1)
            {
                return false; //Checking in left diagonal
            }
            x--;
            y++;
        }
    }
    return true;
}
bool NQueen(int board[10][10], int rowIndex, int n)
{
    if (rowIndex == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 0)
                {
                    cout << " _ ";
                }
                if (board[i][j] == 1)
                {
                    cout << " Q ";
                }
            }
            cout << endl;
        }
        return true;
    }
    for (int j = 0; j < n; j++)
    { //j runs a loop for columnIndex
        if (checkIsQueenSafe(board, n, rowIndex, j))
        {
            board[rowIndex][j] = 1; //Insert a queen at this position assuming it is safe
            //I need to check through recursive call whether nextrow queen can be placed or not.
            if (NQueen(board, rowIndex + 1, n))
            {
                return true;
            }                       //Means we are able to place the queens in next rows as well
            board[rowIndex][j] = 0; //else we backtrack and set it as 0
        }
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    int board[10][10] = {0};
    NQueen(board, 0, n);
    return 0;
}