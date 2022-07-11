#include <iostream>
#include <unordered_map> //storing the dictionary words in an unordered map
using namespace std; 
bool checkPartition(string s, int pos, unordered_map<string, bool> &s1)
{ //checking if my partition is correct or not
    if (pos == s.size())
    {
        return true;
    }
    for (int i = pos; i <= s.size(); i++)
    {
        if ((s1.find(s.substr(pos, i - pos + 1)) != s1.end()) && checkPartition(s.substr(i + 1), i + 1, s1))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    unordered_map<string, bool> dict;
    dict["i"] = 1;
    dict["like"] = 1;
    dict["sam"] = 1;
    dict["sung"] = 1;
    dict["samsung"] = 1;
    dict["mobile"] = 1;
    dict["ice"] = 1;
    dict["cream"] = 1;
    dict["icecream"] = 1;
    dict["man"] = 1;
    dict["go"] = 1;
    dict["mango"] = 1;
    cout << checkPartition("ilike", 0, dict);
    return 0;
}

//This recursive implementation is also right
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// // Function to determine if a string can be segmented into space-separated
// // sequence of one or more dictionary words
// bool wordBreak(vector<string> const &dict, string str)
// {
//     // return true if the end of the string is reached
//     if (str.size() == 0)
//     {
//         return true;
//     }

//     for (int i = 1; i <= str.size(); i++)
//     {
//         // consider all prefixes of the current string
//         string prefix = str.substr(0, i);

//         // return true if the prefix is present in the dictionary and the remaining
//         // string also forms a space-separated sequence of one or more
//         // dictionary words

//         if (find(dict.begin(), dict.end(), prefix) != dict.end() &&
//             wordBreak(dict, str.substr(i)))
//         {
//             return true;
//         }
//     }

//     // return false if the string can't be segmented
//     return false;
// }

// // Word Break Problem Implementation in C++
// int main()
// {
//     // vector of strings to represent a dictionary
//     // we can also use a Trie or a set to store a dictionary

//     vector<string> dict = {"this", "th", "is", "famous", "Word", "break",
//                            "b", "r", "e", "a", "k", "br", "bre", "brea", "ak", "problem"};

//     // input string
//     string str = "Wordbreakproblem";

//     if (wordBreak(dict, str))
//     {
//         cout << "The string can be segmented";
//     }
//     else
//     {
//         cout << "The string can't be segmented";
//     }

//     return 0;
// }