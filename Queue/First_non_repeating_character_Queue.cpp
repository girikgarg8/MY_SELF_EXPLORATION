#include <iostream>
#include <queue>
using namespace std;
const int MAX_CHAR=26;
void firstNonRepeating(char str[]){
    queue<char>q;
    int charCount[MAX_CHAR]={0};
    for (int i=0;str[i]!='\0';i++){
        q.push(str[i]);
        charCount[str[i]-'a']++;
        while (!q.empty()){
            if (charCount[q.front()-'a']>1){
                q.pop();
            }
            else{
                cout << q.front() << " ";
                break;
            }
        }
        if (q.empty()){
            cout << -1 << " ";
        }
        cout <<endl;
    }
}
int main(){
    char str[100]="aabc";
    firstNonRepeating(str);
    return 0;
}