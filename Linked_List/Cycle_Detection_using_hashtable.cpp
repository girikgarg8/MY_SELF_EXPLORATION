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
    unordered_map <LLNode *,int> mp;
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
    bool cycleDetection(){
        LLNode *temp=head;
        while (temp!=NULL){
            if (mp.find(temp)!=mp.end()){
                return true;
            }
            else{
                mp[temp]++;
            }
            temp=temp->next;
        }
        return false;
    }
};
int main(){
    LLNode *n1=new LLNode(1);
    LLNode *n2=new LLNode (2);
    LLNode *n3=new LLNode (3);
    LLNode *n4=new LLNode (4);
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n1;
    LinkedList l1;
    l1.head=n1;
    LinkedList l2;
    l2.push_back(10);
    l2.push_back(20);
    l2.push_back(30);
    l2.push_back(40);
    (l1.cycleDetection()==1)?cout << "Cycle is present" : cout << "Cycle is not present";
    cout <<endl;
    (l2.cycleDetection()==1)?cout << "Cycle is present" : cout << "Cycle is not present";
    return 0;
}