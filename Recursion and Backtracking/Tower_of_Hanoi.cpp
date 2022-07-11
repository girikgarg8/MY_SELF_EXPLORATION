#include <iostream>
using namespace std;
void Tower_of_Hanoi(char src, char helper, char dest, int n)
{
    //Base case
    if (n == 0)
    { //Try with n=1 also
        return;
    }
    Tower_of_Hanoi(src, dest, helper, n - 1);
    cout << "Move "
         << " disk " << n << " from" << src << " to " << dest << endl;
    Tower_of_Hanoi(helper, src, dest, n - 1);
}
int main()
{
    Tower_of_Hanoi('A', 'B', 'C', 3);
    return 0;
}