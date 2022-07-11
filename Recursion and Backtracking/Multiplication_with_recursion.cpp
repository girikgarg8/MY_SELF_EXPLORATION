#include <iostream>
using namespace std;
int multiply(int a, int b)
{
    int smallAns;
    if (a == 0 || b == 0)
    {
        return 0;
    }
    if (b == 1)
    {
        return a;
    }
    if (b > 0)
    {
        smallAns = multiply(a, b - 1);
        return a + smallAns;
    }
    else if (b < 0)
    {
        int k = -b;
        smallAns = multiply(a, k - 1);
        return -(a + smallAns);
    }
}
int main()
{
    cout << multiply(5, 2) << endl;
    cout << multiply(5, -2) << endl;
    cout << multiply(-5, 2) << endl;
    cout << multiply(-2, -5) << endl;
}