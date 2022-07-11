#include <iostream>
#include <vector>
#include <stack>
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
void PreOrderTraversal(TreeNode *root)
{
    cout << root->data;
    queue<TreeNode *> q1;
    q1.push(root);
    while (!q1.empty())
    {
        TreeNode *a = q1.front();
        q1.pop();
        int s = a->childArray.size();
        for (int i = 0; i < s; i++)
        {
            q1.push(a->childArray[i]);
            cout << (a->childArray[i])->data << " ";
        }
    }
    cout << endl;
}
void PostOrderTraversal(TreeNode *root)
{
    int s = root->childArray.size();
    for (int i = 0; i < s; i++)
    {
        PostOrderTraversal(root->childArray[i]);
    }
    cout << root->data << " ";
}
int main()
{
    TreeNode *root = TakeInputLevelWise();
    PreOrderTraversal(root);
    PostOrderTraversal(root);
    return 0;
}