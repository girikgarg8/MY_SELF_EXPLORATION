#include <iostream>
#include <string>
using namespace std;
// int calculateSize(int a){
//     int count=0;
//     while (n!=0){
//         a/=10;
//         count++;
//     }
//     return count;
// }
string intToString(int n)
{
    string s2;
    if (n == 0)
    {
        s2 = " zero";
        return s2;
    }
    if (n == 1)
    {
        s2 = " one";
        return s2;
    }
    if (n == 2)
    {
        s2 = " two";
        return s2;
    }
    if (n == 3)
    {
        s2 = " three";
        return s2;
    }
    if (n == 4)
    {
        s2 = " four";
        return s2;
    }
    if (n == 5)
    {
        s2 = " five";
        return s2;
    }
    if (n == 6)
    {
        s2 = " six";
        return s2;
    }
    if (n == 7)
    {
        s2 = " seven";
        return s2;
    }
    if (n == 8)
    {
        s2 = " eight";
        return s2;
    }
    if (n == 9)
    {
        s2 = " nine";
        return s2;
    }
    s2 = intToString(n / 10);
    s2 = s2 + intToString(n % 10);
    return s2;
}
int main()
{
    string s1 = intToString(2048);
    cout << s1;
    return 0;
}
