#include <iostream>
#include <string>
using namespace std;
class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;
    TrieNode(char data)
    {
        this->data = data;
        isTerminal = false;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};
//class Trie for the user, TrieNode is for the internal working
class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
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
    bool search(TrieNode *root, string word)
    {
        TrieNode *child;
        // Base Case
        if (word.length() == 0)
        {
            return root->isTerminal;
        }
        int index = word[0] - 'a';
        if (root->children[index] == NULL)
        {
            return false;
        }
        else
        {
            child = root->children[index];
        }
        //Small calculation part
        return search(child, word.substr(1)); //As function's return type is non-void,we need to return the recursive call
        //Recursive call
    }
    bool search(string word)
    {
        return search(root, word); //As function's return type is non-void, we have to return the recursive call
    }
    void removeWord(TrieNode *root, string word)
    {
        TrieNode *child;
        //Base case
        if (word.length() == 0)
        {
            root->isTerminal = false;
            return;
        }
        int index = word[0] - 'a';
        if (root->children[index] == NULL)
        {
            return;
        }
        else
        {
            child = root->children[index];
        }
        // Small calculation part
        removeWord(child, word.substr(1));
        // Recursive call
        if (child->isTerminal == false)
        {
            for (int i = 0; i < 26; i++)
            {
                if (child->children[i] != NULL)
                {
                    return;
                }
            }
            delete child;
            root->children[index] = NULL;
        }
    }
    void removeWord(string word)
    {
        removeWord(root, word);
    }
};
int main()
{
    Trie t1;
    t1.insertWord("are");
    t1.insertWord("and");
    t1.insertWord("dot");
    cout << t1.search("and") << endl;
    t1.removeWord("and");
    cout << t1.search("and") << endl;
    return 0;
}