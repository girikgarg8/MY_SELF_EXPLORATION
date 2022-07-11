#include <iostream>
#include <vector>
using namespace std;
vector<int> occurencesInPattern(26, 0);
vector<int> OccurencesInString(26, 0);
int countOccurences(string s1, string s2)
{
    int answer = 0;
    int l2 = s2.size();
    int l1 = s1.size();
    for (int i = 0; i < l2; i++)
    {
        occurencesInPattern[s2[i] - 'a'] += 1;
    }
    int i = 0;
    int j = 0;
    int k = l2;
    while (j < l1)
    {
        if ((j - i + 1) < k)
        {
            OccurencesInString[s1[j] - 'a'] += 1;
            j++;
        }
        if ((j - i + 1) == k)
        {
            if (j < l1)
            {
                OccurencesInString[s1[j] - 'a'] += 1;
            }
            if (OccurencesInString == occurencesInPattern)
            {
                answer++;
                //     cout << "Here " <<endl;
                //     cout << "Values of i and j which have lead to the answer are" << i << " and" << j <<endl;
            }
            OccurencesInString[s1[i] - 'a'] = 0;
            i++;
            j++;
        }
    }
    return answer;
}
using namespace std;
int main()
{
    string s1 = "abcdecdbacb";
    string s2 = "cab";
    cout << "Count of occurences is " << countOccurences(s1, s2);
    return 0; //Expected answer is 3
}