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
    public:
    LLNode *head;
    LLNode *tail;
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
};
int findLength(LLNode *head){
    LLNode *temp=head;
    int length=0;
    while (temp!=NULL){
        length++;
        temp=temp->next;
    }
    return length;
}
LLNode * intersection(LLNode *head1,LLNode *head2){
    int a=findLength(head1);
    int b=findLength(head2);
    int diff=abs(a-b);
    LLNode *temp;
    if (a>=b && a!=0 && b!=0){
        temp=head1;
        int count=0;
        while (count!=diff){
            temp=temp->next;
            count++;
        }
        LLNode *temp1=head2;
        while (temp1!=NULL && temp!=NULL){
            if (temp==temp1){
                return temp;
            }
            temp=temp->next;
            temp1=temp1->next;
        }
    }
    if (b>a && a!=0 && b!=0){
        temp=head2;
        int count=0;
        while (count!=diff){
            temp=temp->next;
            count++;
        }
        LLNode *temp1=head1;
        while (temp1!=NULL && temp!=NULL){
            if (temp==temp1){
                return temp;
            }
            temp=temp->next;
            temp1=temp1->next;
        }
    }
    return NULL;
}
int main(){
    LinkedList l1;
    l1.push_back(3);
    l1.push_back(6);
    l1.push_back(9);
    l1.push_back(11);
    l1.push_back(13);
    LinkedList l2;
    l2.push_back(7);
    l2.push_back(11);
    l2.push_back(12);
    l2.push_back(9);
    l2.push_back(11);
    l2.push_back(13);
    LLNode *head1=l1.head;
    LLNode *head2=l2.head;
    LLNode *ans=intersection(head1,head2);
    if (ans!=NULL){
        cout << ans->data << " ";
    }
    else cout << "NULL";
    return 0;
}