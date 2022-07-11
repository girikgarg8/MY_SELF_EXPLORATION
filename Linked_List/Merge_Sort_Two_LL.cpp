#include <iostream>
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
class LinkedList{
    public:
    LLNode *head;
    LLNode *tail;
    LinkedList(){
        head=NULL;
        tail=NULL;
    }
    void push_back(int data){
    LLNode * node=new LLNode(data);
    if (head==NULL){
        head=node;
        tail=node;
    }
    else{
        tail->next=node;
        tail=node;
    }
    }
    LLNode * findMiddleNode(LLNode *head){
    LLNode *slow=head;
    LLNode *fast=head->next; // this is important, do not intialise to head take example of 20,1 here slow will keep on returning 1 if initialised to head
    while (slow!=NULL && fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
    }
    LLNode * Merge(LLNode *headRef,LLNode *ans1){
        LLNode *finalHead=NULL;
        LLNode *finalTail=NULL;
        LLNode *h1=headRef;
        LLNode *h2=ans1;
        while (h1!=NULL && h2!=NULL){
            if ((h1->data)>=(h2->data)){
                if (finalHead==NULL){
                    finalHead=h2;
                    finalTail=h2;
                }
                else {
                    finalTail->next=h2;
                    finalTail=h2;
                }
                h2=h2->next;
            }
           else if ((h1->data)<(h2->data)){
                if (finalHead==NULL){
                    finalHead=h1;
                    finalTail=h1;
                }
                else {
                    finalTail->next=h1;
                    finalTail=h1;
                }
                h1=h1->next;
        }   
    }
    if (h1!=NULL){
        finalTail->next=h1;
    }
    if (h2!=NULL){
        finalTail->next=h2;
    }
    return finalHead;
    }
    LLNode * MergeSort(LLNode *headRef){
        if (headRef==NULL){
            return headRef;
        }
        if (headRef->next==NULL){
            return headRef;
        }
        LLNode *ans=findMiddleNode(headRef);
        LLNode *ans1=ans->next;
        ans->next=NULL; //this is to make the sublist out of the given list
        LLNode *start=MergeSort(headRef);
        LLNode *center=MergeSort(ans1);
        LLNode *finalHead=Merge(start,center);
        return finalHead;
    }
    LLNode * MergeSort(){
        return MergeSort(head);
    }
};
void print(LLNode *head){
        if (head==NULL){
            cout << "NULL";
            return ;
        }
        if (head->next==NULL){
            cout << head->data << " ";
            return ;
        }
        cout << head->data << " ";
        print(head->next);
    }
int main(){
    LinkedList l1;
    l1.push_back(20);
    l1.push_back(1);
    l1.push_back(5);
    l1.push_back(30);
    l1.push_back(22);
    l1.push_back(3);
    l1.push_back(6);
    l1.push_back(2);
    l1.push_back(11);
    LLNode *node=l1.MergeSort();
    print(node);
    return 0;
}