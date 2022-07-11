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
int findNumOfNodes(BinaryTreeNode *root){
    if (root==NULL){
        return 0; //the edge case, not the recursive base case
    }
    int count=0;
    BinaryTreeNode *cur=root;
    while (cur!=NULL){ //this used to be the base case of my inorder traversal
    if (cur->left==NULL){
        count++; //count node if its left is NULL
        // inorder.push_back(cur->data);
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
                // inorder.push_back(cur->data); //this line is needed because upper left condition of curr->left will not get executed here, henece I need to push the current element to the vector
                count++;
                cur=cur->right;
            }
        }
    }
    return count;
}
int findMedian(BinaryTreeNode *root){
    if (root==NULL){ //edge case
        return 0;
    }
    int count=findNumOfNodes(root);
    int currCount=0;
    BinaryTreeNode *cur=root;
    BinaryTreeNode * prev;
    BinaryTreeNode *pre;
    while (cur!=NULL){ 
    if (cur->left==NULL){
        currCount++;
        //The odd case
        if (count%2!=0 && currCount==(count+1)/2){
            return cur->data;
        }
        //The case when there are even number of nodes in the BST
        if (count%2==0 && currCount==(count)/2+1){
            return (pre->data+cur->data)/2;
        }
        pre=cur;
        cur=cur->right;
    }
    else{
        prev=cur->left;
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
                // inorder.push_back(cur->data); //this line is needed because upper left condition of curr->left will not get executed here, henece I need to push the current element to the vector
                pre=prev;
                currCount++;
            //The odd case
            if (count%2!=0 && currCount==(count+1)/2){
            return cur->data;
             }
            //The case when there are even number of nodes in the BST
            if (count%2==0 && currCount==(count)/2+1){
            return (pre->data+cur->data)/2;
            }
                pre=cur;
                cur=cur->right;
            }
        }
    }
    return count;
}
int main(){
    BinaryTreeNode *root=takeInput();
    cout << "Median is " <<findMedian(root);
    return 0;
}
