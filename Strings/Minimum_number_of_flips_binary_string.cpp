#include <iostream>
using namespace std;
char flip(char ch)
{
    if (ch == '0')
    {
        return '1';
    }
    return '0';
}
int flipCount(string str, char expected)
{
    int flipCount = 0;
    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        if (str[i] != expected)
        {
            flipCount++;
        }
        expected = flip(expected);
    }
    return flipCount;
}
int minFlipCount(string str)
{
    int a = flipCount(str, '0');
    int b = flipCount(str, '1');
    return min(a, b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str = "0001010111";
    cout << minFlipCount(str);
    return 0;
}