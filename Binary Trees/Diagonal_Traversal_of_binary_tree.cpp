#include <iostream>
#include <queue>
#include <vector>
#include <map>
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
void solve(BinaryTreeNode *root,int level,map<int,vector<int>> &levelMap){
    if (root==NULL){
        return ;
    }
    solve (root->left,level+1,levelMap);
    solve (root->right,level,levelMap);

}
vector <int> diagonalPath( BinaryTreeNode * root){
    map <int,vector<int> > levelMap;
    solve(root,0,levelMap);
    vector <int> answer;
     for (auto it: levelMap) {
        vector < int > v = it.second;
        for (auto it: v) {
            answer.push_back(it);
        }
    }
    return answer;
}
int main(){
    BinaryTreeNode *root = takeInput();
    vector <int> ans=diagonalPath(root);
    for (auto u:ans){
        cout << u << " ";
    }
    return 0;
}