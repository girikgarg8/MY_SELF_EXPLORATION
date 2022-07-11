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
    LinkedList(){
        head=NULL;
        tail=NULL;
    }
    void push_back(int val){
        LLNode *node=new LLNode(val);
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
LLNode * intersection(LLNode *head1,LLNode *head2){
    LLNode *temp1=head1;
    LLNode *temp2=head2;
    LinkedList ans;
    while (temp1!=NULL && temp2!=NULL){
    if (temp1->data==temp2->data){
        ans.push_back(temp1->data);
        temp1=temp1->next;
        temp2=temp2->next;
    }
    else if ((temp1->data)>(temp2->data)){
        temp2=temp2->next;
    }
    else if ((temp2->data)>(temp1->data)){
        temp1=temp1->next;
    }
    }
    return ans.head;
}
int main(){
    LinkedList l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(6);
    LinkedList l2;
    l2.push_back(2);
    l2.push_back(4);
    l2.push_back(6);
    l2.push_back(8);
    LLNode *n1=intersection(l1.head,l2.head);
    printUtil(n1);
    return 0;
}
