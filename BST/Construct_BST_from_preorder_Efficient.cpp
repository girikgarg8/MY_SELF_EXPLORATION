#include <iostream>
#include <vector>
#include <climits>
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
void inorder(BinaryTreeNode* root)
{
    if (root == NULL) {
        return ;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
BinaryTreeNode * constructBST(vector <int> const &pre,int &index,int min,int max){

//Base Case
if (index>=pre.size()){
    return NULL;
}
int val=pre[index];
//Return if the next element of preorder traversal is not in the valid range
if (val < min || val>max){
    return NULL;
}
BinaryTreeNode *root=new BinaryTreeNode(val);
index++;
root->left=constructBST(pre,index,min,val-1);
root->right=constructBST(pre,index,val+1,max);
return root;
}
BinaryTreeNode* buildTree(vector<int> const &preorder)
{
    // start from the root node (the first element in a preorder sequence)
    int pIndex = 0;
 
    // set the root node's range as [-INFINITY, INFINITY] and recur
    return constructBST(preorder,pIndex, INT_MIN, INT_MAX);
}
int main()
{
    /* Construct the following BST
              15
            /    \
           /      \
          10       20
         /  \     /  \
        /    \   /    \
       8     12 16    25
    */
 
    // preorder traversal of BST
    vector<int> preorder = { 15, 10, 8, 12, 20, 16, 25 };
 
    // construct the BST
    BinaryTreeNode* root = buildTree(preorder);
 
    // print the BST
    cout << "Inorder traversal of BST is ";
 
    // inorder on the BST always returns a sorted sequence
    inorder(root);
 
    return 0;
}




