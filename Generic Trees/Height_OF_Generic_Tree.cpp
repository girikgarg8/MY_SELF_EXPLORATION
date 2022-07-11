#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <climits>
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
int HeightOfTree(TreeNode<int> *root)
{
    map<TreeNode<int> *, int> height;
    height[root] = 0;
    int s = root->childArray.size();
    for (int i = 0; i < s; i++)
    {
        height[root->childArray[i]] = HeightOfTree(root->childArray[i]);
    }
    int maximum = height[root];
    int x = root->childArray.size();
    for (int i = 0; i < x; i++)
    {
        if (height[root->childArray[i]] > maximum)
        {
            maximum = (height[root->childArray[i]]);
        }
    }
    return maximum + 1;
}
int main()
{
    TreeNode<int> *root = LevelOrderInput();
    cout << "Height of the tree is " << HeightOfTree(root) << endl;
    return 0;
}
