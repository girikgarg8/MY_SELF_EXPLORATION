#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class TreeNode{
    public:
    T data;
    vector <TreeNode *> childArray;
    TreeNode (T data){
        this->data=data;
    }
};

int main(){
    TreeNode <int> *t1= new TreeNode <int> (1);
    TreeNode <int> *t2= new TreeNode <int> (2);
    TreeNode <int> *t3= new TreeNode <int> (3);
    t1->childArray.push_back(t2);
    t2->childArray.push_back(t3);
    return 0;
}
