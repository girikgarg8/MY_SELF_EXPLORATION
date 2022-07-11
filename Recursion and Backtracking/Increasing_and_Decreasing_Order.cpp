#include <iostream>
using namespace std;
void printInDecreasingOrder(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << " ";
    printInDecreasingOrder(n - 1);
}
void printInIncreasingOrder(int n)
{
    if (n == 0)
    {
        return;
    }
    printInIncreasingOrder(n - 1);
    cout << n << " ";
}
int main()
{
    printInDecreasingOrder(5);
    cout << endl;
    printInIncreasingOrder(5);
    return 0;
}