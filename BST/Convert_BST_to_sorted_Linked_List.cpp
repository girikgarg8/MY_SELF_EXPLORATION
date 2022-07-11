#include <iostream>
#include <climits>
#include <queue>
#include "BinaryTreeNode.h"
TreeNode *takeInput()
{
    int rootData;
    int leftchildData;
    int rightchildData;
    cout << "Enter the root data:" << endl;
    cin >> rootData;
    TreeNode *root = new TreeNode(rootData);
    queue<TreeNode *> q1;
    q1.push(root);
    while (!q1.empty())
    {
        TreeNode *leftChild;
        TreeNode *rightChild;
        TreeNode *a = q1.front();
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
            leftChild = new TreeNode(leftchildData);
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
            rightChild = new TreeNode(rightchildData);
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
void printLevelWise(TreeNode *root)
{
    queue<TreeNode *> q1;
    q1.push(root);
    while (!q1.empty())
    {
        TreeNode *a = q1.front();
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
class LinkedListNode{
    public:
    int data;
    LinkedListNode *next;
    LinkedListNode(int val){
        this->data=val;
        this->next=NULL;
    }
};
LinkedListNode * convertToLL(TreeNode *root){
    if (root==NULL){
        return NULL;
    }
    LinkedListNode * left=convertToLL(root->left);
    LinkedListNode * right=convertToLL(root->right);
    LinkedListNode *rootNode=new LinkedListNode(root->data);
    if (left!=NULL){
    LinkedListNode *temp=left;
    while (temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=rootNode;
    }
    rootNode->next=right;
    if (left!=NULL){
        return left;
    }
    return rootNode;
}
int main()
{
    TreeNode *root = takeInput();


    return 0;
}