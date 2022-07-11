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
vector <int> getInorder(BinaryTreeNode *root){
    vector <int> inorder;
    BinaryTreeNode *cur=root;
    while (cur!=NULL){ //this used to be the base case of my inorder traversal
    if (cur->left==NULL){
        inorder.push_back(cur->data);
        cur=cur->right;
    }
    else{
        BinaryTreeNode *prev=cur->left;
        while (prev->right!=NULL && prev->right!=cur){
            prev=prev->right;
        }
             //prev->right!=cur is needed for the case when there sis already an existing thread
            if (prev->right==NULL){
                prev->right=cur; //creating the thread
                cur=cur->left;
            }
            else{
                prev->right=NULL;
                inorder.push_back(cur->data); //this line is needed because upper left condition of curr->left will not get executed here, henece I need to push the current element to the vector
                cur=cur->right;
            }
        }
    }
    return inorder;
}
int main(){
    BinaryTreeNode *root=takeInput();
    vector <int> inorder=getInorder(root);
    for (auto u:inorder){
        cout << u << " ";
    }
    return 0;
}
