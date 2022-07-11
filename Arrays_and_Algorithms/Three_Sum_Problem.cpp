#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> ThreeSum(vector<int> &arr, int k)
{
    int n = arr.size();
    int low;
    int high;
    sort(arr.begin(), arr.end());
    vector<vector<int>> answer; //using a vector instead of set to reduce time complexity
    for (int i = 0; i < n - 2; i++)
    {
        if (i == 0 || arr[i] != arr[i - 1])
        { //I need to make sure that my starting element is also unique, it's not repeated
            int sum = k - arr[i];
            low = i + 1;
            high = n - 1; //not n-i-1
            while (low < high)
            {
                if ((arr[low] + arr[high] == sum))
                {
                    answer.push_back({arr[i], arr[low], arr[high]}); //We are pushing it in the sorted manner
                    while (low < high && arr[low] == arr[low + 1])
                    {
                        low++;
                    }
                    while (low < high && arr[high] == arr[high - 1])
                    {
                        high--;
                    }
                    low++;
                    high--;
                }
                else if ((arr[low] + arr[high] < sum))
                {
                    low++;
                }
                else
                {
                    high--;
                }
            }
        }
    }
    return answer;
}
int main()
{
    vector<int> arr = {-2, -2, -1, -1, -1, 0, 0, 0, 2, 2, 2};
    vector<vector<int>> ans = ThreeSum(arr, 0);
    for (auto i : ans)
    {
        cout << i[0] << " " << i[1] << " " << i[2];
        cout << endl;
    }
    return 0;
}