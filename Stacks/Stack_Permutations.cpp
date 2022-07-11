#include <iostream>
#include <stack>
#include <queue>
using namespace std;
bool checkStackPermutation(int ip[],int op[],int n){
    queue<int> input;
    for (int i=0;i<n;i++){
        input.push(ip[i]);
    }
    queue <int> output;
    for (int i=0;i<n;i++){
        output.push(op[i]);
    }
    stack <int> s;
    while (!input.empty()){
        int ele=input.front();
        input.pop();
        if (ele==output.front()){
            output.pop();
        while (!s.empty()){
            if (s.top()==output.front()){
                s.pop();
                output.pop();
            }
            else break;
        }
        }
        else s.push(ele);
    }
    return input.empty() && s.empty();
}
int main()
{
    // Input Queue
    int input[] = {1, 2, 3};
 
    // Output Queue
    int output[] = {2, 1, 3};
 
    int n = 3;
 
    if (checkStackPermutation(input, output, n))
        cout << "Yes";
    else
        cout << "Not Possible";
    return 0;
}