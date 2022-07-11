#include <iostream>
#include <map>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 
// Recursive function to perform preorder traversal on the tree and fill the map.
// Here, the node has `dist` horizontal distance from the tree's root
void printVertical(Node* node, int dist, auto &map)
{
    // base case: empty tree
    if (node == nullptr) {
        return;
    }
 
    // insert nodes present at a current horizontal distance into the map
    map.insert(make_pair(dist, node->data));
 
    // recur for the left subtree by decreasing horizontal distance by 1
    printVertical(node->left, dist - 1, map);
 
    // recur for the right subtree by increasing horizontal distance by 1
    printVertical(node->right, dist + 1, map);
}
 
// Function to perform vertical traversal on a given binary tree
void printVertical(Node* root)
{
    // create an empty map where
    // `key` —> relative horizontal distance of the node from the root node, and
    // `value` —> nodes present at the same horizontal distance
    multimap<int, int> map;
 
    /* We can also use `map<int, vector<int>>` instead of `multimap<int, int>` */
 
    // perform preorder traversal on the tree and fill the map
    printVertical(root, 0, map);
 
    // traverse the map and print the vertical nodes
    int temp = 0;
    for (auto it = map.begin(); it != map.end(); it++)
    {
        if (temp != it->first)
        {
            cout << endl;
            temp = it->first;
        }
        cout << it->second << " ";
    }
}
 
int main()
{
    /* Construct the following tree
            1
          /   \
         /     \
        2       3
              /   \
             /     \
            5       6
          /   \
         /     \
        7       8
              /   \
             /     \
            9      10
    */
 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
    root->right->left->right->left = new Node(9);
    root->right->left->right->right = new Node(10);
 
    printVertical(root);
 
    return 0;
}

/*
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 
// Function to perform vertical traversal on a given binary tree
void printVertical(Node* root)
{
    // base case
    if (root == nullptr) {
        return;
    }
 
    // create a multimap to store the vertical order of binary tree nodes
    // map<int, vector<int>> can also be used replacing `multimap<int, int>`
    multimap<int, int> map;
 
    // create an empty queue for level order traversal.
    // `It` stores binary tree nodes and their horizontal distance from the root.
    queue<pair<Node*, int>> q;
 
    // enqueue root node with horizontal distance as 0
    q.push(make_pair(root, 0));
 
    // loop till queue is empty
    while (!q.empty())
    {
        // dequeue front node
        Node* node = q.front().first;
        int dist = q.front().second;
        q.pop();
 
        // insert front node value into the map using its horizontal distance
        // as the key
        map.insert(make_pair(dist, node->data));
 
        // enqueue non-empty left and right child of the front node
        // with their corresponding horizontal distance
        if (node->left) {
            q.push(make_pair(node->left, dist - 1));
        }
        if (node->right) {
            q.push(make_pair(node->right, dist + 1));
        }
    }
 
    // print the multimap
    int val = 0;
    for (auto it = map.begin(); it != map.end(); it++)
    {
        if (val != it->first)
        {
            cout << endl;
            val = it->first;
        }
        cout << it->second << " ";
    }
}
 
int main()
{
    /* Construct the following tree
            1
          /   \
         /     \
        2       3
              /   \
             /     \
            5       6
          /   \
         /     \
        7       8
              /   \
             /     \
            9      10
    */
 
 /*
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
    root->right->left->right->left = new Node(9);
    root->right->left->right->right = new Node(10);
 
    printVertical(root);
 
    return 0;
}

*/
/* This code can also be used to print the vertical traversal

    int val = 0; //start printing from horizontal level of root
    for (auto it:map)
    {
        if (val!=it.first){
            cout <<endl;
            val=it.first;
        }
        int x=it.second;
        cout << x << " ";
    }
}
 
 */

