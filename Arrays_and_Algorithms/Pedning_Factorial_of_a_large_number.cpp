#include <iostream>
using namespace std;
class List{
    public:
    int data;
    List *prev;
    List(int data){
        this->data=data;
        this->prev=NULL;
    }
    ~List(){
        delete prev;
    }
};
int Factorial(int n){
    List *tail=new List(1);
    List *temp1=tail;
    List *previous=(temp1->prev);
    for (int i=2;i<=n;i++){
        temp1=tail;
        previous=temp1->prev;
        while (temp1!=NULL){
        temp1->data=(temp1->data)*i;
        if ((temp1->data)>9){
            int temp=(temp1->data)/10;
            while (temp1!=NULL && (temp1->data)>9){
            (temp1->data)=(temp1->data)%10;
            if ((previous)!=NULL){
                (previous->data)=(previous->data)+temp;
                temp1=previous;
            }
            else{
                previous=new List(temp);
                temp1=previous;
            }
        }
        }
        else{
        temp1=previous;
        }
}
}
}
int main(){
    
}
