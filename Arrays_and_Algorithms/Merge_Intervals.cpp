#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> mergeInterval(vector<vector<int>> &intervals)
{
    vector<vector<int>> mergedIntervals;
    vector<int> currentInterval = intervals[0];
    for (auto it : intervals)
    {
        if (it[0] <= currentInterval[1])
        {                                                        //it is ahead of currentInterval gen
            currentInterval[1] = max(currentInterval[1], it[1]); //The current interval is becoming large eg, 1-2 and 3-6 becomes 1-6
        }                                                        //Means merging subintervals are there
        else
        {
            mergedIntervals.push_back(currentInterval);
            currentInterval = it; //Start making new intervals from this point
        }
    }
    mergedIntervals.push_back(currentInterval); //This step is needed becuase for the last interval, the if condition wouldn't execute because there is no further interval to make comparison with
    return mergedIntervals;
}
int main()
{
    vector<vector<int>> v1;
    v1.push_back({1, 3});
    v1.push_back({2, 6});
    v1.push_back({8, 10});
    v1.push_back({15, 18});
    vector<vector<int>> answer = mergeInterval(v1);
    for (auto it : answer)
    {
        cout << it[0] << " " << it[1] << endl;
    }
    return 0;
}