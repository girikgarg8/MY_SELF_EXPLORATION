// C++ program to check if all leaf nodes are at
// same level of binary tree
#include <bits/stdc++.h>
using namespace std;

// tree node
struct Node {
	int data;
	Node *left, *right;
};

// returns a new tree Node
Node* newNode(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// return true if all leaf nodes are
// at same level, else false
int checkLevelLeafNode(Node* root)
{
	if (root==NULL)
		return 1;

	// create a queue for level order traversal
	queue<Node*> q;
	q.push(root);
	int result=INT_MAX; //this variable will hold the levl of first level node, initially inifinity but will we updated when first leaf node is found
    int level=0; //this variable will keep track of levels of all nodes.... it will go on increasing with different levels

	// traverse until the queue is empty
	while (!q.empty()) {
		int n = q.size();
        level+=1;
		// traverse for complete level
		for (int i=0;i<n;i++){
			Node* temp = q.front();
			q.pop();
		if (temp->left!=NULL){
            q.push(temp->left);
            if (temp->left->left==NULL && temp->left->right==NULL){
                if (result==INT_MAX){
                    result=level;
                }
                else if (result!=level){
                    return false;
                }
            }
        }
        if (temp->right!=NULL){
            q.push(temp->right);
             if (temp->right->left==NULL && temp->right->right==NULL){
                if (result==INT_MAX){
                    result=level;
                }
                else if (result!=level){
                    return false;
                }
            }
        }
	}
    }
	return true;
}

// driver program
int main()
{
	// construct a tree
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->right = newNode(4);
	root->right->left = newNode(5);
	root->right->right = newNode(6);

	int result = checkLevelLeafNode(root);
	if (result)
		cout << "All leaf nodes are at same level\n";
	else
		cout << "Leaf nodes not at same level\n";
	return 0;
}
