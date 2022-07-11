#include <iostream> //Solving for 3*3 maze
using namespace std;
void isMazeSolvable(int arr[][3], int i, int j, int path[][3])
{
    if (i < 0 || j < 0 || i >= 3 || j >= 3)
    {
        return;
    }
    if (i == 2 && j == 2)
    {
        path[i][j] = 1;
        for (int i = 0; i <= 2; i++)
        {
            for (int j = 0; j <= 2; j++)
            {
                cout << path[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    if (arr[i][j] == 0 || path[i][j] == 1)
    { //path[i][j]==1 signifies that the the path has already been visited, so we don't have to visit it again
        return;
    }
    path[i][j] = 1;
    (isMazeSolvable(arr, i, j + 1, path));
    (isMazeSolvable(arr, i, j - 1, path));
    (isMazeSolvable(arr, i + 1, j, path));
    (isMazeSolvable(arr, i - 1, j, path));
    path[i][j] = 0;
    return;
}
void isMazeSolvable(int arr[][3])
{
    int path[3][3] = {0};
    isMazeSolvable(arr, 0, 0, path);
}
int main()
{
    int maze[][3] = {{1, 1, 0}, {1, 1, 0}, {0, 1, 1}};
    isMazeSolvable(maze);
    return 0;
}