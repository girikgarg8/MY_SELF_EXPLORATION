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
    LLNode *head;
    LLNode *tail;
    public:
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
    LLNode * reverse(LLNode *head,int k){
        if (head==NULL){ //Base case
            return NULL;
        }
        LLNode *current=head;
        LLNode *nxt=NULL; //Initialised with NULL
        LLNode *prev=NULL; //Initialised with NULL
        int count=0;
        //reverse first k nodes of the linked list : small calculation part
        while (current!=NULL && count<k){ //current!=NULL is required in case I reach the end of sub-list eg. 1 2 and k=3
            nxt=current->next;
            current->next=prev;
            prev=current;
            current=nxt;
            count++;
        }
        //After this step, I have reversed the first sub-list 
        //At this point, nxt points to the (k+1)th node, I need to call recursion and make head->next=node returned by recursion
        if (nxt!=NULL){
            head->next=reverse(nxt,k); //Recursive call
        }
        return prev;
    }
    LLNode * reverse(int k){
        return reverse(head,k);
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
    public:
    void print(){
        printUtil(head);
    }
};
int main(){
        LinkedList l1;
        l1.push_back(1);
        l1.push_back(2);
        l1.push_back(2);
        l1.push_back(4);
        l1.push_back(5);
        l1.push_back(6);
        l1.push_back(7);
        l1.push_back(8);
        l1.print();
        int k=3;
        LLNode *newHead=l1.reverse(3);
        cout <<endl;
        l1.printUtil(newHead);
        return 0;
}
