#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
    ~TreeNode(){
        delete left;
        delete right;
    }
};
void solve(TreeNode *root,TreeNode *&prev){
    if (root==NULL){
        return ;
    }
    if (prev!=NULL){
        prev->next=root;
    }
    prev=root;
    solve(root->right,prev);
}
void populateNext(TreeNode *root){
    TreeNode *prev=NULL;
    solve(root,prev);
}