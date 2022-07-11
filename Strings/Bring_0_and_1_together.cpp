#include <iostream>
using namespace std;
int main()
{
    int count_zero = 0;
    int count_one = 0;
    int count = 0;
    string s = "0111100010";
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (count_zero == count_one && count_zero != 0)
        {
            count++;
            count_zero = 0;
            count_one = 0;
        }
        if (s[i] == '0')
        {
            count_zero += 1;
        }
        else if (s[i] == '1')
        {
            count_one += 1;
        }
    }
    if (count_zero == count_one && count_zero != 0)
    {
        count++;
        count_zero = 0;
        count_one = 0;
    }
    cout << count << endl;
    return 0;
}