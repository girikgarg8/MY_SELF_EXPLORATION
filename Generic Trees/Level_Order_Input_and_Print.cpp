#include <iostream>
#include <vector>
#include <queue>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode *> childArray;
    TreeNode(T data)
    {
        this->data = data;
    }
};
TreeNode<int> *LevelOrderInput()
{
    //I will ask the user for data and number of children, data only will not suffice
    int rootData;
    int childData;
    int num;
    queue<TreeNode<int> *> q1;
    cout << "Enter root data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    q1.push(root);
    while (!q1.empty())
    {
        TreeNode<int> *node = q1.front();
        q1.pop();
        cout << "Enter the number of children"
             << " of" << node->data << endl;
        cin >> num;
        for (int i = 0; i < num; i++)
        {
            cout << "Enter the data"
                 << "of" << i << "th child of " << node->data << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            q1.push(child);
            node->childArray.push_back(child);
        }
    }
    return root;
}
void LevelOrderPrint(TreeNode<int> *root)
{
    cout << root->data << endl;
    queue<TreeNode<int> *> q1;
    q1.push(root);
    while (!q1.empty())
    {
        TreeNode<int> *a = q1.front();
        q1.pop();
        int s = a->childArray.size();
        cout << a->data << " :";
        for (int i = 0; i < s; i++)
        {
            q1.push(a->childArray[i]);
            cout << (a->childArray[i])->data << ",";
        }
        cout << endl;
    }
}
int main()
{
    TreeNode<int> *root = LevelOrderInput();
    LevelOrderPrint(root);
    return 0;
}
