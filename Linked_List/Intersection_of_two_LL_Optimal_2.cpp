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
LLNode * intersection(LLNode *head1,LLNode *head2){
    if (head1==NULL || head2==NULL){
        return NULL;
    }
    LLNode *temp1=head1;
    LLNode *temp2=head2;
    int flag1=0;
    int flag2=0;
    while (temp1!=NULL || flag1==0 || flag2==0){
        if (temp1==NULL && flag1==0){
            temp1=head2;
            flag1=1;
        }
        if (temp2==NULL && flag2==0){
            temp2=head1;
            flag2=1;
        }
        if (temp1==temp2){
            return temp1;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return NULL;
}
int main(){
    LLNode *head1=new LLNode (3);
    LLNode *n1=new LLNode (6);
    LLNode *n2=new LLNode (9);
    LLNode *n3=new LLNode (11);
    LLNode *n4=new LLNode(15);
    LLNode *n5=new LLNode (7);
    LLNode *n6=new LLNode (13);
    LLNode *n7=new LLNode (11);
    LLNode *n8=new LLNode (12);
    head1->next=n1;
    head1->next->next=n2;
    head1->next->next->next=n3;
    head1->next->next->next->next=n6;
    head1->next->next->next->next->next=n4;
    LLNode *head2=n5;
    n5->next=n7;
    n5->next->next=n8;
    n5->next->next->next=n2;
    n5->next->next->next->next=n3;
    n5->next->next->next->next->next=n6;
    n5->next->next->next->next->next->next=n4;
    LLNode *ans=intersection(head1,head2);
    if (ans!=NULL){
        cout << ans->data;
    }
    else cout << "NULL";
    return 0;
    }

    /*
    Alternative better code on GFG:
      while (ptr1 != ptr2) {
 
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
 
        // If at any node ptr1 meets ptr2, then it is
        // intersection node.Return intersection node.
 
        if (ptr1 == ptr2) {
 
            return ptr1;
        }
        Once both of them go through reassigning,
        they will be equidistant from the collision point.
 
        // When ptr1 reaches the end of a list, then
        // reassign it to the head2.
        if (ptr1 == NULL) {
 
            ptr1 = head2;
        }
        // When ptr2 reaches the end of a list, then
        // redirect it to the head1.
        if (ptr2 == NULL) {
 
            ptr2 = head1;
        }
    }
 
    return ptr1;
    */