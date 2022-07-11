#include <iostream>
using namespace std;
int MedianOfTwoArrays(int a[], int b[], int n)
{
    int m1 = (-1); // lazy variable, always stores the values of m2
    int m2 = (-1); //lazy-active concept
    int i = 0; //pointer in array a
    int j = 0; //pointer in array b
    for (int u = 0; u <= n; u++)
    { //Notice carefully u<=n
        if (i == n)
        {
            m1 = m2;
            m2 = b[0];
            break;
        }
        if (j == n)
        {
            m1 = m2;
            m2 = a[0];
            break;
        }
        if (a[i] >= b[j])
        {
            m1 = m2;
            m2 = b[j];
            j++;
        }
        if (a[i] < b[j])
        {
            m1 = m2;
            m2 = a[i]; //Pick the smaller element
            i++;
        }
    }
    return (m1 + m2) / 2;
}
int main()
{
    int arr[] = {1, 4, 2, 6};
    int arr1[] = {8, 11, 13, 12};
    cout << MedianOfTwoArrays(arr, arr1, 4) << endl;
    return 0;
}