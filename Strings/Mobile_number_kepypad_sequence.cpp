#include <iostream>
using namespace std;
void printSequence(string arr[],string input){
    int n=input.length();
    for (int i=0;i<n;i++){
        int index=input[i]-'A';
        if (input[i]==' '){
            cout << "0";
        }
        else{
        cout << arr[index];
        }
    }
}
int main(){
    string arr[]={"2","22","222","3","33","333","4","44","444","5","55","555",
    "6","66","666","7","77","777","7777","8","88","888","9","99","999","9999"};
    string pat="GEEKSFORGEEKS";
    string pat1="HELLO WORLD";
    printSequence(arr,pat);
    printSequence(arr,pat1);
    return 0;
}