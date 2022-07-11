#include <iostream>
#include <cmath>
using namespace std;
int LRS_DP(string s1, string s2)
{
    int a = s1.size();
    int b = s2.size();
    int rows = a + 1;
    int columns = b + 1;
    int **output = new int *[columns];
    for (int i = 0; i < columns; i++)
    {
        output[i] = new int[rows];
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            output[i][j] = -1;
        }
    }
    for (int j = 0; j < columns; j++)
    {
        output[0][j] = 0;
    }
    for (int j = 0; j < rows; j++)
    {
        output[j][0] = 0;
    }
    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < columns; j++)
        {
            if (s1[s1.size()-i] == s2[s2.size()-j] && (s1.size()-i)!=(s2.size()-j))
            { //this would be wrong: s1[i]==s2[j]
                output[i][j] = output[i - 1][j - 1] + 1;
            }
            else
            {
                int a = output[i][j - 1];
                int b = output[i - 1][j];
                int c = output[i - 1][j - 1];
                int d = max(a, max(b, c));
                output[i][j] = d;
            }
        }
    }
    return output[rows - 1][columns - 1];
};
int main()
{
    string s, t;
    cin >> s;
    cout << LRS_DP(s,s) << endl;
    return 0;
}
