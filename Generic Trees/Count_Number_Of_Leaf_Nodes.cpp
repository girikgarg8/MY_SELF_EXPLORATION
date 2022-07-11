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
int CountNumberOfLeafNodes(TreeNode *root)
{
    int count = 0;
    queue<TreeNode *> q1;
    q1.push(root);
    while (!q1.empty())
    {
        TreeNode *a = q1.front();
        q1.pop();
        if (a->childArray.size() == 0)
        {
            count++;
        }
        else
        {
            for (int i = 0; i < (a->childArray.size()); i++)
            {
                q1.push(a->childArray[i]);
            }
        }
    }
    return count;
}
int main()
{
    TreeNode *root = TakeInputLevelWise();
    cout << "Number of leaf nodes are " << CountNumberOfLeafNodes(root) << endl;
    return 0;
}