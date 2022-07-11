#include <iostream>
using namespace std;
class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
void printRecursive(BinaryTreeNode *root)
{
    // Wanted output 1: L2 R3 2: 3:
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ": ";
    if (root->left != NULL)
    {
        cout << "L" << root->left->data;
    }
    if (root->left != NULL)
    {
        cout << "R" << root->right->data;
    }
    cout << endl;
    printRecursive(root->left);
    printRecursive(root->right);
}
BinaryTreeNode *takeInput()
{
    int rootData;
    cout << "Enter the data:" << endl;
    cin >> rootData;
    if (rootData == (-1))
    {
        return NULL;
    }
    BinaryTreeNode *rootnode = new BinaryTreeNode(rootData);
    BinaryTreeNode *leftnode = takeInput();
    BinaryTreeNode *rightnode = takeInput();
    rootnode->left = leftnode;
    rootnode->right = rightnode;
    return rootnode;
}
int main()
{
    BinaryTreeNode *BinaryTreeRoot = takeInput();
    printRecursive(BinaryTreeRoot);
    return 0;
}
