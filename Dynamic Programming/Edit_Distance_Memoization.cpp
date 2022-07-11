#include <iostream>
using namespace std;
int EditDistance(string s, string t, int **arr)
{
    int i = s.size();
    int j = t.size();
    //Base Case
    if (t.size() == 0 || s.size() == 0)
    {
        return max(s.size(), t.size());
    }
    int x, y, z, min_num;
    if (arr[i][j] != (-1))
    {
        return arr[i][j];
    }
    //Recursive Case
    if (s[0] == t[0])
    {
        arr[i][j] = EditDistance(s.substr(1), t.substr(1), arr);
        return arr[i][j];
    }
    else
    {
        x = 1 + EditDistance(s.substr(1), t, arr);
        y = 1 + EditDistance(s, t.substr(1), arr);
        z = 1 + EditDistance(s.substr(1), t.substr(1), arr);
        min_num = min(x, min(y, z));
        arr[i][j] = min_num;
    }
    return min_num;
}
int EditDistance(string s, string t)
{
    int a = s.size() + 1; //rows
    int b = t.size() + 1; //columns
    int **arr = new int *[b];
    for (int i = 0; i < b; i++)
    {
        arr[i] = new int[a];
    }
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cout << "Value of i is " << i << endl;
            cout << "Value of j is " << j << endl;
            arr[i][j] = (-1);
            cout << "Value of array is " << arr[i][j] << endl;
        }
    }
    return EditDistance(s, t, arr);
    delete[] arr;
}
int main()
{
    string s1, s2;
    cout << "Enter the two strings" << endl;
    cin >> s1 >> s2;
    cout << EditDistance(s1, s2) << endl;
    return 0;
}