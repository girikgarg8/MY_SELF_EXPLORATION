#include <bits/stdc++.h>
using namespace std;
class LLNode{
    public:
    int data;
    LLNode *next;
    LLNode(int val){
        data=val;
        next=NULL;
    }
};
bool checkForCircularLL(LLNode *head){
    if (head==NULL){
        return true;
    }
    LLNode *temp=head->next;
    while (temp!=NULL){
        if (temp==head){
            return true;
        }
        else temp=temp->next;
    }
    return false;
}
int main(){
    LLNode *head=new LLNode(10);
    LLNode *n1=new LLNode(20);
    LLNode *n2=new LLNode(30);
    LLNode *n3=new LLNode(40);
    head->next=n1;
    n1->next=n2;
    n2->next=n3;
    n3->next=head;
    (checkForCircularLL(head)==1)?cout << "Cyclic Linked List" : cout << "Not cyclic linked list";
    LLNode *head1=new LLNode(15);
    head1->next=n1;
    n1->next=n2;
    LLNode *n4=new LLNode(40);
    n2->next=n4;
    cout <<endl;
    (checkForCircularLL(head1)==1)?cout << "Cyclic Linked List" : cout << "Not cyclic linked list";
    return 0;
}