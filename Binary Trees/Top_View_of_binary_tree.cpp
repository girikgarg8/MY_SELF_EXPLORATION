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
void printVertical(Node *root)
{
    // base case
    if (root == nullptr)
    {
        return;
    }

    // create a multimap to store the vertical order of binary tree nodes
    // map<int, vector<int>> can also be used replacing `multimap<int, int>`
    multimap<int, int> map;

    // create an empty queue for level order traversal.
    // `It` stores binary tree nodes and their horizontal distance from the root.
    queue<pair<Node *, int>> q;

    // enqueue root node with horizontal distance as 0
    q.push(make_pair(root, 0));

    // loop till queue is empty
    while (!q.empty())
    {
        // dequeue front node
        Node *node = q.front().first;
        int dist = q.front().second;
        q.pop();

        // insert front node value into the map using its horizontal distance
        // as the key
        if (map.find(dist) == map.end())
        { //inserting only the first encountered element into the map
            map.insert(make_pair(dist, node->data));
        }

        // enqueue non-empty left and right child of the front node
        // with their corresponding horizontal distance
        if (node->left)
        {
            q.push(make_pair(node->left, dist - 1));
        }

        if (node->right)
        {
            q.push(make_pair(node->right, dist + 1));
        }
    }

    // print the multimap
    int val = 0;
    for (auto it : map)
    {
        int num = 0;
        if (val != it.first)
        {
            cout << endl;
            val = it.first;
        }
        cout << it.second << " ";
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

    Node *root = new Node(1);
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