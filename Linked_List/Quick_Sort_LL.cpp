#include <bits/stdc++.h> //Code as given on Coding Ninjas Codestudio
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
LLNode *partition(LLNode * head,LLNode *tail,LLNode **newHead,LLNode **newTail){
    //newHead and newTail are passed by reference, hence ** newHead has been passed into this function
    LLNode *pivot=tail;
    LLNode *temp=head;
    LLNode *prev=NULL;
    while (temp!=pivot){
        if ((temp->data)<=(pivot->data)){
            if (*newHead==NULL){
                *newHead=temp;
            }
            prev=temp;
            temp=temp->next;
        }
        else if ((temp->data)>(pivot->data)){
            //There could be two cases here : either temp is the head node (in that case I don't need to delete any node) or temp is not a head node
            //I first need to delete temp node from it's current position, and then put it at the end (tail)
            if (prev!=NULL){ //not newHead!=NULL
                prev->next=temp->next;
            }
            LLNode *temp1=temp->next;
            temp->next=NULL;
            tail->next=temp;
            tail=temp;
            temp=temp1;
        }
    }
    //Edge case
    if (*newHead==NULL){
        *newHead=pivot;
    }
    *newTail=tail;
    return pivot;
}
LLNode * getTail(LLNode *head){
    LLNode *temp=head;
    while (temp->next!=NULL){
        temp=temp->next;
    }
    return temp;
}
LLNode *QuickSort(LLNode *head,LLNode *tail){ //this is actually the helper function
    if (head!=NULL || head==tail){
        return head;
    } //Base Case
    LLNode *newHead=NULL;
    LLNode *newTail=NULL;
    LLNode *pivot=partition(head,tail,&newHead,&newTail);
    //There are two cases here
    if (newHead!=pivot){
        LLNode *temp=newHead;
        while (temp->next!=pivot){
            temp=temp->next;
        }
        temp->next=NULL;
        newHead=QuickSort(newHead,temp);
        LLNode *tail;
        tail=getTail(newHead);
        temp->next=pivot;
    }
    pivot->next=QuickSort(pivot->next,newTail);
    return newHead;
}
LLNode *quickSortLL(LLNode *head)
{
    LLNode *tail = getTail(head);
    head = QuickSort(head, tail);
    return head;
}