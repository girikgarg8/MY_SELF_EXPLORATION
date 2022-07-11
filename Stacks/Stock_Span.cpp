#include <iostream>
#include <stack>
using namespace std;
int *StockSpan(int arr[], int n)
{
    stack<int> s1;
    int *output = new int[n];
    s1.push(0);
    for (int i = 0; i < n; i++)
    {
        output[i] = 1;
        if (i >= 1)
        {
            if (arr[i] > arr[s1.top()])
            {
                while (!s1.empty() && arr[i] > arr[s1.top()])
                {
                    int a = s1.top();
                    output[i] += output[a];
                    s1.pop();
                }
            }
            s1.push(i);
        }
    }
    return output;
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int *ans = StockSpan(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}