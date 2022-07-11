#include <iostream>
#include <queue>
#include <map>
#include <string>
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
string serialize(BinaryTreeNode *root){
    //Recursive function
    //Base Case
    if (root==NULL){
        return ""; //return empty string
    }
    string s="";
    s+=to_string(root->data);
    s+=serialize(root->left);
    s+=serialize(root->right);
    return s;
}
bool hasDuplicateSubTrees(BinaryTreeNode *root){
    map<string,int> mp;
    queue <BinaryTreeNode *> q;
    q.push(root);
    while (!q.empty()){
        BinaryTreeNode *node=q.front();
        q.pop();
        if (node->left==NULL && node->right==NULL){ //means it is a leaf node, as asked in the question, in case of leaf node,I don't have to do serialization

        }
        else{
            string str=serialize(node);
            mp[str]++;
        }
        if (node->left!=NULL){
            q.push(node->left);
        }
        if (node->right!=NULL){
            q.push(node->right);
        }
    }
    for (auto x:mp)
    {
        if (x.second>=2){
            return true;
        }
    }
    return false;
}
int main(){
    BinaryTreeNode *root = takeInput();
    hasDuplicateSubTrees(root); //1 2 3 4 5 -1 2 -1 -1 4 5 -1 -1 -1 -1
}