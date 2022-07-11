#include <iostream>
#include <queue>
#include <vector>
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
vector<int> zigZagTraversal(BinaryTreeNode *root) {
    vector <int> answer;
    if (root==NULL){
        return answer;
    }
    queue<BinaryTreeNode *> q1;
    q1.push(root);
    bool reverseOrder=false;
    while (!q1.empty()){
        int n=q1.size();
        vector <int> currentLevelNodes;
        for (int i=0;i<n;i++){
            BinaryTreeNode * current=q1.front();
            q1.pop();
            currentLevelNodes.push_back(current->data);
            if (current->left){
                q1.push(root->left);
            }
            if (current->right){
                q1.push(root->right);
            }
        }
        for (int i=0;i<n;i++){
            if (reverseOrder==false)
            answer.push_back(currentLevelNodes[i]);
            else if (reverseOrder==true){
                answer.push_back(currentLevelNodes[n-i-1]);
            }
        }
        reverseOrder=!reverseOrder;
    }
    return answer;
}
int main(){
    BinaryTreeNode *root = takeInput();
    vector <int> ans=zigZagTraversal(root);
    for (auto u:ans){
        cout << u << " ";
    }
    return 0;
}

/*
Deque based approach
#include <deque>

vector<int> zigZagTraversal(BinaryTreeNode<int> *root) {
    // Declare an empty array answer to store zigzag traversal
    vector<int> answer;

    // Base case
    if (root == NULL) {
        return answer;
    }

    // Declare an empty deque and push back root to it
    deque<BinaryTreeNode<int>*> d;
    d.push_back(root);

    // Declare a variable level to get current level and initialize it to 1
    int level = 1;

    // Run a loop until deque is not empty
    while (!d.empty())
    {
        // Size of deque i.e. denotes no. of nodes in current level
        int n = d.size();

        // Run a loop until nodes in the current level are greater than zero
        while (n--)
        {
            // In current level is odd
            if (level % 2 == 1)
            {

                // pop the front node from deque and add its data to answer
                BinaryTreeNode<int>* backNode = d.front();
                d.pop_front();
                answer.push_back(backNode->data);

                // Push back left and right child of popped node to deque
                if (backNode->left != NULL)
                {
                    d.push_back(backNode->left);
                }
                if (backNode->right != NULL)
                {
                    d.push_back(backNode->right);
                }

            }
            // If current level is even
            else
            {
                // Pop back node from deque and add its data to answer
                BinaryTreeNode<int>* backNode = d.back();
                d.pop_back();
                answer.push_back(backNode->data);

                // Push right and left child of popped node to front of deque
                if (backNode->right != NULL)
                {
                    d.push_front(backNode->right);
                }
                if (backNode->left != NULL)
                {
                    d.push_front(backNode->left);
                }
            }
        }

        // Increment level by 1
        level++;
    }
    return answer;
}
*/