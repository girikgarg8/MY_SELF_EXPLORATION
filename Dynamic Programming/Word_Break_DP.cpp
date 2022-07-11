#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void wordBreak (vector <string> &dict,string word,string out){
    if (word.size() == 0)
    {
        cout << out << endl;
        return;
    }
    for (int i = 1; i <= word.size(); i++)
    {
        // consider all prefixes of the current string
        string prefix = word.substr(0, i);
    if (find(dict.begin(), dict.end(), prefix) != dict.end()) {
        wordBreak(dict, word.substr(i), out + " " + prefix);
    }
}
}
    int main()
{
    // vector of strings to represent a dictionary
    // we can also use a Trie or a set to store a dictionary
 
    vector<string> dict = { "this", "th", "is", "famous", "Word", "break",
            "b", "r", "e", "a", "k", "br", "bre", "brea", "ak", "problem" };
    string word = "Wordbreakproblem";
 
    wordBreak(dict, word, "");
}
/*

bool wordBreak(vector<string> const &dict, string word)
{
    // return true if the end of the string is reached
    if (word.size() == 0) {
        return true;
    }
 
    for (int i = 1; i <= word.size(); i++)
    {
        // consider all prefixes of the current string
        string prefix = word.substr(0, i);
 
        // return true if the prefix is present in the dictionary and the remaining
        // string also forms a space-separated sequence of one or more
        // dictionary words
 
        if (find(dict.begin(), dict.end(), prefix) != dict.end() &&
                wordBreak(dict, word.substr(i))) {
            return true;
        }
    }
 
    // return false if the string can't be segmented
    return false;
}
 *
/

/*
Memoization
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
// Function to determine if a string can be segmented into space-separated
// sequence of one or more dictionary words
bool wordBreak(vector<string> const &dict, string word,vector<int> &lookup)
{
    // return true if the end of the string is reached
    if (word.size() == 0) {
        return true;
    }
    if (lookup[word.size()]!=-1){
        return lookup[word.size()];
    }
    for (int i = 1; i <= word.size(); i++)
    {
        // consider all prefixes of the current string
        string prefix = word.substr(0, i);
 
        // return true if the prefix is present in the dictionary and the remaining
        // string also forms a space-separated sequence of one or more
        // dictionary words
 
        if (find(dict.begin(), dict.end(), prefix) != dict.end() &&
                wordBreak(dict, word.substr(i),lookup)) {
            return lookup[word.size()]=true;
        }
    }
 
    // return false if the string can't be segmented
    return lookup[word.size()]=false;
}
 
// Word Break Problem Implementation in C++
int main()
{
    // vector of strings to represent a dictionary
    // we can also use a Trie or a set to store a dictionary
 
    vector<string> dict = { "this", "th", "is", "famous", "Word", "break",
            "b", "r", "e", "a", "k", "br", "bre", "brea", "ak", "problem" };
 
    // input string
    string word = "Wordbreakproblem";
    
    vector <int>lookup(word.size()+1,-1);
    if (wordBreak(dict, word,lookup)) {
        cout << "The string can be segmented";
    }
    else {
        cout << "The string can't be segmented";
    }
 
    return 0;
}
*/