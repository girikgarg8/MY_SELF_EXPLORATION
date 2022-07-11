  #include <iostream>
#include <queue>
#include <climits>
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
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};
class BST
{
public:
    BinaryTreeNode *root;
    BST()
    {
        root = NULL;
    }
    BinaryTreeNode *insertElement(BinaryTreeNode *node, int data)
    {
        if (node == NULL)
        {
            BinaryTreeNode *newNode = new BinaryTreeNode(data);
            return newNode;
        }
        if (data < root->data)
        {
            node->left = insertElement(root->left, data);
        }
        if (data > root->data)
        {
            node->right = insertElement(root->right, data);
        }
        return node;
    }
    BinaryTreeNode *findMinElementInRightSubtree(BinaryTreeNode *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        return findMinElementInRightSubtree(root->left);
    }
    BinaryTreeNode *removeElement(BinaryTreeNode *root, int data)
    {
        if (root == NULL)
        {
            return NULL;
        }
        else if (root->data > data)
        {
            root->left = removeElement(root->left, data);
        }
        else if (root->data < data)
        {
            root->right = removeElement(root->right, data);
        }
        else if (root->right == NULL && root->left == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->right == NULL)
        {
            BinaryTreeNode *temp = root->left;
            root->left = NULL;
            return temp;
        }
        else if (root->left == NULL)
        {
            BinaryTreeNode *temp = root->right;
            root->right = NULL;
            return temp;
        }
        else if (root->left != NULL && root->right != NULL)
        {
            BinaryTreeNode *a = findMinElementInRightSubtree(root->right);
            root->data = a->data;
            root->right = removeElement(root->right, a->data);
            return root;
        }
    }
    BinaryTreeNode *removeElement(int data)
    {
        return removeElement(root, data);
    }
    BinaryTreeNode *insertElement(int data)
    {
        this->root = insertElement(root, data);
        return root;
    }
    bool hasData(BinaryTreeNode *node, int search)
    {
        bool x, y;
        if (node == NULL)
        {
            return false;
        }
        if (node->data == search)
        {
            return true;
        }
        else if (search > node->data)
        {
            return hasData(node->right, search);
        }
        else
            return hasData(node->left, search);
    }
    bool hasData(int search)
    {
        return hasData(root, search);
    }
    ~BST()
    {
        delete root;
    }
};
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
};
int main()
{
    BST b1;
    b1.insertElement(10);
    b1.insertElement(5);
    b1.insertElement(20);
    b1.insertElement(7);
    b1.insertElement(3);
    BinaryTreeNode *e = b1.insertElement(5);
    printLevelWise(e);
    return 0;
}