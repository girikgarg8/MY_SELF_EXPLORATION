#include <bits/stdc++.h>
using namespace std;
class BinaryTreeNode
{
public:
    int data;
    int rCount;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        rCount=0;
    }
};
BinaryTreeNode *insert(BinaryTreeNode *root,int key){
    if (root==NULL){
        BinaryTreeNode *newNode=new BinaryTreeNode(key);
        return newNode;
    }
    if (key<root->data){
        root->left=insert(root->left,key);
    }
    else if (key > root->data){
        root->right = insert(root->right, key);
        root->rCount++;
    }
    return root;
}
BinaryTreeNode* kthLargest(BinaryTreeNode* root, int k)
{
    // base case
    if (root == NULL)
        return NULL;
 
    int count = root->rCount + 1;
    if (count == k)
        return root;
 
    if (count>k)
        return kthLargest(root->right, k);
 
    // else search in left subtree
    return kthLargest(root->left,k-count);
}
int main()
{
    BinaryTreeNode* root = NULL;
    int keys[] = { 20, 8, 22, 4, 12, 10, 14 };
 
    for (int x : keys)
        root = insert(root, x);
 
    int k = 4;
    BinaryTreeNode* res = kthLargest(root, k);
    if (res == NULL)
        cout << "There are less than k nodes in the BST";
    else
        cout << "K-th Largest Element is " << res->data;
    return 0;
}