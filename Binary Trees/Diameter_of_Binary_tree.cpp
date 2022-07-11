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
        this->data;
        left = NULL;
        right = NULL;
    }
};
BinaryTreeNode *buildTreeHelper(int pr[], int in[], int size, int prS, int prE, int inS, int inE)
{
    //Base case
    if (inS > inE)
    {
        return;
    }
    int rootdata = pr[prS];
    int LinS = inS;
    int RprE = prE;
    int RinE = inE;
    int i, j; //loop variables
    for (i = 0; i < size; i++)
    {
        if (pr[i] == rootdata)
        {
            break;
        }
    }
    int LprS = i + 1;
    for (j = 0; j < size; j++)
    {
        if (in[j] == rootdata)
        {
            break;
        }
    }
    int LinE = j - 1;
    int RinS = j + 1;
    int LprE = LinE - LinS + LprS;
    int RprS = LprE + 1;
    BinaryTreeNode *root = new BinaryTreeNode(rootdata);
    root->left = buildTreeHelper(pr, in, size, LprS, LprE, LinS, LinE);
    root->left = buildTreeHelper(pr, in, size, RprS, RprE, RinS, RinE);
    return root;
}
BinaryTreeNode *buildTree(int pr[], int in[], int size)
{
    return buildTreeHelper(pr, in, size, 0, size - 1, 0, size - 1);
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
int height(BinaryTreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}
int DiameterOfBinaryTree(BinaryTreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int a = height(root->left) + height(root->right);
    int b = DiameterOfBinaryTree(root->left);
    int c = DiameterOfBinaryTree(root->right);
    return max(a, max(b, c));
}
int main()
{
    int pr[] = {1, 2, 5, 4, 3, 7, 9};
    int in[] = {5, 2, 4, 1, 7, 3, 9};
    BinaryTreeNode *root = buildTree(pr, in, 7);
    printLevelWise(root);
    return 0;
}