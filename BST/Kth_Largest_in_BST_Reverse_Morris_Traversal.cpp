#include <bits/stdc++.h>
using namespace std;
class BinaryTreeNode{
    public:
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode *right;
    BinaryTreeNode(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
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
int KthLargest(BinaryTreeNode *root,int k){
    vector <int> inorder;
    BinaryTreeNode *cur=root;
    int count=0;
    while (cur!=NULL){ //this used to be the base case of my inorder traversal
    if (cur->right==NULL){
        count++;
        if (count==k){
            return cur->data;
        }
        cur=cur->left;
    }
    else{
        BinaryTreeNode *prev=cur->right;
        while (prev->left!=NULL && prev->left!=cur){
            prev=prev->left;
        }
             //prev->right!=cur is needed for the case when there sis already an existing thread
            if (prev->left==NULL){
                prev->left=cur; //creating the thread
                cur=cur->right;
            }
            else{
                prev->left=NULL;
                count++;
                if (count==k){
                return cur->data;
                }
                cur=cur->left;
            }
        }
    }
    cout << "Given BST has less than k elements\n";
}
int main(){
    BinaryTreeNode *root=takeInput();
    int k;
    cin>>k;
    cout << KthLargest(root,k) <<endl;
    return 0;
}