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
void inorder(BinaryTreeNode* root)
{
    if (root == NULL) {
        return ;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
BinaryTreeNode * constructBST(int pre[],int s,int e){
    if (s>e){
        return NULL;
    }
    BinaryTreeNode * node= new BinaryTreeNode(pre[s]);
    int i;
    for (i=s;i<=e;i++){
        if (pre[i]>node->data){
            break;
        }
    }
    node->left=constructBST(pre,s+1,i-1);
    node->right=constructBST(pre,i,e); //not i+1, i would also be a part of the right subtree
    return node;
}
int main(){

    int preorder[] = {15,10,8,12,20,16,25};
    int n = sizeof(preorder)/sizeof(preorder[0]);
    BinaryTreeNode* root = constructBST(preorder, 0, n - 1);
    cout << "Inorder traversal of BST is "; 
    inorder(root);
    return 0;
}