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
BinaryTreeNode *searchinBST(BinaryTreeNode *root, int a)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (a == (root->data))
    {
        return root;
    }
    else if (a > (root->data))
    {
        return searchinBST(root->right, a);
    }
    else if (a < (root->data))
    {
        return searchinBST(root->left, a);
    }
}
int main()
{
    BinaryTreeNode *root = takeInput();
    printLevelWise(root);
    BinaryTreeNode *ans = searchinBST(root, 15);
    BinaryTreeNode *ans1 = searchinBST(root, 4);
    cout << "ans is " << ans->data << endl;
    cout << "ans1 is" << ans1->data << endl;
    return 0;
}