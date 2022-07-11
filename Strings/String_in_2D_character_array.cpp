#include <iostream>
using namespace std;
int StringFrom2DMatrix(char arr[][6], int i, int j, string s, int strIndex)
{
    int found = 0;
    int n = s.size();
    if (i >= 0 && j >= 0 && i < 6 && j < 6 && s[strIndex] == arr[i][j])
    {
        int temp = s[strIndex];
        arr[i][j] = '0';
        strIndex += 1;
        if (strIndex == n)
        { //We reach the end of string, base case
            found = 1;
        }
        else
        {
            found += StringFrom2DMatrix(arr, i + 1, j, s, strIndex);
            found += StringFrom2DMatrix(arr, i - 1, j, s, strIndex);
            found += StringFrom2DMatrix(arr, i, j + 1, s, strIndex);
            found += StringFrom2DMatrix(arr, i, j - 1, s, strIndex);
        }
        arr[i][j] = temp;
    } //backtrack
    return found;
}
int main()
{
    char arr[][6] = {{'B', 'B', 'M', 'B', 'B', 'B'}, {'C', 'B', 'A', 'B', 'B', 'B'}, {'I', 'B', 'G', 'B', 'B', 'B'}, {'G', 'B', 'I', 'B', 'B', 'B'}, {'A', 'B', 'C', 'B', 'B', 'B'}, {'M', 'C', 'I', 'G', 'A', 'M'}};
    string s = "MAGIC";
    int ans = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            ans += StringFrom2DMatrix(arr, i, j, s, 0);
        }
    }
    cout << ans << endl;
    return 0;
}