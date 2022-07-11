#include <iostream>
#include <queue>
#include <vector>
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
    ~BinaryTreeNode(){
        delete left;
        delete right;
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
void leftBoundary(BinaryTreeNode *root,vector <int> &ans){
    if (root==NULL || root->left==NULL && root->right==NULL){
        return ;
    }
    ans.push_back(root->data);
    if (root->left!=NULL){
        leftBoundary(root->left,ans);
    }
    else{
        leftBoundary(root->right,ans);
    }
}
void leafNodes(BinaryTreeNode * root, vector<int>& ans){
    if(root == NULL){
        return;
    }
    leafNodes(root -> left, ans);
    leafNodes(root -> right, ans);
    if(root -> left == NULL && root -> right == NULL){
        ans.push_back(root -> data);
    }
}
void rightBoundary(BinaryTreeNode * root, vector<int>& ans){
    if(root == NULL || (root -> left == NULL && root -> right == NULL)){
        return;
    }
    
    if(root -> right != NULL){
        rightBoundary(root -> right, ans);
    }

    else{
        rightBoundary(root -> left, ans);
    }
    
    ans.push_back(root -> data);
}

vector <int> boundaryTraversal(BinaryTreeNode *root){
    vector <int> ans;
    if (root==NULL){
        return ans;
    }
    ans.push_back(root->data);
    leftBoundary(root->left,ans);
    leafNodes(root,ans);
    rightBoundary(root->right,ans);
    return ans;
}

int main()
{
    BinaryTreeNode *root = takeInput();
    vector <int> ans=boundaryTraversal(root);
    for (auto u:ans){
        cout << u << " ";
    }
    return 0;
}