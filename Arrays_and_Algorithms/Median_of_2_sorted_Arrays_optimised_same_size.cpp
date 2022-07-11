#include <iostream>
using namespace std;
float medianOfSingleArray(int arr[], int s, int e)
{
    return (arr[(s + e) / 2] + arr[(s + e + 1) / 2]) / 2;
}
float medianOfBothArrays(int a[], int b[], int sA, int eA, int sB, int eB)
{
    if (eA - sA <= 1 && eB - sB <= 1)
    {
        return (min(a[eA], b[eB]) + max(a[sA], b[sB])) / (2.0);
    }
    float m1 = medianOfSingleArray(a, sA, eA);
    float m2 = medianOfSingleArray(b, sB, eB);
    if (m1 == m2)
    {
        return m1;
    }
    if (m1 > m2)
    {
        return medianOfBothArrays(a, b, sA, (sA + eA + 1) / 2, (sB + eB + 1) / 2, eB);
    }
    return medianOfBothArrays(a, b, (sA + eA + 1) / 2, eA, sB, (sB + eB + 1) / 2);
}
int main()
{
    int arr1[] = {1, 4, 2, 6};
    int arr2[] = {7, 10, 9, 8};
    cout << "Median is " << medianOfBothArrays(arr1, arr2, 0, 3, 0, 3);
    return 0;
}