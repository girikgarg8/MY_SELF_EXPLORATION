#include <bits/stdc++.h>
using namespace std;
class LLNode{
    public:
    int data;
    LLNode *next;
    // LLNode(int data){
    //     this->data=data;
    //     this->next=NULL;
    // }
    LLNode(){
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
        LLNode *node;
        node=new LLNode;
        node->data=value;
        node->next=NULL;
        if (head==NULL){
            head=node;
            tail=node;
        }
        else{
            tail->next=node;
            tail=tail->next;
        }
    }
    void print(){
        LLNode *temp;
        temp=head;
        if (head==NULL){
             cout << "NULL" <<endl;
             return ;
        }
        while (temp!=NULL){
            cout << temp->data << " ";
            temp=temp->next;
        }
        cout <<endl;
    }
    void reverse(){
        LLNode *prev=head;
        if (head==NULL){
            cout << "NULL" <<endl;
            return ;
        }
        if (head->next==NULL){
            cout << head->data <<endl;
        return ;
        }
        if ((head->next->next)==NULL){
            cout << head->next->data << " " << head->data <<endl;
            return ;
        }
        LLNode *curr=head->next;
        LLNode *nxt=curr->next;
        while (curr!=NULL){
            curr->next=prev;
            prev=curr;
            curr=nxt;
            if (nxt!=NULL){
            nxt=nxt->next;
        }
        }
        head->next=NULL;
        head=prev;
        print();
    }
};
int main(){
    LinkedList l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    l1.print();
    l1.reverse();
    LinkedList l2;
    l2.print();
    l2.reverse();
    LinkedList l3;
    l3.push_back(10);
    l3.print();
    l3.reverse();
    LinkedList l4;
    l4.push_back(10);
    l4.push_back(20);
    l4.print();
    l4.reverse();
    return 0;
}