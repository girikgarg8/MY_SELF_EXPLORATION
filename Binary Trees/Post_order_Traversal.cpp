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
BinaryTreeNode *buildTreeHelper(int in[], int pr[], int prS, int prE, int inS, int inE)
{
    //Base case
    if (inS > inE)
    {
        return NULL;
    }
    int rootdata = pr[prS];
    int LinS = inS;
    int RprE = prE;
    int RinE = inE;
    int j = (-1); //loop variable
    int LprS = prS + 1;
    for (j = inS; j <= inE; j++)
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
    root->left = buildTreeHelper(in, pr, LprS, LprE, LinS, LinE);
    root->right = buildTreeHelper(in, pr, RprS, RprE, RinS, RinE);
    return root;
}
BinaryTreeNode *buildTree(int *in, int *pr, int size)
{
    return buildTreeHelper(in, pr, 0, size - 1, 0, size - 1);
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
int main()
{
    int pr[] = {1, 2, 3};
    int in[] = {2, 1, 3};
    BinaryTreeNode *root = buildTree(in, pr, 3);
    printLevelWise(root);
    return 0;
}