#include <iostream>
#include <stack>
using namespace std;
void NextSmallerElement(int arr[],int n){
    stack <int> s1;
    s1.push(0);
    for (int i=1;i<n;i++){
        while (!s1.empty() && arr[i]<arr[s1.top()]){
            cout << arr[s1.top()] << " ->" << arr[i] <<endl;
            s1.pop();
        }
        s1.push(i);
    }
    while (!s1.empty()){
        cout << arr[s1.top()] << " ->" << "-1" <<endl;
        s1.pop();
    }
}
int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    NextSmallerElement(arr,n);
    return 0;
}