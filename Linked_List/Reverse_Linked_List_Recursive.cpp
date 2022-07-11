#include <bits/stdc++.h>
using namespace std;
class LLNode{
    public:
    int data;
    LLNode *next;
    public:
    LLNode (int value){
        data=value;
        next=NULL;
    }
};
class LinkedList{
    LLNode *head;
    LLNode *tail;
    public:
    LinkedList(){
        head=NULL;
        tail=NULL;
    }
    void push_back(int value){
        LLNode *node=new LLNode(value);
        if (head==NULL){
            head=node;
            tail=node;
        }
        else{
            tail->next=node;
            tail=tail->next;
        }
    }
    void print(LLNode *head){
        if (head==NULL){
            cout << "NULL";
            return ;
        }
        if (head->next==NULL){
            cout << head->data;
            return ;
        }
        cout << head->data << " ";
        print(head->next);
    }
    void printForUser(){
        print(head);
    }
    void reverse(LLNode *head,LLNode *prev,LLNode *nxt){
        if (nxt==NULL){
            this->head=head;
            return ;
        }
        LLNode *node=head;
        LLNode *node1=nxt;
        LLNode *node2=node1->next;
        node1->next=node;
        node->next=prev;
        reverse(node1,node,node2);
    }
    void reverseForUser(){
        if (head==NULL){
            return ;
        }
        if (head->next==NULL){
            return ;
        }
        reverse(head,NULL,head->next);
    }
};
int main(){
    LinkedList l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    l1.printForUser();
    l1.reverseForUser();
    cout <<endl;
    l1.printForUser();
    LinkedList l2;
    cout <<endl;
    l2.printForUser();
    l2.reverseForUser();
    cout <<endl;
    l2.printForUser();
    LinkedList l3;
    l3.push_back(10);
    cout <<endl;
    l3.printForUser();
    l3.reverseForUser();
    cout <<endl;
    l3.printForUser();
    LinkedList l4;
    l4.push_back(10);
    l4.push_back(20);
    cout <<endl;
    l4.printForUser();
    l4.reverseForUser();
    cout <<endl;
    l4.printForUser();
    return 0;
}
//Another simple recursive approach could be as follows
/*Node* reverse(Node* node)
    {
        if (node == NULL)
            return NULL;
        if (node->next == NULL) {
            head = node;
            return node;
        }
        Node* node1 = reverse(node->next);
        node1->next = node;
        node->next = NULL;
        return node;
    }
    */