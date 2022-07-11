#include <iostream>
#include <map>
using namespace std;
class Node
{
public:
    Node *left;
    Node *right;
    int key, val;
    Node(int key, int val)
    {
        this->key = key;
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
class LRUCache
{
    map<int, Node *> nodemap;
    Node *head;
    Node *tail;
    int capacity, size;

public:
    LRUCache(int capacity)
    {
        head = tail = NULL;
        this->capacity = capacity;
        this->size = 0;
    }
    void deleteNode(Node *nd)
    {
        if (nd->left != NULL)
        {
            nd->left->right = nd->right;
        }
        else
        {
            head = nd->right;
        }
        if (nd->right != NULL)
        {
            nd->right->left = nd->left;
        }
        else
        {
            tail = nd->left;
        }
        nd->left = nd->right = NULL;
    }
    void addToRear(Node *nod)
    {
        if (head == NULL)
        {
            head = tail = nod;
            return;
        }
        return;
    }
    int get(int key)
    {
        if (nodemap.find(key) == nodemap.end())
        {
            return -1;
        }
        deleteNode(nodemap[key]);
        addToRear(nodemap[key]);
        return nodemap[key]->val;
    }
    void put(int key, int value)
    {
        if (nodemap.find(key) != nodemap.end())
        {
            nodemap[key]->val = value;
            deleteNode(nodemap[key]);
            addToRear(nodemap[key]);
        }
        else
        {
            Node *nod = new Node(key, value);
            nodemap[key] = nod;
            if (capacity == size)
            {
                nodemap.erase(head->key);
                deleteNode(head);
                addToRear(nod);
            }
            else
            {
                addToRear(nod);
                size++;
            }
        }
    }
};
int main(){
    int capacity,q;
    cin>>capacity>>q;
    LRUCache l(capacity);
    for (int i=0;i<q;i++){
        int a,b,c;
        cin>>a;
        if (a==1){
            cin>>b>>c;
            l.put(b,c);
        }
        if (a==0){
            cin>>b;
            cout << l.get(b) <<endl;
        }
    }
    return 0;
}