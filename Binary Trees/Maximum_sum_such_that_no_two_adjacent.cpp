#include <iostream>
#include <queue>
#include <unordered_map>
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
int maximumSum(BinaryTreeNode *root,unordered_map <BinaryTreeNode *,int> &mp){
    if (root==NULL){ //if tree is empty
        return 0;
    }
    if (root->left==NULL && root->right==NULL){
        //if root does not have left and right child nodes i.e. leaf node
        return root->data;
    }
    if (mp[root]!=0){
        return mp[root]; //return sum stored
    }
    int left_side=0;
    int right_side=0;
    if (root->left!=NULL){
        //calculate the left subtree sum
        left_side=maximumSum(root->left->left,mp)+maximumSum(root->left->right,mp);
    }
    if (root->right!=NULL){
        right_side=maximumSum(root->right->left,mp)+maximumSum(root->right->right,mp);
    }
    int x=left_side+right_side+root->data;
    int y=maximumSum(root->left,mp)+maximumSum(root->right,mp);
    return mp[root]=max(x,y);
}
int maximumSumOfNodes(BinaryTreeNode *root){
    unordered_map <BinaryTreeNode *,int> mp;
    int res=maximumSum(root,mp);
    return res;
}
int main(){
    BinaryTreeNode *root=takeInput();
    cout << maximumSumOfNodes(root);
    return 0;
}
/*
Pair approach
pair <int,int> maximumSum(BinaryTreeNode *root){
    pair <int,int> max_sum;
    if (root==NULL){
        max_sum.first=0;
        max_sum.second=0;
        return max_sum;
    }
    //Initialise pair to calculate the sum from left and right subtree
    pair <int,int> left_sum=maximumSum(root->left);
    pair <int,int> right_sum=maximumSum(root->right);

    //If current node is included, meaning that left and right children are not included
    max_sum.first=left_sum.second+right_sum.second+root->data;

    //The current node is not included meaning that either left or right children is included
    max_sum.second=max(left_sum.first,left_sum.second)+max(right_sum.first,right_sum.second);
    
}
int maximumSumOfNodes(BinaryTreeNode *root){
    pair<int,int> res=maximumSum(root); //initialise a pair to store sum of nodes that calls the function
    //return maximum of first and second values of pair
    return max(res.first,res.second);
}




*/