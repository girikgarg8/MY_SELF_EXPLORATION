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
TreeNode *insert(TreeNode *root,int val,TreeNode * & successor){
    if (root==NULL){
        root=new TreeNode(val);
        return root;
    }
    if (val<root->data){
        successor->data=root->data;
        root->left=insert(root->left,val,successor);
    }
    else{
        root->right=insert(root->right,val,successor);
    }
    return root;
}
vector <int> leastGreatestElement(vector <int> & arr){
    TreeNode *root=NULL;
    int n=arr.size();
    for (int i=n-1;i>=0;i--){
        TreeNode *successor= new TreeNode(-1); //intialised successor with the value -1
        root=insert(root,arr[i],successor);
        arr[i]=successor->data;
    }
    for (int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return arr;
}
int main(){
    vector <int> v={8,58,71,18,31,32,63,92,43,3,91,93,25,80,28};
    leastGreatestElement(v);
    return 0;
}