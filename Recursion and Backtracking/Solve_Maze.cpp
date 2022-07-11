#include <iostream> //Solving for 3*3 maze
using namespace std;
bool isMazeSolvable(int arr[][3], int i, int j, int path[][3])
{
    if (i < 0 || j < 0 || i >= 3 || j >= 3)
    {
        return false;
    }
    if (i == 2 && j == 2)
    {
        return true;
    }
    if (arr[i][j] == 0 || path[i][j] == 1)
    { //path[i][j]==1 signifies that the the path has already been visited, so we don't have to visit it again
        return false;
    }
    path[i][j] = 1;
    if (isMazeSolvable(arr, i, j + 1, path))
    {
        path[i][j] = 0; //This step is needed to reset path value to zero, in case I need to find all possible paths
        return true;
    }
    if (isMazeSolvable(arr, i, j - 1, path))
    {
        path[i][j] = 0;
        return true;
    }
    if (isMazeSolvable(arr, i + 1, j, path))
    {
        path[i][j] = 0;
        return true;
    }
    if (isMazeSolvable(arr, i - 1, j, path))
    {
        path[i][j] = 0;
        return true;
    }
    return false;
}
bool isMazeSolvable(int arr[][3])
{
    int path[3][3] = {0};
    return isMazeSolvable(arr, 0, 0, path);
}
int main()
{
    int maze[][3] = {{1, 1, 0}, {0, 1, 0}, {0, 1, 1}};
    cout << isMazeSolvable(maze);
    return 0;
}