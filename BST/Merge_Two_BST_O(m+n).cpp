#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
    ~TreeNode(){
        delete left;
        delete right;
    }
};
TreeNode *takeInput()
{
    int rootData;
    int leftchildData;
    int rightchildData;
    cout << "Enter the root data:" << endl;
    cin >> rootData;
    TreeNode *root = new TreeNode(rootData);
    queue<TreeNode *> q1;
    q1.push(root);
    while (!q1.empty())
    {
        TreeNode *leftChild;
        TreeNode *rightChild;
        TreeNode *a = q1.front();
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
            leftChild = new TreeNode(leftchildData);
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
            rightChild = new TreeNode(rightchildData);
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
void storeInOrder(TreeNode *root,int temp[],int &index){
    if (root==NULL){
        return ;
    }
    storeInOrder(root->left,temp,index);
    temp[index++]=root->data;
    storeInOrder(root->right,temp,index);
}
int *merge(int temp1[],int n,int temp2[],int m){
    int *mergedArray=new int [n+m];
    int i=0,j=0,k=0;
    while (i<n && j<m){
        if (temp1[i]<=temp2[j]){
            mergedArray[k]=temp1[i];
            i++;
            k++;
        }
        else if (temp1[i]>temp2[j]){
            mergedArray[k]=temp2[j];
            j++;
            k++;
    }
    }
    while (i < n)
    {
        mergedArray[k] = temp1[i];
        i++; k++;
    }

    while (j < m)
    {
        mergedArray[k] = temp2[j];
        j++; k++;
    }
 
    return mergedArray;
}
TreeNode * sortedArrayToBST(int arr[],int s,int e){
    if (s>e){
        return NULL;
    }
    int mid=s+(e-s)/2;
    TreeNode *root=new TreeNode(arr[mid]);
    root->left=sortedArrayToBST(arr,s,mid-1);
    root->right=sortedArrayToBST(arr,mid+1,e);
    return root;
}
TreeNode * mergeBST(TreeNode *root1,TreeNode *root2,int n,int m){
    int *temp1=new int [n];
    int i=0;
    storeInOrder(root1,temp1,i);
    int *temp2=new int[m];
    int j=0;
    storeInOrder(root2,temp2,j);
    int *mergedArray=merge(temp1,n,temp2,m);
    return sortedArrayToBST(mergedArray,0,m+n-1);
}
void printLevelWise(TreeNode *root)
{
    queue<TreeNode *> q1;
    q1.push(root);
    while (!q1.empty())
    {
        TreeNode *a = q1.front();
        q1.pop();
        cout << endl;
        cout << a->data << ":";
        if (a->left != NULL)
        {
            cout << " L" << a->left->data;
            q1.push(a->left);
        }
        if (a->right != NULL)
        {
            cout << " R" << a->right->data;
            q1.push(a->right);
        }
    }
}
int main(){
    TreeNode *root1=takeInput();
    cout << "Inputting second BST" <<endl;
    TreeNode *root2=takeInput();
    TreeNode *merge=mergeBST(root1,root2,5,3);
    printLevelWise(merge);
    return 0;
}