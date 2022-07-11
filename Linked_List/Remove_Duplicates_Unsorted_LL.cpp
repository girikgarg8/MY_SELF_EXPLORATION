#include <bits/stdc++.h>
using namespace std;
class LLNode{
    public:
    int data;
    LLNode *next;
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
    void push_back(int value){
        LLNode * node=new LLNode(value);
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
        unordered_map <int,int> mp;
        if (head==NULL){
            return NULL;
        }
        LLNode *curr=head;
        LLNode *nxt=curr->next;
        LLNode *prev=NULL;
        while (curr!=NULL){
            if (mp.find(curr->data)!=mp.end()){
                prev->next=nxt;
                delete curr;
                curr=nxt;
                if (nxt!=NULL){
                nxt=nxt->next;
                }
            }
            else{
                mp[curr->data]+=1;
                prev=curr;
                curr=nxt;
                if (nxt!=NULL){
                nxt=nxt->next;
                }
            }
        }
        return head;
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
    void removeDuplicates(){
        this->head=removeDuplicatesUtil(head);
    }
    void print(){
        printUtil(head);
    }
};
int main(){
    LinkedList l1;
    l1.push_back(5);
    l1.push_back(2);
    l1.push_back(2);
    l1.push_back(4);
    l1.removeDuplicates();
    l1.print();
    return 0;
}