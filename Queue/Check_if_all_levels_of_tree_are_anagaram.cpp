#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
TreeNode *takeInputLevelWise()
{
    int rootData;
    TreeNode *root;
    queue<TreeNode *> q1;
    cout << "Enter the root data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL; //because in this case NULL would be the root of the tree
    }
    else
    {
        root = new TreeNode(rootData);
    }
    q1.push(root);
    while (!q1.empty())
    {
        TreeNode *a = q1.front();
        q1.pop();
        TreeNode *leftChild;
        TreeNode *rightChild;
        int leftData, rightData;
        cout << "Enter the left child of " << a->data << endl;
        cin >> leftData;
        if (leftData == -1)
        {
            leftChild = NULL;
        }
        else
        {
            leftChild = new TreeNode(leftData);
            q1.push(leftChild);
        }
        cout << "Enter the right child of " << a->data << endl;
        cin >> rightData;
        if (rightData == -1)
        {
            rightChild = NULL;
        }
        else
        {
            rightChild = new TreeNode(rightData);
            q1.push(rightChild);
        }
        a->left = leftChild;
        a->right = rightChild;
    }
    return root;
}
void printLevelWise(TreeNode *root)
{
    queue<TreeNode *> q1;
    if (root == NULL)
    {
        return;
    }
    q1.push(root);
    while (!q1.empty())
    {
        TreeNode *a = q1.front();
        q1.pop();
        cout << a->data << "->";
        if (a->left != NULL)
        {
            q1.push(a->left);
            cout << "L" << a->left->data << ",";
        }
        if (a->right != NULL)
        {
            q1.push(a->right);
            cout << "R" << a->right->data;
        }
        cout << endl;
    }
}
bool checkIsAnagram(TreeNode *root1, TreeNode *root2, int n, int m)
{
    if (n != m)
    {
        return false;
    }
    queue<TreeNode *> q1;
    queue<TreeNode *> q2;
    vector<int> tree1data;
    vector<int> tree2data;
    q1.push(root1);
    q2.push(root2);
    while (true)
    {
        if (q1.size() != q2.size())
        { //Unequal number of elements at a current level
            return false;
        }
        if (q1.size() == 0)
        {
            return true; //means that we have covered all the levels of the trees
        }
        int q1Size = q1.size();
        int q2Size = q2.size();
        while (q1Size != 0)
        {
            TreeNode *a = q1.front();
            tree1data.push_back(a->data);
            if (a->left != NULL)
            {
                q1.push(a->left);
            }
            if (a->right != NULL)
            {
                q1.push(a->right);
            }
            q1.pop();
            q1Size--;
        }
        while (q2Size != 0)
        {
            TreeNode *b = q2.front();
            tree2data.push_back(b->data);
            if (b->left != NULL)
            {
                q2.push(b->left);
            }
            if (b->right != NULL)
            {
                q2.push(b->right);
            }
            q2.pop();
            q2Size--;
        }
        sort(tree1data.begin(), tree1data.end());
        sort(tree2data.begin(), tree2data.end());
        if (tree1data != tree2data)
        { //vector comparison by operator overloading
            return false;
        }
    }
    return true;
}
int main()
{
    TreeNode *root1 = takeInputLevelWise();
    TreeNode *root2 = takeInputLevelWise();
    int n = 3, m = 3;
    cout << checkIsAnagram(root1, root2, n, m) << endl;
    return 0;
}
/*Another recursive approach
void anagramHelper(TreeNode *root, int level, vector <int> & v){
    if (root==NULL){
        return ;
    }
    v[level].push_back(root->val);
    anagramHelper(root->left,level+1,v);
    anagramHelper(root->right,level+1,v);
    return ;
}
bool checkIsAnagram(TreeNode *root1,TreeNode *root2,int n,int m){
    if (n!=m){
        return false;
    }
    vector <int> TreeOne(n);
    vector <int> TreeTwo(m);
    anagramHelper(root1,0,TreeOne);
    anagramHelper(root2,0,TreeTwo);
    for (int i=0;i<n;i++){
        if (TreeOne[i]!=TreeTwo[i]){
            return false;
        }
        if (treeOne[i].size()==0 && treeTwo.size()==0){
            break;
        }
    }
    return true;
}
*/
