#include <bits/stdc++.h>
using namespace std;
class LLNOde{
    public:
    int data;
    LLNOde *next;
    LLNOde(int val){
        data=val;
        next=NULL;
    }
};
LLNOde * findTail(LLNOde * head){
    if (head==NULL){
        return NULL;
    }
    LLNOde *temp=head;
    while (temp->next!=head){
        temp=temp->next;
    }
    return temp;
}
void splitCircularLL(LLNOde *head, LLNOde **head1, LLNOde **head2){
    LLNOde *slow=head;
    LLNOde *fast=head;
    while (fast!=NULL && fast->next!=NULL && fast->next!=head && fast->next->next!=head){
        slow=slow->next;
        fast=fast->next->next;
    }
    LLNOde *next=slow->next;
    slow->next=head;
    *head1=head;
    *head2=next;
}
int main(){
    LLNOde *head=new LLNOde(1);
    LLNOde *n1=new LLNOde(2);
    LLNOde *n2=new LLNOde(3);
    LLNOde *n3=new LLNOde(4);
    head->next=n1;
    n1->next=n2;
    n2->next=n3;
    n3->next=head;
    LLNOde *head1=NULL;
    LLNOde *head2=NULL;
    splitCircularLL(head,&head1,&head2);
    cout << head->data << endl;
    cout << head1->data <<endl;
    cout << head2->data <<endl;
    return 0;
}