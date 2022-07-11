#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main(){
    unordered_map <string,int> mymap;
    mymap["abc"]=102;
    mymap["xyz"]=989;
    mymap["qrs"]=978;
    unordered_map <string,int>::iterator it;
    for (it=mymap.begin();it!=mymap.end();it++){
        cout << (it->second) <<endl;
    }
    unordered_map <string,int>::iterator it1= mymap.find("abc");
    for (;it1!=mymap.end();it1++){
        cout << (it1->second) <<endl;
    }
    it1=mymap.find("abc");
    mymap.erase(it1,mymap.end());
    cout << "Size of map now is" << mymap.size() <<endl;
    return 0;
}