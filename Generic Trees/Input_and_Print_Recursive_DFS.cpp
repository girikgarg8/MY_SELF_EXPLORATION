#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<int> *> childArray;
    TreeNode(T data)
    {
        this->data = data;
    }
};
void print(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ":";
    for (int i = 0; i < root->childArray.size(); i++)
    {
        cout << (root->childArray[i])->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->childArray.size(); i++)
    {
        print(root->childArray[i]);
    }
}
TreeNode<int> *takeInput()
{
    int rootData;
    int n;
    cout << "Enter the data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    cout << "Enter the number of children" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *childnode = takeInput();
        root->childArray.push_back(childnode);
    }
    return root;
}
int main()
{                                      //Take input and print are not class functions
    TreeNode<int> *root = takeInput(); //User also needs to have the root with himself
    print(root);
    return 0;
}
