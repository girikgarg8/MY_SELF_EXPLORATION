#include <iostream>
using namespace std;
#define ALPHABET_SIZE 26
class TrieNode
{
public:
    bool isTerminal;
    char value;
    int wordCount;
    TrieNode **children;
    TrieNode(char data)
    {
        wordCount = 1;
        value = data;
        isTerminal = false;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};
class Trie
{
    TrieNode *root;
    string LCP = "";
    int n; //number of strings
public:
    Trie(int n)
    {
        this->n = n;
        root = new TrieNode('\0');
        root->wordCount = (-1);
    }
    //Fucntion for the internal function call
    void insertWord(TrieNode *root, string word)
    {

        //Base Case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        //Small calculation part
        int position = word[0] - 'a';
        TrieNode *node;
        if (root->children[position] != NULL)
        {
            node = root->children[position];
            node->wordCount = node->wordCount + 1;
        }
        else
        {
            node = new TrieNode(word[0]);
            root->children[position] = node;
        }
        // Recursive call
        insertWord(node, word.substr(1));
    }
    //For the user
    void insertWord(string word)
    {
        insertWord(root, word);
    }
    string findLCP(TrieNode *root)
    {
        if (root->wordCount == n)
        {
            LCP = LCP + root->value;
        }
        if (root->isTerminal)
        {
            return LCP;
        }
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i] != NULL)
            {
                findLCP(root->children[i]);
            }
        }
        return LCP;
    }
    string findLCP()
    {
        return findLCP(root);
    }
};
int main()
{
    Trie t1(3);
    t1.insertWord("apple");
    t1.insertWord("apps");
    t1.insertWord("ape");
    string a = t1.findLCP();
    cout << a << endl;
    return 0;
}
