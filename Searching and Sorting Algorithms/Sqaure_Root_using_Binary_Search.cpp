#include <iostream>
using namespace std;
float IntegralPartOfSquareRoot(int arr[], int s, int e, int number, int precision)
{

    float ans;
    while (s <= (e - 1))
    {
        int mid = (s + e) / 2;
        if (arr[mid] * arr[mid] > number)
        {
            e = mid - 1;
        }
        if (arr[mid] * arr[mid] < number)
        {
            ans = mid;
            s = mid + 1;
        }
        if (arr[mid] * arr[mid] == number)
        {
            ans = mid;
        }
    }
    float increment = 0.1;
    for (int i = 0; i < precision; i++)
    {
        while (ans * ans <= number)
        {
            ans += increment;
        }
        ans = ans - increment;
        increment = increment / 10;
    }
    return ans;
}

int main()
{
    int number, precision;
    cout << "Enter the number" << endl;
    cin >> number;
    cout << "Enter the precision of decimal place" << endl;
    cin >> precision;
    int *arr = new int[number];
    for (int i = 0; i < number; i++)
    {
        arr[i] = i + 1;
    }
    float x = IntegralPartOfSquareRoot(arr, 0, number, number, precision);
    cout << "Integral part of the number " << number << " is " << x << endl;
    delete[] arr;
    return 0;
}