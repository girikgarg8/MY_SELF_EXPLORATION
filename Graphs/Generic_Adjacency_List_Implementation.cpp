#include <iostream>
#include <list>
#include <map>
using namespace std;
template <typename T>
class Graph{
     //I don't need to know number of entries because I don't have to create array
     map <T, list<T> > map1;
     public:
     Graph(){

     }
     void addEdge(T a,T b,bool isBiDirectional=true){
         map1[a].push_back(b);
         if (isBiDirectional){
             map1[b].push_back(a);
         }
     }
     void print(){
         for (auto j:map1){ //auto can be used with STL items , this one is for traversing the map
             cout << j.first << "->";
            for (auto i:j.second){
                cout << i << ",";
            } //this one is for traversing the LL
     cout <<endl;
     }
}
};
int main(){
    Graph <string>g1;
    g1.addEdge("Modi","Trump");
    g1.addEdge("Putin","Trump",false);
    g1.addEdge("Putin","Modi",false);
    g1.addEdge("Putin","Pope",false);
    g1.addEdge("Modi","Yogi");
    g1.addEdge("Prabhu","Modi",false);
    g1.addEdge("Yogi","Prabhu",false);
    g1.print();
    return 0;
}