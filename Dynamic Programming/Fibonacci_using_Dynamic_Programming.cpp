#include <iostream>
using namespace std;
int helper(int *arr, int n)
{
    arr[0]=0;
    arr[1]=1;
    for (int i = 2; i <= n; i++)
    {
       arr[i]=arr[i-1]+arr[i-2];
}
return arr[n];
}
int fibonacci(int n)
{
    int *arr = new int[n + 1];
    return helper(arr, n);
}
int main()
{
    cout << fibonacci(6) << endl;
    return 0;
}