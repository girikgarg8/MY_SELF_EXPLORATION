#include <bits/stdc++.h>
using namespace std;
class LLNode{
    public:
    int data;
    LLNode *next;
    public:
    LLNode(int value){
        data=value;
        next=NULL;
    }
};
class LinkedList{
    public:
    LLNode *head;
    LLNode *tail;
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
            tail=node;
        }
    }
    void checkAndRemoveLoop(){
        LLNode *slow=head;
        LLNode *fast=head;
        int flag=0;
        while (slow && fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if (slow==fast){
                flag=1;
                break;
            }
        }
        if (flag){
            if (slow==head){ //This is needed in the case like 1 2 3 4 5 and 5->next=1 i.e. a circularly linked list
                while (fast->next!=slow){
                    fast=fast->next;
                }
                fast->next=NULL;
            }
            else{
            slow=head;
            while (slow->next!=fast->next){
                slow=slow->next;
                fast=fast->next;
            }
            fast->next=NULL;
        }
    }
    }
    void printUtil(LLNode *head){
        if (head==NULL){
            cout << "NULL";
            return ;
        }
        if (head->next==NULL){
            cout << head->data << " ";
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
    LLNode *n1=new LLNode(1);
    LLNode *n2=new LLNode (2);
    LLNode *n3=new LLNode (3);
    LLNode *n4=new LLNode (4);
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n1;
    LinkedList l1;
    l1.head=n1;
    l1.checkAndRemoveLoop();
    l1.print();
    LLNode *n5=new LLNode(10);
    LLNode *n6=new LLNode(20);
    LLNode *n7=new LLNode(30);
    LLNode *n8=new LLNode(40);
    n5->next=n6;
    n6->next=n7;
    n7->next=n8;
    n8->next=n6;
    LinkedList l2;
    l2.head=n5;
    cout <<endl;
    l2.checkAndRemoveLoop();
    l2.print();
    return 0;
}