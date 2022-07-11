#include <bits/stdc++.h>
using namespace std;
class LLNode{
    public:
    int data;
    LLNode *next;
    public:
    LLNode(int data){
        this->data=data;
        next=NULL;
    }
};
class LinkedList{
    public:
    LLNode *head;
    LLNode *tail;
    public:
    LinkedList(){
        head=NULL;
        tail=NULL;
    }
    void push_back(int data){
        LLNode *node=new LLNode(data);
        if (head==NULL){
            head=node;
            tail=node;
        }
        else{
            tail->next=node;
            tail=node;
        }
    }
    //Only I need to take case of the edge like 999, 9999 etc
    void reverse(){
        LLNode *prev=NULL;
        LLNode *curr=head;
        LLNode *nxt;
        if (head==NULL){
            return ;
        }
        if (curr!=NULL){
            nxt=curr->next;
        }
        while (curr!=NULL){
            curr->next=prev;
            prev=curr;
            curr=nxt;
            if (nxt!=NULL){
            nxt=nxt->next;
            }
        }
        this->head=prev;
    }
    void insertOne(){
        reverse();
        if (head==NULL){
            cout << "Empty linked list" <<endl;
        }
        else{
        LLNode *temp=head; //this is actually pointing to the head of the reversed linked list
        head->data=head->data+1;
        while (temp!=NULL){
            if ((temp->data)==10){
                if (temp->next==NULL){
                    temp->data=0;
                     LLNode *newNode= new LLNode (1); //for cases like 999
                     temp->next=newNode;
                     temp=temp->next;
                }
                else{
                temp->data=0;
                (temp->next->data)+=1;
                temp=temp->next;
                }
            }
            else break;
        }
        reverse();
        }
    }
    void printUtil(LLNode *head){
        if (head==NULL){
        cout << "NULL";
        return ;
        }
        if (head->next==NULL){
            cout << head->data;
            return ;
        }
        cout << head->data << " ";
        printUtil(head->next);
    }
    void print(){
        printUtil(head);
    }
}; 
int main(){
    LinkedList l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.insertOne();
    l1.print();
    cout <<endl;
    LinkedList l2;
    l2.push_back(8);
    l2.push_back(6);
    l2.push_back(9);
    l2.insertOne();
    l2.print();
    cout <<endl;
    LinkedList l3;
    l3.push_back(8);
    l3.push_back(9);
    l3.push_back(9);
    l3.insertOne();
    l3.print();
    cout << endl;
    LinkedList l4;
    l4.push_back(9);
    l4.push_back(9);
    l4.push_back(9);
    l4.insertOne();
    l4.print();
    return 0;
}