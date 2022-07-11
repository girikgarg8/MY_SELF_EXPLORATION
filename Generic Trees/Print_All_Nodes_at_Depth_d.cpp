#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class TreeNode
{
public:
    int data;
    vector<TreeNode *> childArray;
    TreeNode(int data)
    {
        this->data = data;
    }
};
TreeNode *TakeInputLevelWise()
{
    queue<TreeNode *> q1;
    int rootData;
    int childData;
    int num;
    cout << "Enter the root data " << endl;
    cin >> rootData;
    TreeNode *root = new TreeNode(rootData);
    q1.push(root);
    while (!q1.empty())
    {
        TreeNode *a = q1.front();
        q1.pop();
        cout << "Enter the number of children of " << a->data << endl;
        cin >> num;
        for (int i = 0; i < num; i++)
        {
            cout << "Enter the " << i << " th child of " << a->data << endl;
            cin >> childData;
            TreeNode *node = new TreeNode(childData);
            a->childArray.push_back(node);
            q1.push(node);
        }
    }
    return root;
}
void printNodesAtDepth(TreeNode *root, int d)
{   
    //Edge case
    if (root==NULL){
        return ;
    }
    if (d == 0)
    {
        cout << root->data << ",";
        return;
    }
    for (int i = 0; i < root->childArray.size(); i++)
    {
        printNodesAtDepth(root->childArray[i], d - 1);
    }
}
int main()
{
    TreeNode *root = TakeInputLevelWise();
    printNodesAtDepth(root, 1);
    return 0;
}




