#include<iostream>
#include <string>
#include <cmath>
    using namespace std;
int convertString(string a)
{
    if (a.size() == 0)
    {
        return 0;
    }
    int x = convertString(a.substr(1));
    int num = a[0] - '0';
    return x + num * pow(10, a.size() - 1);
}
int main()
{
    int a = convertString("12354");
    cout << a << endl;
}
