#include <iostream>
#include <queue>
using namespace std;
int RemoveKCharacters(string s,int k){
    int l=s.length();
    if (k>=l){
        return 0;
    }
    vector <int> arr (26,0);
    for (int i=0;i<l;i++){
        arr[s[i]-'a']++;
    }
    priority_queue <int> pq;
    for (int i=0;i<26;i++){
        pq.push(arr[i]);
    }
    while (k!=0){
        int a=pq.top();
        a=a-1;
        pq.pop();
        pq.push(a);
        k--;
    }
    int result=0;
    while (!pq.empty()){
        int temp=pq.top();
        result+=temp*temp;
        pq.pop();
    }
    return result;
}
int main(){
    string str = "abbccc"; // Input 1
    int k = 2;
    cout << RemoveKCharacters(str, k) << endl;

    str = "aaab"; // Input 2
    k = 2;
    cout << RemoveKCharacters(str, k);
    return 0;
}

