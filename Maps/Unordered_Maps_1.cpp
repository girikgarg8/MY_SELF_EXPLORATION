#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main(){
    unordered_map <string,int> mymap;
    pair <string,int> p1("hello",192);
    mymap.insert(p1);
    mymap["hi"]=98;
    cout << mymap["hello"] <<endl;
    cout << mymap.at("hi") <<endl;
    // cout << mymap.at("xyz");
    cout << mymap["xyz"] <<endl;
    cout << mymap.count("xyz") <<endl;
    cout << mymap.count("yut") <<endl;
    cout << "Size is" << mymap.size() << endl;
    mymap.erase("hello");
    cout << "Count of hello now is " << mymap.count("hello");
    return 0;
}