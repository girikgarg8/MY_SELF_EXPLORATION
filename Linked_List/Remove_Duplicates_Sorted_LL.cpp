#include <bits/stdc++.h>
using namespace std;
class LLNode{
    public:
    int data;
    LLNode *next;
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
    private:
    LLNode * removeDuplicatesUtil(LLNode *head){
        if (head==NULL){
            return NULL;
        }
        //Base Case
        if (head->next!=NULL){
            LLNode *temp=head->next->next;
            if (head->data==head->next->data){
                delete head->next;
                head->next=temp;
            }
        } //Small calculation part
        removeDuplicatesUtil(head->next);//recursive call;
        return head;
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
    public:
    void removeDuplicates(){
        this->head=removeDuplicatesUtil(head);
    }
    void print(){
        printUtil(head);
    }
};
int main(){
    LinkedList l1;
    // 11->11->11->21->43->43->60
    l1.push_back(11);
    l1.push_back(11);
    l1.push_back(21);
    l1.push_back(43);
    l1.push_back(43);
    l1.push_back(60);
    l1.removeDuplicates();
    l1.print();
    return 0;
}