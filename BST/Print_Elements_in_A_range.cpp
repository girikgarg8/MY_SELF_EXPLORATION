#include <iostream>
#include <queue>
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
BinaryTreeNode *takeInput()
{
    int rootData;
    int leftchildData;
    int rightchildData;
    cout << "Enter the root data:" << endl;
    cin >> rootData;
    BinaryTreeNode *root = new BinaryTreeNode(rootData);
    queue<BinaryTreeNode *> q1;
    q1.push(root);
    while (!q1.empty())
    {
        BinaryTreeNode *leftChild;
        BinaryTreeNode *rightChild;
        BinaryTreeNode *a = q1.front();
        q1.pop();
        cout << "Enter the left child data"
             << " of " << a->data << endl;
        cin >> leftchildData;
        if (leftchildData == (-1))
        {
            leftChild = NULL;
        }
        else
        {
            leftChild = new BinaryTreeNode(leftchildData);
            q1.push(leftChild);
        }
        cout << "Enter the right child data"
             << " of" << a->data << endl;
        cin >> rightchildData;
        if (rightchildData == (-1))
        {
            rightChild = NULL;
        }
        else
        {
            rightChild = new BinaryTreeNode(rightchildData);
            q1.push(rightChild);
        }
        if (a != NULL)
        {
            a->left = leftChild;
            a->right = rightChild;
        }
    }
    return root;
}
void printLevelWise(BinaryTreeNode *root)
{
    queue<BinaryTreeNode *> q1;
    q1.push(root);
    while (!q1.empty())
    {
        BinaryTreeNode *a = q1.front();
        q1.pop();
        cout << endl;
        cout << a->data << ":";
        if (a->left != NULL)
        {
            cout << " L" << a->left->data;
            q1.push(a->left);
        }
        if (a->right != NULL)
        {
            cout << " R" << a->right->data;
            q1.push(a->right);
        }
    }
}
void searchElementsInRange(BinaryTreeNode *root, int min, int max)
{
    if (root == NULL)
    {
        return;
    }
    else if (root->data < max && root->data > min)
    {
        cout << root->data << endl;
        searchElementsInRange(root->left, min, max);
        searchElementsInRange(root->left, min, max);
    }
    else if ((root->data) > max)
    {
        searchElementsInRange(root->left, min, max);
    }
    else if (min > (root->data))
    {
        searchElementsInRange(root->right, min, max);
    }
}
int main()
{
    BinaryTreeNode *root = takeInput();
    printLevelWise(root);
    cout << "Elements in range 20 and 30 are:";
    searchElementsInRange(root, 20, 30);
    cout << "Elements in range 20 and 45 are:";
    searchElementsInRange(root, 20, 45);
    cout << "Elements in range 0 and 15 are:";
    searchElementsInRange(root, 0, 15);
    return 0;
}