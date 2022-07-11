//Thsi code is actually faulty because if I say V=5, I can have the elements as 10 20 30 40 50, now in my code I am trying to access arr[10] which is actually wrong
#include <iostream>
using namespace std;
class LLNode
{
public:
    int data;
    LLNode *next;
    LLNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    void insertatEnd(LLNode *head, int data)
    {
        LLNode *newNode = new LLNode(data);
        LLNode *temp = head;
        while ((temp->next) != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void print(LLNode *temp)
    {
        while (temp != NULL)
        {
            cout << temp->data << " , ";
            temp = temp->next;
        }
    }
};
class Graph
{
public:
    int v; //Number of vertices in the graph
    LLNode **arr;
    Graph(int v)
    {
        this->v = v;
        arr = new LLNode *[v];
        for (int i = 0; i < v; i++)
        {
            arr[i] = NULL;
        }
    }
    void addEdge(int x, int y, bool isBiDirectionalEdge = true)
    {
        if (isBiDirectionalEdge == true)
        {
            if (arr[x] == NULL && arr[y] == NULL)
            {
                arr[x] = new LLNode(y);
                arr[y] = new LLNode(x);
            }
            else if (arr[x] != NULL && arr[y] != NULL)
            {
                LLNode *head1 = arr[x];
                LLNode *head2 = arr[y];
                head1->insertatEnd(head1, y);
                head2->insertatEnd(head2, x);
            }
            else if (arr[x] == NULL && arr[y] != NULL)
            {
                arr[x] = new LLNode(y);
                LLNode *head2 = arr[y];
                head2->insertatEnd(head2, x);
            }
            else if (arr[x] != NULL && arr[y] == NULL)
            {
                arr[y] = new LLNode(x);
                LLNode *head1 = arr[x];
                head1->insertatEnd(head1, y);
            }
        }
        if (isBiDirectionalEdge == false)
        {
            if (arr[x] == NULL)
            {
                arr[x] = new LLNode(y);
            }
            else if (arr[x] != NULL)
            {
                LLNode *head1 = arr[x];
                head1->insertatEnd(head1, y);
            }
        }
    }
    void printNeighbours(int x)
    {
        LLNode *t = arr[x];
        t->print(t);
    }
};
int main()
{
    Graph g1(5);
    g1.addEdge(1, 3);
    g1.addEdge(3, 4);
    g1.addEdge(4, 2);
    g1.addEdge(2, 1);
    g1.printNeighbours(2);
    return 0;
}