#include <iostream>
#include <cmath>
using namespace std;
int MinSteps(int n)
{   int x=INT_MAX,y=INT_MAX;
    //Brute Force Appro5ach
    //Base Case
    if (n <= 1)
    {
        return 0;
    }
    //Recursive call
    int z = MinSteps(n - 1);
    if (n%2==0){
        x=MinSteps(n/2);
    }
    if (n % 3 == 0)
    {
        y = MinSteps(n / 3);
    }
    int ans=min(x,min(y,z))+1;
    return ans;
}
int main()
{
    cout << MinSteps(10) << endl;
    return 0;
}