#include <iostream>
#include <queue>
#include <map>
#include <climits>
using namespace std;
class BinaryTreeNode
{
public:
    int data;
    map<BinaryTreeNode *, BinaryTreeNode *> parent;
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
vector<int> *RootToNodePath(BinaryTreeNode *root, int element)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == element)
    {
        vector<int> *arr = new vector<int>();
        arr->push_back(root->data);
        return arr;
    }
    vector<int> *x = RootToNodePath(root->left, element);
    if (x != NULL)
    {
        x->push_back(root->data);
    }
    vector<int> *y = RootToNodePath(root->right, element);
    if (y != NULL)
    {
        y->push_back(root->data);
    }
    else
        return NULL;
}
int main()
{
    BinaryTreeNode *root = takeInput();
    vector<int> *output = RootToNodePath(root, 8);
    for (int i = 0; i < output->size(); i++)
    {
        cout << output->at(i);
    }
    return 0;
}